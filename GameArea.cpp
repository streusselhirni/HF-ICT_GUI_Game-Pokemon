#include "GameArea.h"
#include <QImage>
#include <QPainter>

void GameArea::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.drawImage(0, 0, this->backgroundImage->scaledToWidth(640));
}

GameArea::GameArea(QWidget* parent)
{
    this->backgroundImage = new QImage("img/background.jpg");
}

GameArea::~GameArea()
{

}
