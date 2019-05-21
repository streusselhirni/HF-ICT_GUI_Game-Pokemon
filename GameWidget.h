#ifndef HARAMBE_GAMEWIDGET_H
#define HARAMBE_GAMEWIDGET_H


#include <QWidget>
#include <QPushButton>
#include <QSpinBox>
#include <QSlider>

class GameArea;

class GameWidget : public QWidget {
Q_OBJECT;
private:
    static short const MENU = 1;
    static short const RUNNING = 2;

    GameArea *gameArea;
    int width;
    int height;

    // GUI
    QPushButton *actionButton;
    QSpinBox *numShots;
    QSlider *speedSlider;
    QSpinBox *speedOutput;
    QSlider *angleSlider;
    QSpinBox *angleOutput;

    short currentState;
    uint64_t lastPushTime;

    void createObjects();

    void createLayout();

    void connectObjects();

    void reset();

public:
    virtual ~GameWidget();

    explicit GameWidget(QWidget *parent, int w, int h);

    void actionButtonClicked();

    bool isInteractable();

    bool isRunning();

    void onGameFinished();

signals:
    void shoot(int speed, int angle);
};


#endif //HARAMBE_GAMEWIDGET_H
