/********************************************************************************
** Form generated from reading UI file 'settingscreen.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSCREEN_H
#define UI_SETTINGSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingScreen
{
public:
    QWidget *widget;
    QPushButton *Confirm_Button;
    QWidget *widget_2;

    void setupUi(QDialog *SettingScreen)
    {
        if (SettingScreen->objectName().isEmpty())
            SettingScreen->setObjectName(QString::fromUtf8("SettingScreen"));
        SettingScreen->resize(800, 1080);
        SettingScreen->setStyleSheet(QString::fromUtf8(""));
        widget = new QWidget(SettingScreen);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 800, 1080));
        widget->setStyleSheet(QString::fromUtf8("background: url(D:/CourseWork/realisation/CourseWork/img/SettingBack.png);\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"border: none;\n"
""));
        Confirm_Button = new QPushButton(widget);
        Confirm_Button->setObjectName(QString::fromUtf8("Confirm_Button"));
        Confirm_Button->setGeometry(QRect(560, 1000, 180, 60));
        Confirm_Button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background: url(D:/CourseWork/realisation/CourseWork/img/BConfirm.png);\n"
"border: none;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"border: none;\n"
"background: url(D:/CourseWork/realisation/CourseWork/img/BConfirmHover.png);\n"
"}\n"
"\n"
"QPushButton:pressed \n"
"{\n"
"border: none;\n"
"background: url(D:/CourseWork/realisation/CourseWork/img/BConfirmPress.png);\n"
"}"));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(100, 50, 600, 200));
        widget_2->setStyleSheet(QString::fromUtf8("background: url(D:/CourseWork/realisation/CourseWork/img/SettingsLogo.png);"));

        retranslateUi(SettingScreen);

        QMetaObject::connectSlotsByName(SettingScreen);
    } // setupUi

    void retranslateUi(QDialog *SettingScreen)
    {
        SettingScreen->setWindowTitle(QCoreApplication::translate("SettingScreen", "Dialog", nullptr));
        Confirm_Button->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SettingScreen: public Ui_SettingScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSCREEN_H
