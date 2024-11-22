#include "mainpage.h"
#include "ui_mainpage.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QComboBox>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QFileDialog>
#include <QHttpMultiPart>
#include <QNetworkRequest>
#include <QFile>
#include <QDate>
#include <QProcess>

MainPage::MainPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainPage)
{
    ui->setupUi(this);
    QNetworkAccessManager *manager;
    qDebug() << QSqlDatabase::drivers();
    manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished,
            this, &MainPage::replyFinished);
    connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainPage::chargerImageEmployeSelectionne);
    loadUserData();
    loadbox();
    networkManager = new QNetworkAccessManager(this);

}

MainPage::~MainPage()
{
    delete ui;
}

void MainPage::on_ajouter_clicked()
{
    imagePath = QFileDialog::getOpenFileName(
        this,
        tr("Ouvrir"),
        "",
        tr("Images (*.png *.jpg *.jpeg)")
        );
    QPixmap pixmap(imagePath);
    if (!pixmap.isNull()) {
        QFileInfo fileInfo(imagePath);
        fileName = fileInfo.fileName();
        qDebug() << "Image chargée avec succès";
        QSize labelSize = ui->imageLabel_2->size();
        QPixmap scaledPixmap = pixmap.scaled(labelSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        ui->imageLabel_2->setPixmap(scaledPixmap);
        ui->imageLabel_2->setScaledContents(true);
    } else {
        // Affichez un message d'erreur si le chargement de l'image a échoué
        qDebug() << "Impossible de charger l'image depuis le chemin :" << imagePath;
    }
}

void MainPage::on_buttonBox_accepted()
{
    QString nom = ui->txt_nom->text();
    QString prenom = ui->txt_prenom->text();
    QDate date_de_naissance = ui->date_de_naissance->date();
    QStringList champsManquants;
    QString serverUrl = "http://172.16.112.234/photos/";
    if (upload(serverUrl, imagePath)) {
        qDebug() << "Votre application a la permission d'écrire dans le répertoire du serveur.";
    } else {
        qDebug() << "Votre application n'a pas la permission d'écrire dans le répertoire du serveur.";
    }

    if (nom.isEmpty()) {
        champsManquants << "Nom";
    }
    if (prenom.isEmpty()) {
        champsManquants << "Prénom";
    }
    if (!date_de_naissance.isValid()) {
        champsManquants << "Date de naissance";
    }

    if (champsManquants.isEmpty()) {
        // Condition si tous les champs sont ok on continue
        QSqlDatabase db = QSqlDatabase::database();
        QString date_de_naissance_str = date_de_naissance.toString("yyyy-MM-dd");

        if (db.isOpen()) {
            // requête sql
            QSqlQuery query;
            query.prepare("INSERT INTO employe (nom, prenom, date_de_naissance, badge) VALUES (:nom, :prenom, :date_de_naissance, :badge)");
            query.bindValue(":nom", nom);
            query.bindValue(":prenom", prenom);
            query.bindValue(":date_de_naissance", date_de_naissance_str);
            query.bindValue(":badge", badgeID);
            // Exécutez la requête
            if (query.exec()) {
                qDebug() << "Enregistrement ajouté avec succès à la base de données.";
                // message de succès
                QMessageBox::information(this, "Succès", "Enregistrement ajouté avec succès à la base de données.");
                int idEmploye = query.lastInsertId().toInt();
                qDebug() << "ID de l'employé ajouté : " << idEmploye;
                QString lien = serverUrl + fileName;
                QPixmap pixmap(imagePath);
                if (!pixmap.isNull()){
                    QSqlQuery upload;
                    upload.prepare("INSERT INTO photosemployes (id_employe, lien_photo) VALUES (:idEmploye, :lien_photo)");
                    upload.bindValue(":idEmploye", idEmploye);
                    upload.bindValue(":lien_photo", lien);
                    if (!upload.exec()) {
                        qDebug() << "Erreur: " << upload.lastError().text().toStdString();
                    } else {
                        qDebug() << "Ajouté avec succès";
                    }
                }
                if(ui->checkBox->isChecked()){
                    QSqlQuery querycheck;
                    querycheck.prepare("INSERT INTO employe_niveau_acces (id_employe, id_niveau_acces) VALUES (:idEmploye, 1)");
                    querycheck.bindValue(":idEmploye", idEmploye);
                    QMessageBox::information(this, "Succès", "L'employé a bien reçu l'accès 1");
                    if (!querycheck.exec()) {
                        qDebug() << "Erreur lors de l'insertion du niveau d'accès 1 :" << querycheck.lastError().text();
                    }
                }
                if(ui->checkBox_2->isChecked()){
                    QSqlQuery querycheck;
                    querycheck.prepare("INSERT INTO employe_niveau_acces (id_employe, id_niveau_acces) VALUES (:idEmploye, 2)");
                    querycheck.bindValue(":idEmploye", idEmploye);
                    QMessageBox::information(this, "Succès", "L'employé a bien reçu l'accès 2");
                    if (!querycheck.exec()) {
                        qDebug() << "Erreur lors de l'insertion du niveau d'accès 2 :" << querycheck.lastError().text();
                    }
                }
                if(ui->checkBox_3->isChecked()){
                    QSqlQuery querycheck;
                    querycheck.prepare("INSERT INTO employe_niveau_acces (id_employe, id_niveau_acces) VALUES (:idEmploye, 3)");
                    querycheck.bindValue(":idEmploye", idEmploye);
                    QMessageBox::information(this, "Succès", "L'employé a bien reçu l'accès 3");
                    if (!querycheck.exec()) {
                        qDebug() << "Erreur lors de l'insertion du niveau d'accès 3 :" << querycheck.lastError().text();
                    }
                }
                loadUserData();
                loadbox();
            } else {
                qDebug() << "Erreur lors de l'ajout de l'enregistrement à la base de données:" << query.lastError().text();
                // message d'erreur
                QMessageBox::critical(this, "Erreur", "Erreur lors de l'ajout de l'enregistrement à la base de données:\n" + query.lastError().text());
            }
        } else {
            qDebug() << "Erreur: La connexion à la base de données n'est pas ouverte.";
            // message erreur connexion bdd
            QMessageBox::critical(this, "Erreur", "La connexion à la base de données n'est pas ouverte.");
        }
    } else {
        // message d'erreur détaillé
        QString message = "Les champs suivants sont manquants :";
        foreach (const QString &champ, champsManquants) {
            message += "\n- " + champ;
        }
        qDebug() << message;
        QMessageBox::warning(this, "Erreur", message);
    }
    ui->checkBox->setChecked(false);
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);
    ui->txt_nom->clear();
    ui->txt_prenom->clear();
    QDate dateSpecifique(2000, 1, 1);
    ui->date_de_naissance->setDate(dateSpecifique);
    ui->imageLabel_2->clear();
}

void MainPage::loadUserData()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QString query = "SELECT employe.id, employe.nom, employe.prenom, employe.date_de_naissance, employe_niveau_acces.id_niveau_acces, employe.badge"
                    " FROM employe"
                    " INNER JOIN employe_niveau_acces ON employe.id = employe_niveau_acces.id_employe"
                    " ORDER BY employe.id";

    // Exécuter la requête SQL
    model->setQuery(query);

    // Définir les en-têtes du modèle
    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "Nom");
    model->setHeaderData(2, Qt::Horizontal, "Prénom");
    model->setHeaderData(3, Qt::Horizontal, "Date de naissance");
    model->setHeaderData(4, Qt::Horizontal, "ID Niveau d'accès");
    model->setHeaderData(5, Qt::Horizontal, "Badge");

    // Afficher le modèle dans la vue
    ui->user_list->setModel(model);
}

void MainPage::loadbox()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT id FROM employe");
    ui->comboBox->setModel(model);
}
void MainPage::replyFinished(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray data = reply->readAll();
        QPixmap pixmap;
        pixmap.loadFromData(data);
        QSize labelSize = ui->imageLabel->size();
        QPixmap scaledPixmap = pixmap.scaled(labelSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        ui->imageLabel->setPixmap(scaledPixmap);
        ui->imageLabel->setScaledContents(true);
    } else {
        // Afficher un message d'erreur en cas de problème lors du chargement de l'image
        QMessageBox::warning(this, "Erreur", "Impossible de charger l'image : " + reply->errorString());
    }

    // Nettoyer la réponse
    reply->deleteLater();
}

void MainPage::chargerImageEmployeSelectionne()
{
    ui->imageLabel->clear();
    ui->checkBox_4->setChecked(false);
    ui->checkBox_5->setChecked(false);
    ui->checkBox_6->setChecked(false);
    ui->txt_nom_2->clear();
    ui->txt_prenom_2->clear();
    QDate dateSpecifique(2000, 1, 1);
    ui->date_de_naissance_2->setDate(dateSpecifique);
    QString idEmployeSelectionne = ui->comboBox->currentText();
    QSqlQuery query;
    qDebug() << "ID de l'employé sélectionné : " << idEmployeSelectionne; // Message pour afficher l'ID sélectionné
    query.prepare("SELECT lien_photo FROM PhotosEmployes WHERE id_employe = ?");
    query.bindValue(0, idEmployeSelectionne);

    if(query.exec() && query.first()) {
        QString imageUrl = query.value(0).toString();
        qDebug() << "URL de l'image de l'employé : " << imageUrl; // Message pour afficher l'URL de l'image récupérée

        QNetworkAccessManager *manager = new QNetworkAccessManager(this);
        connect(manager, &QNetworkAccessManager::finished, this, &MainPage::replyFinished);
        manager->get(QNetworkRequest(QUrl(imageUrl)));

    } else {
        QMessageBox::warning(this, "Erreur", "Impossible de récupérer les images des l'employés");
    }
    QSqlQueryModel *model = new QSqlQueryModel();
    QString queryString  = "SELECT employe.id, employe.nom, employe.prenom, employe.date_de_naissance, employe_niveau_acces.id_niveau_acces, employe.badge"
                          " FROM employe"
                          " INNER JOIN employe_niveau_acces ON employe.id = employe_niveau_acces.id_employe"
                          " WHERE employe.id = '" + idEmployeSelectionne  + "'";
    model->setQuery(queryString);
    // Définir les en-têtes du modèle
    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "Nom");
    model->setHeaderData(2, Qt::Horizontal, "Prénom");
    model->setHeaderData(3, Qt::Horizontal, "Date de naissance");
    model->setHeaderData(4, Qt::Horizontal, "ID Niveau d'accès");
    model->setHeaderData(5, Qt::Horizontal, "Badge");

    // Afficher le modèle dans la vue
    ui->user_list_2->setModel(model);
}

void MainPage::on_load_button_clicked() // bouton reload pour la page modification
{
    loadUserData();
    loadbox();
}
void MainPage::chargerInfosEmployePourModification()
{
    ui->checkBox_4->setChecked(false);
    ui->checkBox_5->setChecked(false);
    ui->checkBox_6->setChecked(false);
    QString idEmployeSelectionne = ui->comboBox->currentText();
    qDebug() << "ID de l'employé sélectionné pour la modification : " << idEmployeSelectionne;

    QSqlQueryModel model;
    QString queryString = "SELECT employe.id, employe.nom, employe.prenom, employe.date_de_naissance, employe_niveau_acces.id_niveau_acces"
                          " FROM employe"
                          " INNER JOIN employe_niveau_acces ON employe.id = employe_niveau_acces.id_employe"
                          " WHERE employe.id = '" + idEmployeSelectionne + "'";
    model.setQuery(queryString);

    // Vérifier si des données sont disponibles
    if (model.rowCount() > 0) {
        // Récupérer les informations de la première ligne (seule ligne)
        QString nom = model.record(0).value("nom").toString();
        QString prenom = model.record(0).value("prenom").toString();
        QDate dateNaissance = model.record(0).value("date_de_naissance").toDate();
        int idAcces = model.record(0).value("id_niveau_acces").toInt();

        // Remplir les champs avec les informations récupérées
        ui->txt_nom_2->setText(nom);
        ui->txt_prenom_2->setText(prenom);
        ui->date_de_naissance_2->setDate(dateNaissance);
        if (idAcces == 1) {
            ui->checkBox_4->setChecked(true);
        } else if (idAcces == 2) {
            ui->checkBox_5->setChecked(true);
        } else if (idAcces == 3) {
            ui->checkBox_6->setChecked(true);
        }
        qDebug() << "Informations de l'employé récupérées pour la modification : " << nom << prenom << dateNaissance << idAcces;
    } else {
        qDebug() << "Aucune information trouvée pour l'employé sélectionné";
    }
}

void MainPage::on_pushButton_clicked()
{
    chargerInfosEmployePourModification();
}
void MainPage::modifierInfosEmploye()
{
    QString idEmployeSelectionne = ui->comboBox->currentText();
    QString nouveauNom = ui->txt_nom_2->text();
    QString nouveauPrenom = ui->txt_prenom_2->text();
    QDate nouvelleDateNaissance = ui->date_de_naissance_2->date();
    QSqlQuery query;

    // Vérifier les droits d'accès sélectionnés et mettre à jour l'ID d'accès en conséquence
    if(ui->checkBox_4->isChecked()){
        QSqlQuery querycheck;
        querycheck.prepare("UPDATE employe_niveau_acces SET id_niveau_acces = 1 WHERE id_employe = ?");
        querycheck.bindValue(0, idEmployeSelectionne); // Utiliser bindValue avec l'index 0
        QMessageBox::information(this, "Succès", "L'employé a bien reçu l'accès 1");
        if (!querycheck.exec()) {
            qDebug() << "Erreur lors de la mise à jour du niveau d'accès 1 :" << querycheck.lastError().text();
        }
    }
    if(ui->checkBox_5->isChecked()){
        QSqlQuery querycheck;
        querycheck.prepare("UPDATE employe_niveau_acces SET id_niveau_acces = 2 WHERE id_employe = ?");
        querycheck.bindValue(0, idEmployeSelectionne); // Utiliser bindValue avec l'index 0
        QMessageBox::information(this, "Succès", "L'employé a bien reçu l'accès 2");
        if (!querycheck.exec()) {
            qDebug() << "Erreur lors de la mise à jour du niveau d'accès 2 :" << querycheck.lastError().text();
        }
    }
    if(ui->checkBox_6->isChecked()){
        QSqlQuery querycheck;
        querycheck.prepare("UPDATE employe_niveau_acces SET id_niveau_acces = 3 WHERE id_employe = ?");
        querycheck.bindValue(0, idEmployeSelectionne); // Utiliser bindValue avec l'index 0
        QMessageBox::information(this, "Succès", "L'employé a bien reçu l'accès 3");
        if (!querycheck.exec()) {
            qDebug() << "Erreur lors de la mise à jour du niveau d'accès 3 :" << querycheck.lastError().text();
        }
    }

    // Préparer la requête SQL de mise à jour
    query.prepare("UPDATE employe SET nom = ?, prenom = ?, date_de_naissance = ? WHERE id = ?");
    query.bindValue(0, nouveauNom);
    query.bindValue(1, nouveauPrenom);
    query.bindValue(2, nouvelleDateNaissance);
    query.bindValue(3, idEmployeSelectionne.toInt()); // Convertir l'ID en entier

    // Exécuter la requête de mise à jour
    if (query.exec()) {
        qDebug() << "Les informations de l'employé ont été mises à jour avec succès.";
        QMessageBox::information(this, "Succès", "Les informations de l'employé ont été mises à jour avec succès.");
    } else {
        qDebug() << "Erreur lors de la mise à jour des informations de l'employé :" << query.lastError().text();
        QMessageBox::critical(this, "Erreur", "Erreur lors de la mise à jour des informations de l'employé : " + query.lastError().text());
    }
}


void MainPage::on_buttonBox_2_accepted()
{
    modifierInfosEmploye();
    loadUserData();
    loadbox();
}

void MainPage::supprimerUtilisateur() {
    QString idEmployeSelectionne = ui->comboBox->currentText();
    QSqlQuery queryDelete1, queryDelete2;

    queryDelete1.prepare("DELETE FROM employe_niveau_acces WHERE id_employe = ?");
    queryDelete1.bindValue(0, idEmployeSelectionne.toInt());
    if (!queryDelete1.exec()) {
        qDebug() << "Erreur lors de la suppression des données associées dans employe_niveau_acces :" << queryDelete1.lastError().text();
        QMessageBox::critical(this, "Erreur", "Erreur lors de la suppression des données associées dans employe_niveau_acces : " + queryDelete1.lastError().text());
        return; // Sortie de la fonction en cas d'erreur
    }
    QSqlQuery querySelectImage;
    querySelectImage.prepare("SELECT lien_photo FROM photosemployes WHERE id_employe = ?");
    querySelectImage.bindValue(0, idEmployeSelectionne.toInt());
    if (!querySelectImage.exec()) {
        qDebug() << "Erreur lors de la récupération de l'URL de l'image :" << querySelectImage.lastError().text();
        QMessageBox::critical(this, "Erreur", "Erreur lors de la récupération de l'URL de l'image : " + querySelectImage.lastError().text());
        return; // Sortie de la fonction en cas d'erreur
    }
    if (querySelectImage.next()) {
        QString imageUrl = querySelectImage.value(0).toString();
        if (deleteImage("http://172.16.112.234/photos/", imageUrl)) {
            qDebug() << "L'image a été supprimée avec succès.";
        } else {
            qDebug() << "La suppression de l'image a échoué.";
        }
    } else {
        qDebug() << "Aucune image n'a été trouvée pour l'ID de l'employé :" << idEmployeSelectionne;
    }
    queryDelete2.prepare("DELETE FROM photosemployes WHERE id_employe = ?");
    queryDelete2.bindValue(0, idEmployeSelectionne.toInt());
    if (!queryDelete2.exec()) {
        qDebug() << "Erreur lors de la suppression des données associées dans niveau_acces :" << queryDelete2.lastError().text();
        QMessageBox::critical(this, "Erreur", "Erreur lors de la suppression des données associées dans niveau_acces : " + queryDelete2.lastError().text());
        return; // Sortie de la fonction en cas d'erreur
    }

    QSqlQuery queryDeleteEmploye;
    queryDeleteEmploye.prepare("DELETE FROM employe WHERE id = ?");
    queryDeleteEmploye.bindValue(0, idEmployeSelectionne.toInt());
    if (queryDeleteEmploye.exec()) {
        qDebug() << "L'utilisateur a été supprimé avec succès.";
        QMessageBox::information(this, "Succès", "L'utilisateur a été supprimé avec succès.");
    } else {
        qDebug() << "Erreur lors de la suppression de l'utilisateur :" << queryDeleteEmploye.lastError().text();
        QMessageBox::critical(this, "Erreur", "Erreur lors de la suppression de l'utilisateur : " + queryDeleteEmploye.lastError().text());
    }
}

void MainPage::on_btn_supprimer_clicked()
{
    connect(ui->btn_supprimer, &QPushButton::clicked, this, &MainPage::supprimerUtilisateur);
    supprimerUtilisateur();
    loadUserData();
    loadbox();
}


bool MainPage::upload(const QString& serverUrl, const QString& imagePath) {
    QFile file(imagePath);
    if (!file.exists()) {
        qDebug() << "L'image spécifiée n'existe pas.";
        return false;
    }

    if (file.open(QIODevice::ReadOnly)) {
        QByteArray imageData = file.readAll();

        QNetworkRequest request(serverUrl);
        QHttpMultiPart multiPart(QHttpMultiPart::FormDataType);

        QHttpPart imagePart;
        imagePart.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("multipart/form-data"));
        imagePart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"image\"; filename=\"" + QFileInfo(imagePath).fileName() + "\""));
        imagePart.setBody(imageData);
        multiPart.append(imagePart);

        QNetworkAccessManager manager;
        QNetworkReply* reply = manager.post(request, &multiPart);
        QEventLoop loop;
        QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
        loop.exec();

        if (reply->error() == QNetworkReply::NoError) {
            qDebug() << "Réponse du serveur Apache : " << reply->readAll();
            reply->deleteLater();
            return true;
        } else {
            qDebug() << "Erreur lors de l'envoi du fichier :" << reply->errorString();
            reply->deleteLater();
            return false;
        }
    } else {
        qDebug() << "Impossible de lire l'image spécifiée.";
        return false;
    }
}
bool MainPage::deleteImage(const QString& serverUrl, const QString& imageUrl) {
    QNetworkRequest request(serverUrl);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QByteArray postData;
    postData.append("delete=").append(imageUrl.toUtf8());

    QNetworkAccessManager manager;
    QNetworkReply* reply = manager.post(request, postData);
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    if (reply->error() == QNetworkReply::NoError) {
        qDebug() << "Réponse du serveur Apache : " << reply->readAll();
        reply->deleteLater();
        return true;
    } else {
        qDebug() << "Erreur lors de la suppression de l'image :" << reply->errorString();
        reply->deleteLater();
        return false;
    }
}

void MainPage::on_Lecteur_clicked()
{
    QString adresseIP = "172.16.112.232";
    QString nomUtilisateur = "snir";
    QString motDePasse = "root";
    QString commande = "cd pi-rfid/ && python3 lire.py";

    // Construction de la commande plink
    QString commandePlink = "plink";
    QStringList arguments;
    arguments << "-ssh" << nomUtilisateur + "@" + adresseIP << "-pw" << motDePasse <<commande;

    // Exécution de la commande
    QProcess process;
    process.start(commandePlink, arguments);
    process.waitForFinished(-1); // Attendre la fin de l'exécution
    QString resultat = process.readAllStandardOutput();

    // Vérification du résultat de l'exécution
    int codeSortie = process.exitCode();
    if (codeSortie == 0) {
        badgeID = resultat.trimmed(); // Supprime les espaces blancs
        qDebug() << "ID du badge lu:" << badgeID;
        ui->UID->setText(badgeID);
        ui->UID->setReadOnly(true);
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la connexion à la Raspberry Pi ou de l'exécution de la commande.");
    }
}

