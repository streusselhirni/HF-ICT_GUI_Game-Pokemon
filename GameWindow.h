#ifndef HARAMBE_GAMEWINDOW_H
#define HARAMBE_GAMEWINDOW_H


#include <QMainWindow>

class QWidget;

class GameWindow: public QMainWindow
{
Q_OBJECT
public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow() override;

private:
    QWidget *gameWidget;
};


#endif //HARAMBE_GAMEWINDOW_H
