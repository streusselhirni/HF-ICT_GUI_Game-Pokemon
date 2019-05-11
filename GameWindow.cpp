//
// Created by Nicolas Haenni on 2019-05-11.
//

#include "GameWindow.h"
#include "GameArea.h"
#include <QHBoxLayout>
#include <QLabel>

GameWindow::GameWindow(QWidget* parent)
{
    this->gameWidget = new QWidget();

    this->setCentralWidget(gameWidget);
    this->setWindowTitle("Harambe Returns");
}

GameWindow::~GameWindow()
{

}
