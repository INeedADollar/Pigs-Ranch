/********************************************************************************
** Form generated from reading UI file 'loginmenu.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINMENU_H
#define UI_LOGINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginMenu
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *logo;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginMenu)
    {
        if (LoginMenu->objectName().isEmpty())
            LoginMenu->setObjectName(QString::fromUtf8("LoginMenu"));
        LoginMenu->resize(749, 600);
        LoginMenu->setMinimumSize(QSize(400, 500));
        centralwidget = new QWidget(LoginMenu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        logo = new QLabel(centralwidget);
        logo->setObjectName(QString::fromUtf8("logo"));
        logo->setMinimumSize(QSize(200, 300));
        logo->setPixmap(QPixmap(QString::fromUtf8(":/assets/hamburger_logo.png")));
        logo->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(logo);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(22);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background:#5F5F5F;\n"
"border: 2px solid gray;\n"
"border-radius:12px;\n"
"padding:10 10 10 8px;\n"
"\n"
"}"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background:#5F5F5F;\n"
"border: 2px solid gray;\n"
"border-radius:10px;\n"
"padding:10 10 10 8px;\n"
"\n"
"}"));

        verticalLayout->addWidget(pushButton_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        LoginMenu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LoginMenu);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 749, 23));
        LoginMenu->setMenuBar(menubar);
        statusbar = new QStatusBar(LoginMenu);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        LoginMenu->setStatusBar(statusbar);

        retranslateUi(LoginMenu);

        QMetaObject::connectSlotsByName(LoginMenu);
    } // setupUi

    void retranslateUi(QMainWindow *LoginMenu)
    {
        LoginMenu->setWindowTitle(QCoreApplication::translate("LoginMenu", "MainWindow", nullptr));
        logo->setText(QString());
        label->setText(QCoreApplication::translate("LoginMenu", "Food Heaven", nullptr));
        pushButton->setText(QCoreApplication::translate("LoginMenu", "Login", nullptr));
        pushButton_2->setText(QCoreApplication::translate("LoginMenu", "Register", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateMenu: public Ui_LoginMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINMENU_H
