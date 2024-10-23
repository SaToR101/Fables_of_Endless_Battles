#include "gamewindow.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QScreen>
#include <QGuiApplication>
#include <QKeyEvent>
#include <QDebug>
#include "pausewindow.h"

GameWindow::GameWindow(QWidget *parent)
    : QWidget(parent),
    pauseWindow(new PauseWindow(this, this)) // Создаем окно паузы
{
    setWindowTitle("Game Window");
    //setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint | Qt::FramelessWindowHint);

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    setGeometry(screenGeometry); // Устанавливаем окно на весь экран

    QLabel *label = new QLabel("Welcome to the Game!", this);
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(label);
    setLayout(layout);
}

void GameWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Escape) {
        openPauseWindow();
    }
}

void GameWindow::openPauseWindow() {
    PauseWindow pauseWindow(this);
    pauseWindow.setModal(true);
    pauseWindow.exec(); // Открывает модальное окно
}
