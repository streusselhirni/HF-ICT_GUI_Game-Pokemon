#include <QHBoxLayout>
#include <QLabel>
#include "GameWidget.h"
#include "GameArea.h"
#include <QDebug>

GameWidget::~GameWidget() {}

GameWidget::GameWidget(QWidget *parent, int w, int h) : QWidget(parent), width(w), height(h) {
    this->gameArea = new GameArea(this, this->width, this->height - 100);
    this->currentState = GameWidget::MENU;

    this->createObjects();
    this->createLayout();
    this->connectObjects();
}

void GameWidget::createObjects() {
    this->actionButton = new QPushButton("Start");

    this->numShots = new QSpinBox();
    this->numShots->setReadOnly(true);
    this->numShots->setFixedWidth(40);
    this->numShots->setButtonSymbols(QSpinBox::ButtonSymbols::NoButtons);

    this->speedSlider = new QSlider(Qt::Orientation::Horizontal);
    this->speedSlider->setMinimum(1);
    this->speedSlider->setMaximum(100);

    this->speedOutput = new QSpinBox();
    this->speedOutput->setReadOnly(true);
    this->speedOutput->setFixedWidth(40);
    this->speedOutput->setButtonSymbols(QSpinBox::ButtonSymbols::NoButtons);

    this->angleSlider = new QSlider(Qt::Orientation::Horizontal);
    this->angleSlider->setMinimum(0);
    this->angleSlider->setMaximum(90);

    this->angleOutput = new QSpinBox();
    this->angleOutput->setReadOnly(true);
    this->angleOutput->setFixedWidth(40);
    this->angleOutput->setButtonSymbols(QSpinBox::ButtonSymbols::NoButtons);
}

void GameWidget::createLayout() {
    auto vbox = new QVBoxLayout();

    auto title = new QLabel("<h1>Harambe</h1>");
    title->setMaximumHeight(50);
    vbox->addWidget(title);
    vbox->addWidget(this->gameArea);

    auto hbox = new QHBoxLayout();

    hbox->addWidget(this->actionButton);

    hbox->addWidget(new QLabel("Shot #"));
    hbox->addWidget(this->numShots);

    hbox->addWidget(new QLabel("Speed"));
    hbox->addWidget(this->speedSlider);
    hbox->addWidget(this->speedOutput);

    hbox->addWidget(new QLabel("Angle"));
    hbox->addWidget(this->angleSlider);
    hbox->addWidget(this->angleOutput);

    vbox->addLayout(hbox);

    this->setLayout(vbox);
}

void GameWidget::connectObjects() {
    QObject::connect(this->speedSlider, &QSlider::valueChanged, this->speedOutput, &QSpinBox::setValue);
    QObject::connect(this->angleSlider, &QSlider::valueChanged, this->angleOutput, &QSpinBox::setValue);
    QObject::connect(this->actionButton, &QPushButton::clicked, this, &GameWidget::actionButtonClicked);
}

void GameWidget::actionButtonClicked() {
    if (this->isInteractable()) {
        this->numShots->setValue(this->numShots->value() + 1);
        emit this->shoot(this->speedOutput->value(), this->angleOutput->value());
    } else {
        if (this->isRunning()) {
            this->actionButton->setText("Continue");
        } else {
            this->actionButton->setText("Shoot");
            this->gameArea->startGame();
        }
        this->currentState = GameWidget::RUNNING;
    }
}

/**
 * Returns true if the game is not in "Menu-Mode" (when you can play)
 * @return
 */
bool GameWidget::isInteractable() {
    return !(this->currentState & GameWidget::MENU);
}

/**
 * Returns true if the game has started and is playable right now
 * @return
 */
bool GameWidget::isRunning() {
    return this->currentState & GameWidget::RUNNING;
}
