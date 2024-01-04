/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *keyLineEdit;
    QPushButton *closePushButton;
    QTextBrowser *textBrowser;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *findPushButton;
    QCheckBox *matchCheckBox;
    QLineEdit *fileLineEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(230, 10, 276, 224));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        keyLineEdit = new QLineEdit(gridLayoutWidget);
        keyLineEdit->setObjectName(QString::fromUtf8("keyLineEdit"));

        gridLayout->addWidget(keyLineEdit, 1, 1, 1, 1);

        closePushButton = new QPushButton(gridLayoutWidget);
        closePushButton->setObjectName(QString::fromUtf8("closePushButton"));

        gridLayout->addWidget(closePushButton, 1, 2, 1, 1);

        textBrowser = new QTextBrowser(gridLayoutWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        gridLayout->addWidget(textBrowser, 5, 0, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        findPushButton = new QPushButton(gridLayoutWidget);
        findPushButton->setObjectName(QString::fromUtf8("findPushButton"));

        gridLayout->addWidget(findPushButton, 0, 2, 1, 1);

        matchCheckBox = new QCheckBox(gridLayoutWidget);
        matchCheckBox->setObjectName(QString::fromUtf8("matchCheckBox"));

        gridLayout->addWidget(matchCheckBox, 3, 0, 1, 1);

        fileLineEdit = new QLineEdit(gridLayoutWidget);
        fileLineEdit->setObjectName(QString::fromUtf8("fileLineEdit"));

        gridLayout->addWidget(fileLineEdit, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        closePushButton->setText(QCoreApplication::translate("MainWindow", "close", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Find from file", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", " find what", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "search status", nullptr));
        findPushButton->setText(QCoreApplication::translate("MainWindow", "find", nullptr));
        matchCheckBox->setText(QCoreApplication::translate("MainWindow", "Matchcase", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
