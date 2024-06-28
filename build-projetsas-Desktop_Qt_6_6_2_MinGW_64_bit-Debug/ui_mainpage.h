/********************************************************************************
** Form generated from reading UI file 'mainpage.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINPAGE_H
#define UI_MAINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainPage
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *txt_nom;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *txt_prenom;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QDateEdit *date_de_naissance;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QPushButton *ajouter;
    QDialogButtonBox *buttonBox;
    QTableView *user_list;
    QLabel *imageLabel_2;
    QPushButton *Lecteur;
    QLineEdit *UID;
    QWidget *tab_3;
    QTableView *user_list_2;
    QLabel *imageLabel;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_5;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *btn_supprimer;
    QPushButton *pushButton;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *txt_nom_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QLineEdit *txt_prenom_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QDateEdit *date_de_naissance_2;
    QHBoxLayout *horizontalLayout_8;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;
    QDialogButtonBox *buttonBox_2;
    QMenuBar *menuBar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainPage)
    {
        if (MainPage->objectName().isEmpty())
            MainPage->setObjectName("MainPage");
        MainPage->resize(1171, 528);
        centralwidget = new QWidget(MainPage);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tab = new QWidget();
        tab->setObjectName("tab");
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(9, 9, 1131, 181));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        txt_nom = new QLineEdit(groupBox);
        txt_nom->setObjectName("txt_nom");

        horizontalLayout->addWidget(txt_nom);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(groupBox);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        txt_prenom = new QLineEdit(groupBox);
        txt_prenom->setObjectName("txt_prenom");

        horizontalLayout_2->addWidget(txt_prenom);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_3->addWidget(label_3);

        date_de_naissance = new QDateEdit(groupBox);
        date_de_naissance->setObjectName("date_de_naissance");
        date_de_naissance->setContextMenuPolicy(Qt::CustomContextMenu);
        date_de_naissance->setWrapping(true);

        horizontalLayout_3->addWidget(date_de_naissance);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName("checkBox");

        horizontalLayout_4->addWidget(checkBox);

        checkBox_2 = new QCheckBox(groupBox);
        checkBox_2->setObjectName("checkBox_2");

        horizontalLayout_4->addWidget(checkBox_2);

        checkBox_3 = new QCheckBox(groupBox);
        checkBox_3->setObjectName("checkBox_3");

        horizontalLayout_4->addWidget(checkBox_3);

        ajouter = new QPushButton(groupBox);
        ajouter->setObjectName("ajouter");

        horizontalLayout_4->addWidget(ajouter);


        verticalLayout->addLayout(horizontalLayout_4);

        buttonBox = new QDialogButtonBox(groupBox);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

        user_list = new QTableView(tab);
        user_list->setObjectName("user_list");
        user_list->setGeometry(QRect(9, 193, 701, 187));
        imageLabel_2 = new QLabel(tab);
        imageLabel_2->setObjectName("imageLabel_2");
        imageLabel_2->setGeometry(QRect(750, 190, 381, 191));
        imageLabel_2->setFrameShape(QFrame::Panel);
        Lecteur = new QPushButton(tab);
        Lecteur->setObjectName("Lecteur");
        Lecteur->setGeometry(QRect(10, 400, 75, 24));
        UID = new QLineEdit(tab);
        UID->setObjectName("UID");
        UID->setGeometry(QRect(100, 400, 113, 22));
        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        user_list_2 = new QTableView(tab_3);
        user_list_2->setObjectName("user_list_2");
        user_list_2->setGeometry(QRect(410, 110, 621, 61));
        imageLabel = new QLabel(tab_3);
        imageLabel->setObjectName("imageLabel");
        imageLabel->setGeometry(QRect(20, 110, 331, 281));
        imageLabel->setFrameShape(QFrame::Panel);
        layoutWidget = new QWidget(tab_3);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 40, 211, 61));
        verticalLayout_5 = new QVBoxLayout(layoutWidget);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        comboBox = new QComboBox(layoutWidget);
        comboBox->setObjectName("comboBox");

        verticalLayout_5->addWidget(comboBox);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        btn_supprimer = new QPushButton(layoutWidget);
        btn_supprimer->setObjectName("btn_supprimer");

        horizontalLayout_9->addWidget(btn_supprimer);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName("pushButton");

        horizontalLayout_9->addWidget(pushButton);


        verticalLayout_5->addLayout(horizontalLayout_9);

        groupBox_2 = new QGroupBox(tab_3);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(410, 190, 621, 201));
        verticalLayout_4 = new QVBoxLayout(groupBox_2);
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName("label_4");

        horizontalLayout_5->addWidget(label_4);

        txt_nom_2 = new QLineEdit(groupBox_2);
        txt_nom_2->setObjectName("txt_nom_2");

        horizontalLayout_5->addWidget(txt_nom_2);


        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName("label_5");

        horizontalLayout_6->addWidget(label_5);

        txt_prenom_2 = new QLineEdit(groupBox_2);
        txt_prenom_2->setObjectName("txt_prenom_2");

        horizontalLayout_6->addWidget(txt_prenom_2);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName("label_6");
        label_6->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_7->addWidget(label_6);

        date_de_naissance_2 = new QDateEdit(groupBox_2);
        date_de_naissance_2->setObjectName("date_de_naissance_2");
        date_de_naissance_2->setContextMenuPolicy(Qt::CustomContextMenu);
        date_de_naissance_2->setWrapping(true);

        horizontalLayout_7->addWidget(date_de_naissance_2);


        verticalLayout_4->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        checkBox_4 = new QCheckBox(groupBox_2);
        checkBox_4->setObjectName("checkBox_4");

        horizontalLayout_8->addWidget(checkBox_4);

        checkBox_5 = new QCheckBox(groupBox_2);
        checkBox_5->setObjectName("checkBox_5");

        horizontalLayout_8->addWidget(checkBox_5);

        checkBox_6 = new QCheckBox(groupBox_2);
        checkBox_6->setObjectName("checkBox_6");

        horizontalLayout_8->addWidget(checkBox_6);


        verticalLayout_4->addLayout(horizontalLayout_8);

        buttonBox_2 = new QDialogButtonBox(groupBox_2);
        buttonBox_2->setObjectName("buttonBox_2");
        buttonBox_2->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_4->addWidget(buttonBox_2);

        tabWidget->addTab(tab_3, QString());

        verticalLayout_2->addWidget(tabWidget);

        MainPage->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainPage);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1171, 22));
        MainPage->setMenuBar(menuBar);
        statusbar = new QStatusBar(MainPage);
        statusbar->setObjectName("statusbar");
        MainPage->setStatusBar(statusbar);

        retranslateUi(MainPage);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainPage);
    } // setupUi

    void retranslateUi(QMainWindow *MainPage)
    {
        MainPage->setWindowTitle(QCoreApplication::translate("MainPage", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainPage", "Ajouter un utilisateur", nullptr));
        label_2->setText(QCoreApplication::translate("MainPage", "Nom :", nullptr));
        label->setText(QCoreApplication::translate("MainPage", "Pr\303\251nom :", nullptr));
        label_3->setText(QCoreApplication::translate("MainPage", "Date de naissance :", nullptr));
        checkBox->setText(QCoreApplication::translate("MainPage", "Acc\303\250s niveau 1", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainPage", "Acc\303\250s niveau 2", nullptr));
        checkBox_3->setText(QCoreApplication::translate("MainPage", "Acc\303\250s niveau 3", nullptr));
        ajouter->setText(QCoreApplication::translate("MainPage", "Ajouter une photo", nullptr));
        imageLabel_2->setText(QString());
        Lecteur->setText(QCoreApplication::translate("MainPage", "Lecteur", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainPage", "Gestion", nullptr));
        imageLabel->setText(QString());
        btn_supprimer->setText(QCoreApplication::translate("MainPage", "Supprimer", nullptr));
        pushButton->setText(QCoreApplication::translate("MainPage", "Modifier", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainPage", "Modifier un utilisateur", nullptr));
        label_4->setText(QCoreApplication::translate("MainPage", "Nom :", nullptr));
        label_5->setText(QCoreApplication::translate("MainPage", "Pr\303\251nom :", nullptr));
        label_6->setText(QCoreApplication::translate("MainPage", "Date de naissance :", nullptr));
        checkBox_4->setText(QCoreApplication::translate("MainPage", "Acc\303\250s niveau 1", nullptr));
        checkBox_5->setText(QCoreApplication::translate("MainPage", "Acc\303\250s niveau 2", nullptr));
        checkBox_6->setText(QCoreApplication::translate("MainPage", "Acc\303\250s niveau 3", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainPage", "Modification", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainPage: public Ui_MainPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINPAGE_H
