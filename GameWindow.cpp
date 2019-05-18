#include "GameWindow.h"
#include "GameWidget.h"
#include <QHBoxLayout>
#include <QLabel>

GameWindow::GameWindow(QWidget *parent) : QMainWindow(parent) {
    this->gameWidget = new GameWidget(this);
    this->setFixedSize(1200, 800);
    this->setCentralWidget(this->gameWidget);
}

GameWindow::~GameWindow() {

}
