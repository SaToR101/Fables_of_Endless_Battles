/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *BPlay;
    QPushButton *BSettings;
    QPushButton *BOptions;
    QPushButton *BQuit;
    QWidget *widget;
    QWidget *BackGround;
    QLabel *label;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1920, 1080);
        MainWindow->setMouseTracking(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8("img/menuIcon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        BPlay = new QPushButton(centralwidget);
        BPlay->setObjectName(QString::fromUtf8("BPlay"));
        BPlay->setGeometry(QRect(30, 250, 453, 164));
        BPlay->setAutoFillBackground(false);
        BPlay->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background: url(D:/CourseWork/realisation/CourseWork/img/BPlay.png);\n"
"border: none;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"border: none;\n"
"background: url(D:/CourseWork/realisation/CourseWork/img/BPlayHover.png);\n"
"}\n"
"\n"
"QPushButton:pressed \n"
"{\n"
"border: none;\n"
"background: url(D:/CourseWork/realisation/CourseWork/img/BPlayPressSmall.png);\n"
"}"));
        BPlay->setIconSize(QSize(16, 16));
        BPlay->setAutoDefault(true);
        BPlay->setFlat(false);
        BSettings = new QPushButton(centralwidget);
        BSettings->setObjectName(QString::fromUtf8("BSettings"));
        BSettings->setGeometry(QRect(30, 420, 453, 164));
        BSettings->setAutoFillBackground(false);
        BSettings->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background: url(D:/CourseWork/realisation/CourseWork/img/BSettings.png);\n"
"border: none;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"border: none;\n"
"background: url(D:/CourseWork/realisation/CourseWork/img/BSettingsHover.png);\n"
"}\n"
"\n"
"QPushButton:pressed \n"
"{\n"
"border: none;\n"
"background: url(D:/CourseWork/realisation/CourseWork/img/BSettingsPressSmall.png);\n"
"}"));
        BSettings->setIconSize(QSize(16, 16));
        BSettings->setAutoDefault(true);
        BSettings->setFlat(false);
        BOptions = new QPushButton(centralwidget);
        BOptions->setObjectName(QString::fromUtf8("BOptions"));
        BOptions->setGeometry(QRect(30, 590, 453, 164));
        BOptions->setAutoFillBackground(false);
        BOptions->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background: url(D:/CourseWork/realisation/CourseWork/img/BOptions.png);\n"
"border: none;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"border: none;\n"
"background: url(D:/CourseWork/realisation/CourseWork/img/BOptionsHover.png);\n"
"}\n"
"\n"
"QPushButton:pressed \n"
"{\n"
"border: none;\n"
"background: url(D:/CourseWork/realisation/CourseWork/img/BOptionsPressSmall.png);\n"
"}"));
        BOptions->setIconSize(QSize(16, 16));
        BOptions->setAutoDefault(true);
        BOptions->setFlat(false);
        BQuit = new QPushButton(centralwidget);
        BQuit->setObjectName(QString::fromUtf8("BQuit"));
        BQuit->setGeometry(QRect(30, 760, 453, 164));
        BQuit->setAutoFillBackground(false);
        BQuit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background: url(D:/CourseWork/realisation/CourseWork/img/BQuit.png);\n"
"border: none;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"border: none;\n"
"background: url(D:/CourseWork/realisation/CourseWork/img/BQuitHover.png);\n"
"}\n"
"\n"
"QPushButton:pressed \n"
"{\n"
"border: none;\n"
"background: url(D:/CourseWork/realisation/CourseWork/img/BQuitPressSmall.png);\n"
"}"));
        BQuit->setIconSize(QSize(16, 16));
        BQuit->setAutoDefault(true);
        BQuit->setFlat(false);
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 230, 471, 721));
        widget->setStyleSheet(QString::fromUtf8("background: url(D:/CourseWork/realisation/CourseWork/img/BlackAlpha.png);\n"
"border-radius: 30%;\n"
"border: none;"));
        BackGround = new QWidget(centralwidget);
        BackGround->setObjectName(QString::fromUtf8("BackGround"));
        BackGround->setGeometry(QRect(0, 0, 1920, 1080));
        BackGround->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(BackGround);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 1920, 1080));
        label->setStyleSheet(QString::fromUtf8(""));
        MainWindow->setCentralWidget(centralwidget);
        BackGround->raise();
        widget->raise();
        BPlay->raise();
        BSettings->raise();
        BOptions->raise();
        BQuit->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1920, 21));
        menubar->setStyleSheet(QString::fromUtf8("background-color: rgb(55,25,22);"));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        BPlay->setText(QString());
#if QT_CONFIG(shortcut)
        BPlay->setShortcut(QCoreApplication::translate("MainWindow", "Return", nullptr));
#endif // QT_CONFIG(shortcut)
        BSettings->setText(QString());
#if QT_CONFIG(shortcut)
        BSettings->setShortcut(QCoreApplication::translate("MainWindow", "Return", nullptr));
#endif // QT_CONFIG(shortcut)
        BOptions->setText(QString());
#if QT_CONFIG(shortcut)
        BOptions->setShortcut(QCoreApplication::translate("MainWindow", "Return", nullptr));
#endif // QT_CONFIG(shortcut)
        BQuit->setText(QString());
#if QT_CONFIG(shortcut)
        BQuit->setShortcut(QCoreApplication::translate("MainWindow", "Return", nullptr));
#endif // QT_CONFIG(shortcut)
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
