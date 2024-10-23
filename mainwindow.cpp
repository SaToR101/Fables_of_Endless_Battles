#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMovie"
#include "QSoundEffect"
#include <QAudioDevice>
#include <QMediaDevices>
#include <QMediaPlayer>
#include <QAudioOutput>
#include<settingscreen.h>
#include <QSettings>
#include "gamewindow.h"
#include "pausewindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , settingsDialog(new SettingScreen(nullptr, true))
    , playerMenuMusic(new QMediaPlayer(this))
    , outputMenuMusic(new QAudioOutput(this))
    , playerMenuButton(new QMediaPlayer(this))
    , outputMenuButton(new QAudioOutput(this))
    //, pauseWindow(new PauseWindow(this))
    ,gameWindow(nullptr)
{
    ui->setupUi(this);

    connect(settingsDialog, &SettingScreen::volumeChanged, this, &MainWindow::changeVolume);

    playerMenuMusic->setAudioOutput(outputMenuMusic);
    playerMenuMusic->setSource(QUrl("D:/CourseWork/realisation/CourseWork/sound/menuMusic.mp3"));

    QSettings settings("BSUIR", "Game");
    int savedVolume = settings.value("volume", 50).toInt();
    outputMenuMusic->setVolume(savedVolume / 100.0f);

    playerMenuMusic->setLoops(QSoundEffect::Infinite);
    playerMenuMusic->play();
    playerMenuButton->setAudioOutput(outputMenuButton);
    playerMenuButton->setSource(QUrl("D:/CourseWork/realisation/CourseWork/sound/menuButtonSound1i.mp3"));
    outputMenuButton->setVolume(0.1);

    QMovie *movie = new QMovie("D:/CourseWork/realisation/CourseWork/img/menuBackGround.gif");
    ui->label->setMovie(movie);
    movie->start();

}

MainWindow::~MainWindow()
{
    playerMenuMusic->stop();
    delete playerMenuMusic;      // Удаление медиаплеера
    delete outputMenuMusic;      // Удаление аудиовыхода
    delete playerMenuButton;      // Удаление медиаплеера для кнопки
    delete outputMenuButton;      // Удаление аудиовыхода для кнопки
    delete ui;
    delete settingsDialog;
    delete gameWindow;
    close();
}

void MainWindow::changeVolume(int volume) {
    outputMenuMusic->setVolume(volume / 100.0f);
}

void MainWindow::on_BPlay_clicked()

{
    if (playerMenuMusic) {
        playerMenuMusic->stop(); // Останавливаем музыку из главного меню
    }
    playerMenuButton->setSource(QUrl("D:/CourseWork/realisation/CourseWork/sound/menuButtonSound1i.mp3"));
    playerMenuButton->play();
    GameWindow *gameWindow = new GameWindow(); // Создайте новое игровое окно
    gameWindow->showFullScreen(); // Отобразите его
    close(); // Закрыть экран настроек, если это необходимо
}

void MainWindow::on_BQuit_clicked(bool checked)
{
    QApplication::quit();
    playerMenuMusic->stop();
    if (!checked) close();
}

void MainWindow::on_BSettings_clicked()
{
    playerMenuButton->setSource(QUrl("D:/CourseWork/realisation/CourseWork/sound/menuButtonSound1i.mp3"));
    playerMenuButton->play();
    settingsDialog->exec();
}

