#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "settingscreen.h"
#include <QMediaPlayer>
#include <QAudioOutput>
#include "pausewindow.h"
#include "gamewindow.h"



QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:
    void on_BPlay_clicked();

    void on_BQuit_clicked(bool checked);

    void on_BSettings_clicked();

    void changeVolume(int volume); // Слот для изменения громкости

private:
    Ui::MainWindow *ui;
    SettingScreen *settingsDialog;
    QMediaPlayer *playerMenuMusic; // Убедитесь, что эта строка есть
    QAudioOutput *outputMenuMusic; // Убедитесь, что эта строка есть
    QMediaPlayer *playerMenuButton;
    QAudioOutput *outputMenuButton;
    PauseWindow *pauseWindow;
    GameWindow *gameWindow;


};
#endif // MAINWINDOW_H
