#ifndef PAUSEWINDOW_H
#define PAUSEWINDOW_H

#include <QDialog>
#include <settingscreen.h>

class MainWindow; // Предварительное объявление
class GameWindow; // Предварительное объявление

namespace Ui {
class PauseWindow;
}

class PauseWindow : public QDialog {
    Q_OBJECT

public:
    explicit PauseWindow(GameWindow *gameWindow, QWidget *parent = nullptr);
    ~PauseWindow();

private slots:
    void on_BQuitPause_clicked();

    void on_BSettingsPause_clicked();

    void on_BMainMenuPause_clicked();

private:
    Ui::PauseWindow *ui;
    SettingScreen *settingsDialog;
    MainWindow *mainMenu;
    GameWindow *gameWindow;

};

#endif // PAUSEWINDOW_H
