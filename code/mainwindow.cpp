#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainpage.h"
#include <QMessageBox>
#include <QString>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QtWidgets>
MainWindow::MainWindow(QWidget *parent)

    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPushButton *pushButton_singin = ui->pushButton_singin;
    connect(pushButton_singin, &QPushButton::clicked, this, &MainWindow::VerifierLaConnexion);
    QShortcut *shortcut = new QShortcut(QKeySequence(Qt::Key_Return), this);
    connect(shortcut, &QShortcut::activated, this, &MainWindow::VerifierLaConnexion);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::VerifierLaConnexion()
{
    QString identifiant = ui->lineEdit_identifiant->text();
    QString password = ui->lineEdit_password->text();
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setUserName(identifiant);
    db.setPassword(password);
    db.setHostName("172.16.112.234");
    db.setDatabaseName("sas");
    db.setPort(3306);
    if(db.open()){
        this->hide();
        MainPage *mainpage = new MainPage();
        mainpage->show();
    }
    else {
        QMessageBox::about(nullptr, "Erreur de connexion", "Erreur de connexion à la base de données : " + db.lastError().text());
    }
}

