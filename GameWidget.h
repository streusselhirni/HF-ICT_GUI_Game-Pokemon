#ifndef HARAMBE_GAMEWIDGET_H
#define HARAMBE_GAMEWIDGET_H


#include <QWidget>

class GameArea;

class GameWidget : public QWidget {
Q_OBJECT;
private:
    GameArea *gameArea;

    void createObjects();

    void createLayout();

    void connectObjects();

public:
    virtual ~GameWidget();


    explicit GameWidget(QWidget *parent);
};


#endif //HARAMBE_GAMEWIDGET_H
