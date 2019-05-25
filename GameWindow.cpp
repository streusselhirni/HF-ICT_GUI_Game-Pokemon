#include "GameWindow.h"
#include "GameWidget.h"
#include <QHBoxLayout>
#include <QLabel>

GameWindow::GameWindow(QWidget *parent) : QMainWindow(parent) {
    this->windowWidth = 1000;
    this->windowHeight = 600;
    this->gameWidget = new GameWidget(this, this->windowWidth, this->windowHeight);
    this->setFixedSize(this->windowWidth, this->windowHeight);
    this->setCentralWidget(this->gameWidget);
}

GameWindow::~GameWindow() {

}
