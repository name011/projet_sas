#include <QCoreApplication>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTextStream>
#include <iostream>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

class Server : public QTcpServer
{
    Q_OBJECT

public: //ce programme se comporte comme un serveur en attente de l'id que le programme python peut lui envoyerw
    Server(QObject *parent = nullptr) : QTcpServer(parent)
    {
        connect(this, &QTcpServer::newConnection, this, &Server::onNewConnection);
    }

    void startServer()
    {
        if (this->listen(QHostAddress::Any, 8080)) {
            std::cout << "Serveur lancé, en attente de connection..." << std::endl;
        } else {
            std::cerr << "Impossible de lancer le serveur: " << this->errorString().toStdString() << std::endl;
        }
    }

private slots:
    void onNewConnection()
    {
        QTcpSocket *socket = this->nextPendingConnection();
        connect(socket, &QTcpSocket::readyRead, this, &Server::onReadyRead);
        std::cout << "Client connecté." << std::endl;
    }
    void onReadyRead()
    {
        QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
        if (socket) {
            QByteArray data = socket->readAll();
            QString id = QString::fromUtf8(data);
            std::cout << "ID received: " << id.toStdString() << std::endl;

            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
            db.setUserName("snir");
            db.setPassword("root");
            db.setHostName("172.16.112.234");
            db.setDatabaseName("sas");
            db.setPort(3306);

            if (db.open()) {
                QSqlQuery query(db);
                QSqlQuery query2(db);
                query.prepare("SELECT * FROM employe WHERE ID = :id");
                query2.prepare("SELECT lien_photo FROM photosemployes WHERE id_employe = :id");
                query.bindValue(":id", id);
                query2.bindValue(":id", id);

                if (query.exec()) {
                    if (query.next()) {
                        int employeeId = query.value(0).toInt();
                        QString firstName = query.value(1).toString();
                        QString lastName = query.value(2).toString();
                        QString date = query.value(3).toString();

                        std::cout << "Employee ID: " << employeeId << std::endl;
                        std::cout << "nom: " << firstName.toStdString() << std::endl;
                        std::cout << "prénom: " << lastName.toStdString() << std::endl;
                        std::cout << "Date: " << date.toStdString() << std::endl;
                    } else {
                        std::cout << "Id non trouvé" << std::endl;
                    }
                } else {
                    std::cerr << "Query erreur: " << query.lastError().text().toStdString() << std::endl;
                }
                if(query2.exec()){
                    if(query2.next()){
                        QString lien = query2.value(0).toString();
                        std::cout << "lien: " << lien.toStdString() << std::endl;
                    }else {
                        std::cout << "l'employé ne possède pas de photo" << std::endl;
                    }
                }else {
                    std::cerr << "Query erreur: " << query.lastError().text().toStdString() << std::endl;
                }

                db.close();
            } else {
                std::cerr << "Database connection erreur: " << db.lastError().text().toStdString() << std::endl;
            }

            socket->close();
        }
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Server server;
    server.startServer();

    return a.exec();
}

#include "main.moc" //absolument laisser
