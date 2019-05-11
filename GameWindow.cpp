#include "GameWindow.h"
#include "GameWidget.h"
#include <QHBoxLayout>
#include <QLabel>

GameWindow::GameWindow(QWidget *parent) : QMainWindow(parent) {
    this->gameWidget = new GameWidget(this);
    this->setCentralWidget(this->gameWidget);
}

GameWindow::~GameWindow() {

}
