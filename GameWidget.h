#ifndef HARAMBE_GAMEWIDGET_H
#define HARAMBE_GAMEWIDGET_H


#include <QWidget>
#include <QPushButton>
#include <QSpinBox>
#include <QSlider>
#include <map>

class GameArea;

enum keyState {
    RELEASED,
    PRESSED,
    HOLD
};

class GameWidget : public QWidget {
Q_OBJECT;
private:
    static short const MENU = 1;
    static short const RUNNING = 2;

    std::map<Qt::Key, keyState> pressedKeys = {
            {Qt::Key_Left, RELEASED},
            {Qt::Key_Right, RELEASED},
            {Qt::Key_Up, RELEASED},
            {Qt::Key_Down, RELEASED},
            {Qt::Key_Space, RELEASED}
    };

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

protected:
    void keyPressEvent(QKeyEvent *event) override;

    void keyReleaseEvent(QKeyEvent *event) override;

    void paintEvent(QPaintEvent *event) override;

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
