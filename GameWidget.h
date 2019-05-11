#ifndef HARAMBE_GAMEWIDGET_H
#define HARAMBE_GAMEWIDGET_H


#include <QWidget>
#include <QPushButton>
#include <QLineEdit>

class GameArea;

class GameWidget : public QWidget {
Q_OBJECT;
private:
    //GameArea *gameArea;

    void createObjects();

    void createLayout();

    void connectObjects();

    QPushButton *startButton;
    QLineEdit *numShots;

public:
    virtual ~GameWidget();


    explicit GameWidget(QWidget *parent);
};


#endif //HARAMBE_GAMEWIDGET_H
