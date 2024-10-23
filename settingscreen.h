#ifndef SETTINGSCREEN_H
#define SETTINGSCREEN_H
#include <QDialog>
#include <QSlider>
#include <QLabel>
#include <QMediaDevices>
#include <QMediaPlayer>
#include <QAudioOutput>

namespace Ui {
class SettingScreen;
}

class SettingScreen : public QDialog
{
    Q_OBJECT

public:
    explicit SettingScreen(QWidget *parent = nullptr, bool isTransparent = true);
    ~SettingScreen();

signals:
    void volumeChanged(int volume);

private slots:
    void updateVolumeLabel(int value);
    void on_Confirm_Button_clicked();
    void updateDifficulty(int value);
    void mouseReleaseEvent(QMouseEvent *event);


private:
    QSlider *volumeSlider;
    QSlider *difficultySlider;
    Ui::SettingScreen *ui;
    QLabel *volumeLabel;
    QLabel *MusicSettingLabel;
    QLabel *difficultyLabel;
    QMediaPlayer *difSound;
    QAudioOutput *outputSettingState;
    bool firstRun;

};

#endif // SETTINGSCREEN_H
