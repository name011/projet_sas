/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_identifiant;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_password;
    QPushButton *pushButton_singin;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(651, 450);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(190, 130, 233, 133));
        groupBox->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(300, 30));
        label_3->setTextFormat(Qt::AutoText);

        verticalLayout_2->addWidget(label_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(groupBox);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        lineEdit_identifiant = new QLineEdit(groupBox);
        lineEdit_identifiant->setObjectName("lineEdit_identifiant");

        horizontalLayout->addWidget(lineEdit_identifiant);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        lineEdit_password = new QLineEdit(groupBox);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(lineEdit_password);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        pushButton_singin = new QPushButton(groupBox);
        pushButton_singin->setObjectName("pushButton_singin");
        pushButton_singin->setStyleSheet(QString::fromUtf8("/* Styles par d\303\251faut du bouton */\n"
"QPushButton {\n"
"    padding: 2px 10px; /* Marge int\303\251rieure */\n"
"    border: 2px solid #3498db; /* Bordure */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    background-color: #3498db; /* Couleur de fond */\n"
"    color: white; /* Couleur du texte */\n"
"    font-size: 16px; /* Taille de la police */\n"
"}\n"
"\n"
"/* Style du bouton au survol */\n"
"QPushButton:hover {\n"
"    background-color: #2980b9; /* Couleur de fond au survol */\n"
"    border-color: #2980b9; /* Bordure au survol */\n"
"}\n"
"\n"
"/* Style du bouton lorsqu'il est enfonc\303\251 */\n"
"QPushButton:pressed {\n"
"    background-color: #1f618d; /* Couleur de fond lors de l'enfoncement */\n"
"    border-color: #1f618d; /* Bordure lors de l'enfoncement */\n"
"}\n"
"\n"
"/* Style du bouton lorsqu'il est d\303\251sactiv\303\251 */\n"
"QPushButton:disabled {\n"
"    background-color: #bdc3c7; /* Couleur de fond d\303\251sactiv\303\251e */\n"
"    border-color: #bdc3c7; /* Bordure "
                        "d\303\251sactiv\303\251e */\n"
"    color: #7f8c8d; /* Couleur du texte d\303\251sactiv\303\251e */\n"
"}\n"
""));

        verticalLayout_2->addWidget(pushButton_singin);

        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 651, 22));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Connexion</p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Identifiant", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Mot de passe", nullptr));
        pushButton_singin->setText(QCoreApplication::translate("MainWindow", "Se connecter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
