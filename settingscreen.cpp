#include "settingscreen.h"
#include "ui_settingscreen.h"
#include <QMouseEvent>
#include <QVBoxLayout>
#include <QSettings>
#include <QLabel>
#include <QFontDatabase>
#include <QFont>
#include <QMediaDevices>
#include <QMediaPlayer>
#include <QAudioOutput>


QSettings menuMusicVolemeSettings("BSUIR", "Game");
QSettings gameDifficultySettings("BSUIR", "Game");

const
    int menuMusicX = 100, menuMusicY = 250, sliderWidth = 600, sliderHeight = 50,
        gameDifficultyX = 100, gameDifficultyY = 380;


SettingScreen::SettingScreen(QWidget *parent, bool isTransparent)
    : QDialog(parent)
    , ui(new Ui::SettingScreen)
    , difSound(new QMediaPlayer(this))
    , outputSettingState(new QAudioOutput(this))
    , firstRun(true)
{
    ui->setupUi(this);

    if (isTransparent) {
        setAttribute(Qt::WA_TranslucentBackground);
        setWindowOpacity(0.9); // Полупрозрачный фон
    } else {
        setAttribute(Qt::WA_TranslucentBackground, false); // Непрозрачный фон
        setWindowOpacity(1.0); // Полная непрозрачность
    }

    int fontId = QFontDatabase::addApplicationFont(":/fonts/fibberish.ttf");
    QString family = QFontDatabase::applicationFontFamilies(fontId).at(0);
    QFont pixelFont(family);
    pixelFont.setPointSize(24);

    difSound->setAudioOutput(outputSettingState);
    difSound->setSource(QUrl("D:/CourseWork/realisation/CourseWork/sound/DifChoseSound.mp3"));
    outputSettingState->setVolume(0.3);

    setWindowFlags(Qt::Dialog |Qt::FramelessWindowHint | Qt::WindowTitleHint);
    setFixedSize(800, 1080);
    setWindowOpacity(0.9);
    QApplication::setQuitOnLastWindowClosed(false);

    volumeSlider = new QSlider(Qt::Horizontal, this);
    volumeSlider->setFixedWidth(sliderWidth);
    volumeSlider->setFixedHeight(sliderHeight);
    volumeSlider->setStyleSheet(
        "QSlider::handle:horizontal {"
        "   margin: -20px px;" // Отрицательные отступы для выхода за пределы
        "   image: url(D:/CourseWork/realisation/CourseWork/img/handle.png);" // Цвет ручки
        "   width: 34px;" // Ширина ручки (измените на размер изображения)
        "   height: 44px;" // Высота ручки (должна быть больше высоты дорожки)
        "   border: none"
        "}"
        "QSlider::groove:horizontal {"
        "    border: 1px solid;"
        "    height: 10px;"
        "}"
        "QSlider::sub-page:horizontal {"
        "   background: #6F2B11;" // Цвет до ручки
        "}"
        "QSlider::add-page:horizontal {"
        "   background: #B9692C;" // Цвет после ручки
        "}"
        );
    volumeSlider->setRange(0, 100);
    volumeSlider->setValue(50);
    volumeSlider->move(menuMusicX, menuMusicY+25); // Задайте координаты x и y


    volumeLabel = new QLabel(QString::number(volumeSlider->value()), this);
    volumeLabel->move(menuMusicX+sliderWidth + 10, menuMusicY+33); // Устанавливаем положение QLabel рядом с ползунком
    volumeLabel->setFixedWidth(50);
    volumeLabel->setFont(pixelFont);
    volumeLabel->setStyleSheet("color: #3F2332;");
    volumeLabel->setStyleSheet("background-color: transparent;");

    MusicSettingLabel = new QLabel(QString::number(volumeSlider->value()), this);
    MusicSettingLabel->move(menuMusicX, menuMusicY); // Устанавливаем положение QLabel рядом с ползунком
    MusicSettingLabel->setFixedWidth(300);
    MusicSettingLabel->setFont(pixelFont);
    MusicSettingLabel->setStyleSheet("color: #3F2332;");
    MusicSettingLabel->setText("Menu Music");
    MusicSettingLabel->setStyleSheet("background-color: transparent;");

    connect(volumeSlider, &QSlider::valueChanged, this, &SettingScreen::updateVolumeLabel);
    connect(volumeSlider, &QSlider::valueChanged, this, &SettingScreen::volumeChanged);

    int savedVolume =menuMusicVolemeSettings.value("volume", 50).toInt();
    volumeSlider->setValue(savedVolume);
    volumeLabel->setText(QString::number(savedVolume)); // Обновляем текст QLabel



    difficultySlider = new QSlider(Qt::Horizontal, this);
    difficultySlider->setFixedWidth(sliderWidth);
    difficultySlider->setFixedHeight(sliderHeight);
    difficultySlider->setRange(0, 3); // 0: Лёгкий, 1: Средний, 2: Сложный, 3: Очень сложный
    difficultySlider->move(gameDifficultyX, gameDifficultyY + 40);

    difficultySlider->setStyleSheet(
        "QSlider {"
        "background: url(D:/CourseWork/realisation/CourseWork/img/DifficultySliderBackBig.png);"
        "}"
        "QSlider::groove:horizontal {"

        "   height: 0px;"
        "   border-radius: 5px;"
        "   margin: 0 75px;" // Отступы по бокам дорожки
        "}"
        "QSlider::handle:horizontal {"
        "   width: 50px;"
        "   height: 50px;"
        "   border-radius: 15px;"
        "   background: red;" // Начальный цвет ручки
        "   margin: -25px 0;" // Убираем отступы для ручки
        "}"
        );
    // Инициализация лейбла для отображения уровня сложности
    difficultyLabel = new QLabel("Difficulty: Easy", this);
    difficultyLabel->setFixedWidth(300);
    difficultyLabel->move(gameDifficultyX, gameDifficultyY);
    difficultyLabel->setFont(pixelFont);

    // Подключение сигналов
    connect(difficultySlider, &QSlider::valueChanged, this, &SettingScreen::updateDifficulty);


    // Установка значения слайдера без вызова updateDifficulty
    int savedDifficulty = gameDifficultySettings.value("difficulty", 0).toInt();
    difficultySlider->setValue(savedDifficulty); // Установка значения слайдера
    firstRun = true;
    updateDifficulty(savedDifficulty); // Обновляем текст метки и стиль

}


SettingScreen::~SettingScreen()
{
    delete ui;
    close();
}

void SettingScreen::updateVolumeLabel(int value)
{
    volumeLabel->setText(QString::number(value)); // Обновляем текст QLabel с текущим значением
}

void SettingScreen::on_Confirm_Button_clicked()
{
    int volume = volumeSlider->value();
    emit volumeChanged(volume);
    menuMusicVolemeSettings.setValue("volume", volume);
    close();
}


void SettingScreen::updateDifficulty(int value)
{
    QString difficultyText;
    QString handleStyle;
    QString BackGround;

    BackGround = "background: url(D:/CourseWork/realisation/CourseWork/img/DifficultySliderBackBig.png);";

    difSound->setSource(QUrl("D:/CourseWork/realisation/CourseWork/sound/DifChoseSound.mp3"));
    switch (value) {
    case 0:
        difficultyText = "Difficulty: Easy";
        handleStyle = "background: url(D:/CourseWork/realisation/CourseWork/img/DifEasy.png);";
        //BackGround = "background:url(D:/CourseWork/realisation/CourseWork/img/DifficultySliderBackBigE.png);";
        break;
    case 1:
        difficultyText = "Difficulty: Medium";
        handleStyle = "background:url(D:/CourseWork/realisation/CourseWork/img/DifMedium.png);";
        //BackGround = "background:url(D:/CourseWork/realisation/CourseWork/img/DifficultySliderBackBigM.png);";
        break;
    case 2:
        difficultyText = "Difficulty: Hard";
        handleStyle = "background:url(D:/CourseWork/realisation/CourseWork/img/DifHard.png);";
        //BackGround = "background:url(D:/CourseWork/realisation/CourseWork/img/DifficultySliderBackBigH.png);";
        break;
    case 3:
        difficultyText = "Difficulty: Very Hard";
        handleStyle = "background:url(D:/CourseWork/realisation/CourseWork/img/DifVeryHard.png);";
        //BackGround = "background:url(D:/CourseWork/realisation/CourseWork/img/DifficultySliderBackBigVH.png);";
        difSound->setSource(QUrl("D:/CourseWork/realisation/CourseWork/sound/DifChoseSoundVH.mp3"));
        break;
    }

    difficultyLabel->setText(difficultyText); // Обновляем текст метки

    // Обновляем стиль ручки
    difficultySlider->setStyleSheet(
        "QSlider {"
        + BackGround +
        "}"
        "QSlider::groove:horizontal {"
        "   height: 0px;"
        "   border-radius: 5px;"
        "   margin: 0 49px;"
        "}"
        "QSlider::handle:horizontal {"
        "   width: 50px;"
        "   height: 50px;"
        "   border-radius: 15px;"
        + handleStyle +
        "   margin: -25px 0;"
        "}"
        );

    // Воспроизводим звук переключения уровня сложности только если уровень был изменён и это не первый запуск
    if (!firstRun) {
        difSound->play();
    }

    // Сохраняем уровень сложности
    gameDifficultySettings.setValue("difficulty", value);
    // Устанавливаем флаг, что первый запуск завершён
    firstRun = false;
}

void SettingScreen::mouseReleaseEvent(QMouseEvent *event)
{
    if (difficultySlider->geometry().contains(event->pos())) {
        // Получаем координаты клика относительно слайдера
        int x = event->pos().x() - difficultySlider->pos().x();
        int sliderWidth = difficultySlider->width();

        // Определяем ширину отступа для каждых предустановленных значений
        const int margin = 60; // Установите значение отступа в пикселях
        const int step = (sliderWidth - 2 * margin) / (difficultySlider->maximum() - difficultySlider->minimum());

        // Находим ближайшее предустановленное значение
        int closestValue = difficultySlider->minimum(); // Начальное значение
        for (int i = difficultySlider->minimum(); i <= difficultySlider->maximum(); ++i) {
            // Вычисляем позицию для каждого предустановленного значения с учетом отступа
            int position = margin + (i - difficultySlider->minimum()) * step;
            if (std::abs(x - position) <= (step / 2)) { // Проверяем, попадает ли клик в диапазон
                closestValue = i;
                break;
            }
        }

        // Устанавливаем значение слайдера и обновляем метку
        if (closestValue != difficultySlider->value()){
        difficultySlider->setValue(closestValue);
        updateDifficulty(closestValue); // Обновляем уровень сложности
        }
    }
}



