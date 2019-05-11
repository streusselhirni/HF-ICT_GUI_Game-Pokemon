#include <QHBoxLayout>
#include <QLabel>
#include "GameWidget.h"
#include "GameArea.h"

GameWidget::~GameWidget() {}

GameWidget::GameWidget(QWidget *parent) : QWidget(parent) {
    this->gameArea = new GameArea(this);

    this->createObjects();
    this->createLayout();
    this->connectObjects();
}

void GameWidget::createObjects() {

}

void GameWidget::createLayout() {
    auto vbox = new QVBoxLayout();

    vbox->addWidget(new QLabel("Harambe"));

    vbox->addWidget(this->gameArea);


    auto hbox = new QHBoxLayout();

    this->startButton = new QPushButton("Start");
    hbox->addWidget(this->startButton);

    hbox->addWidget(new QLabel("Shot #"));
    this->numShots = new QLineEdit("0");
    hbox->addWidget(this->numShots);

    hbox->addWidget(new QLabel("Speed"));
    this->speedSlider = new QSlider(Qt::Orientation::Horizontal);
    hbox->addWidget(this->speedSlider);
    this->speedOutput = new QLineEdit("0");
    hbox->addWidget(this->speedOutput);

    hbox->addWidget(new QLabel("Angle"));
    this->angleSlider = new QSlider(Qt::Orientation::Horizontal);
    hbox->addWidget(this->angleSlider);
    this->angleOutput = new QLineEdit("0");
    hbox->addWidget(this->angleOutput);


    vbox->addLayout(hbox);

    this->setLayout(vbox);
}

void GameWidget::connectObjects() {

}
