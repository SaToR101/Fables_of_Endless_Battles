#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include "pausewindow.h" // Подключение заголовка PauseWindow

class GameWindow : public QWidget {
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void openPauseWindow();

private:
    PauseWindow *pauseWindow; // Указатель на окно паузы
};

#endif // GAMEWINDOW_H
