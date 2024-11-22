#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QNetworkReply>

namespace Ui {
class MainPage;
}

class MainPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainPage(QWidget *parent = nullptr);
    ~MainPage();

private slots:

    void on_buttonBox_accepted();

    void on_load_button_clicked();

    void replyFinished(QNetworkReply *reply);

    void chargerImageEmployeSelectionne();

    void chargerInfosEmployePourModification();

    void on_pushButton_clicked();

    void modifierInfosEmploye();

    void on_buttonBox_2_accepted();

    void supprimerUtilisateur();

    void on_btn_supprimer_clicked();

    bool upload(const QString& serverUrl, const QString& imagePath);

    void on_ajouter_clicked();

    bool deleteImage(const QString& serverUrl, const QString& imagePath);

    void loadUserData();

    void loadbox();

    void on_Lecteur_clicked();

private:
    Ui::MainPage *ui;
    QNetworkAccessManager *networkManager;
    QString imagePath;
    QString fileName;
    QString badgeID;
};

#endif // MAINPAGE_H
