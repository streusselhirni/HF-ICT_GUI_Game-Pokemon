#ifndef HARAMBE_GAMEWINDOW_H
#define HARAMBE_GAMEWINDOW_H


#include <QMainWindow>

class QWidget;

class GameWindow : public QMainWindow {
Q_OBJECT
private:
    QWidget *gameWidget;

public:
    explicit GameWindow(QWidget *parent = nullptr);

    ~GameWindow() override;

};


#endif //HARAMBE_GAMEWINDOW_H
