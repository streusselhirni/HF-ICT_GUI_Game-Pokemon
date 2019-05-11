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

    auto title = new QLabel("<h1>Harambe</h1>");
    title->setMaximumHeight(50);
    vbox->addWidget(title);
    vbox->addWidget(this->gameArea);

    auto hbox = new QHBoxLayout();

    this->startButton = new QPushButton("Start");
    hbox->addWidget(this->startButton);

    hbox->addWidget(new QLabel("Shot #"));
    this->numShots = new QSpinBox();
    this->numShots->setReadOnly(true);
    this->numShots->setFixedWidth(40);
    this->numShots->setButtonSymbols(QSpinBox::ButtonSymbols::NoButtons);
    hbox->addWidget(this->numShots);

    hbox->addWidget(new QLabel("Speed"));
    this->speedSlider = new QSlider(Qt::Orientation::Horizontal);
    hbox->addWidget(this->speedSlider);
    this->speedOutput = new QSpinBox();
    this->speedOutput->setReadOnly(true);
    this->speedOutput->setFixedWidth(40);
    this->speedOutput->setButtonSymbols(QSpinBox::ButtonSymbols::NoButtons);
    hbox->addWidget(this->speedOutput);

    hbox->addWidget(new QLabel("Angle"));
    this->angleSlider = new QSlider(Qt::Orientation::Horizontal);
    hbox->addWidget(this->angleSlider);
    this->angleOutput = new QSpinBox();
    this->angleOutput->setReadOnly(true);
    this->angleOutput->setFixedWidth(40);
    this->angleOutput->setButtonSymbols(QSpinBox::ButtonSymbols::NoButtons);
    hbox->addWidget(this->angleOutput);


    vbox->addLayout(hbox);

    this->setLayout(vbox);
}

void GameWidget::connectObjects() {
    QObject::connect(this->speedSlider, &QSlider::valueChanged, this->speedOutput, &QSpinBox::setValue);
    QObject::connect(this->angleSlider, &QSlider::valueChanged, this->angleOutput, &QSpinBox::setValue);
}
