QT       += core gui
QT       += multimedia
QT       += multimedia-private network
QT       += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    gamewindow.cpp \
    main.cpp \
    mainwindow.cpp \
    pausewindow.cpp \
    settingscreen.cpp

HEADERS += \
    gamewindow.h \
    mainwindow.h \
    pausewindow.h \
    settingscreen.h

FORMS += \
    gamewindow.ui \
    mainwindow.ui \
    pausewindow.ui \
    settingscreen.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../../Грфон/buttonNN.png \
    ../../Грфон/buttonNN.png \
    Sound/menuButtonSound1i.mp3 \
    Sound/menuMusic1.mp3 \
    fonts/fibberish.ttf \
    img/BOptions.png \
    img/BOptions1.png \
    img/BOptionsHover.png \
    img/BOptionsPress1.png \
    img/BOptionsPressSmall.png \
    img/BPlay.png \
    img/BPlay1.png \
    img/BPlayHover.png \
    img/BPlayHover1.png \
    img/BPlayPress.png \
    img/BPlayPress1.png \
    img/BPlayPressSmall.png \
    img/BPlayPressSmall1.png \
    img/BQuit.png \
    img/BQuit1.png \
    img/BQuitHover.png \
    img/BQuitHover1.png \
    img/BQuitPress1.png \
    img/BQuitPressSmall.png \
    img/BQuitPressSmall1.png \
    img/BSettings.png \
    img/BSettings1.png \
    img/BSettingsHover.png \
    img/BSettingsHover1.png \
    img/BSettingsPress1.png \
    img/BSettingsPressSmall.png \
    img/BSettingsPressSmall1.png \
    img/BackgroundMenyFull.jpg \
    img/BackgroundMenyPix.png \
    img/BlackAlpha.png \
    img/buttonNN.png \
    img/menuBackGround.gif \
    img/menuBackGround.mp4 \
    img/menuIcon.ico \
    img/menuIcon.png \
    img/xK.gif

RESOURCES += \
    resource.qrc
