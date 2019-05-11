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

    auto title = new QLabel("Harambe");
    title->setMaximumHeight(50);
    vbox->addWidget(title);

    vbox->addWidget(this->gameArea);

    auto hbox = new QHBoxLayout();
    hbox->addWidget(new QLabel("Test"));
    hbox->addWidget(new QLabel("Test"));
    vbox->addLayout(hbox);

    this->setLayout(vbox);
}

void GameWidget::connectObjects() {

}
