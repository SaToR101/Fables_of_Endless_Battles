/********************************************************************************
** Form generated from reading UI file 'pausewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAUSEWINDOW_H
#define UI_PAUSEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_PauseWindow
{
public:
    QPushButton *BResumePause;
    QPushButton *BSettingsPause;
    QPushButton *BMainMenuPause;
    QPushButton *BQuitPause;

    void setupUi(QDialog *PauseWindow)
    {
        if (PauseWindow->objectName().isEmpty())
            PauseWindow->setObjectName(QString::fromUtf8("PauseWindow"));
        PauseWindow->resize(800, 1080);
        PauseWindow->setStyleSheet(QString::fromUtf8("background: url(D:/CourseWork/realisation/CourseWork/img/SettingBack.png);\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"border: none;\n"
""));
        BResumePause = new QPushButton(PauseWindow);
        BResumePause->setObjectName(QString::fromUtf8("BResumePause"));
        BResumePause->setGeometry(QRect(173, 100, 454, 164));
        BSettingsPause = new QPushButton(PauseWindow);
        BSettingsPause->setObjectName(QString::fromUtf8("BSettingsPause"));
        BSettingsPause->setGeometry(QRect(173, 320, 454, 164));
        BSettingsPause->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background: url(D:/CourseWork/realisation/CourseWork/img/BSettings.png);\n"
"border: none;\n"
"}\n"
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
        BMainMenuPause = new QPushButton(PauseWindow);
        BMainMenuPause->setObjectName(QString::fromUtf8("BMainMenuPause"));
        BMainMenuPause->setGeometry(QRect(173, 540, 454, 164));
        BMainMenuPause->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background: url(D:/CourseWork/realisation/CourseWork/img/BMenuPause.png);\n"
"border: none;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"border: none;\n"
"background: url(D:/CourseWork/realisation/CourseWork/img/BMenuPauseHover.png);\n"
"}\n"
"\n"
"QPushButton:pressed \n"
"{\n"
"border: none;\n"
"background: url(D:/CourseWork/realisation/CourseWork/img/BMenuPausePressSmall.png);\n"
"}"));
        BQuitPause = new QPushButton(PauseWindow);
        BQuitPause->setObjectName(QString::fromUtf8("BQuitPause"));
        BQuitPause->setGeometry(QRect(173, 760, 454, 164));
        BQuitPause->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        retranslateUi(PauseWindow);

        QMetaObject::connectSlotsByName(PauseWindow);
    } // setupUi

    void retranslateUi(QDialog *PauseWindow)
    {
        PauseWindow->setWindowTitle(QCoreApplication::translate("PauseWindow", "Dialog", nullptr));
        BResumePause->setText(QCoreApplication::translate("PauseWindow", "PushButton", nullptr));
        BSettingsPause->setText(QString());
        BMainMenuPause->setText(QString());
        BQuitPause->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PauseWindow: public Ui_PauseWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAUSEWINDOW_H
