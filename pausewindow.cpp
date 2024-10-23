#include "pausewindow.h"
#include "ui_pausewindow.h"
#include <QFontDatabase>
#include <QFont>
#include <settingscreen.h>
#include <mainwindow.h>

PauseWindow::PauseWindow(GameWindow *gameWindow, QWidget *parent)
    : QDialog(parent)
    ,ui(new Ui::PauseWindow)
    ,settingsDialog(new SettingScreen(this, false))
    ,gameWindow(gameWindow)

{
    ui->setupUi(this);


    int fontId = QFontDatabase::addApplicationFont(":/fonts/fibberish.ttf");
    QString family = QFontDatabase::applicationFontFamilies(fontId).at(0);
    QFont pixelFont(family);
    pixelFont.setPointSize(24);

    //setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint );
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
    setFixedSize(800, 1080);

}

PauseWindow::~PauseWindow() {
    delete ui;
}

void PauseWindow::on_BQuitPause_clicked()
{
    QApplication::quit();
}

void PauseWindow::on_BSettingsPause_clicked()
{
    settingsDialog->exec(); // Или exec() для модального окна
}

void PauseWindow::on_BMainMenuPause_clicked()
{
    if (gameWindow) {
        gameWindow->close(); // Закрытие игрового окна, если оно открыто
    }
    this->close(); // Закрытие окна паузы
    // Создаем новый экземпляр главного меню
    MainWindow *newMainMenu = new MainWindow(); // Если нужно, передайте параметры
    newMainMenu->showFullScreen(); // Показ нового главного меню
    // Закрытие игрового окна
}

