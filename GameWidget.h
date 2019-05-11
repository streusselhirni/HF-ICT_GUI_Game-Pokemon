#ifndef HARAMBE_GAMEWIDGET_H
#define HARAMBE_GAMEWIDGET_H


#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QSlider>

class GameArea;

class GameWidget : public QWidget {
Q_OBJECT;
private:
    GameArea *gameArea;

    // GUI
    QPushButton *startButton;
    QLineEdit *numShots;
    QSlider *speedSlider;
    QLineEdit *speedOutput;
    QSlider *angleSlider;
    QLineEdit *angleOutput;

    void createObjects();

    void createLayout();

    void connectObjects();


public:
    virtual ~GameWidget();


    explicit GameWidget(QWidget *parent);
};


#endif //HARAMBE_GAMEWIDGET_H