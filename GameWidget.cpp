#include <QHBoxLayout>
#include <QLabel>
#include "GameWidget.h"
#include "GameArea.h"
#include <QDebug>
#include <QSound>
#include <QMessageBox>
#include <QKeyEvent>
#include <utility>

GameWidget::~GameWidget() {}

GameWidget::GameWidget(QWidget *parent, int w, int h) : QWidget(parent), width(w), height(h) {
    this->gameArea = new GameArea(this, this->width, this->height - 100);
    this->currentState = GameWidget::MENU;
    this->lastPushTime = 0;

    this->setFocusPolicy(Qt::FocusPolicy::StrongFocus);

    this->createObjects();
    this->createLayout();
    this->connectObjects();
}

void GameWidget::createObjects() {
    this->actionButton = new QPushButton("Start");

    this->numShots = new QSpinBox();
    this->numShots->setReadOnly(true);
    this->numShots->setFixedWidth(40);
    this->numShots->setMaximum(1000);
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
    QObject::connect(this->speedSlider, &QSlider::valueChanged, this->gameArea, &GameArea::strengthChanged);
    QObject::connect(this->angleSlider, &QSlider::valueChanged, this->angleOutput, &QSpinBox::setValue);
    QObject::connect(this->angleSlider, &QSlider::valueChanged, this->gameArea, &GameArea::angleChanged);
    QObject::connect(this->actionButton, &QPushButton::clicked, this, &GameWidget::actionButtonClicked);
    QObject::connect(this, &GameWidget::shoot, this->gameArea, &GameArea::shoot);
    QObject::connect(this->gameArea, &GameArea::gameFinished, this, &GameWidget::onGameFinished);
    QObject::connect(this->gameArea, &GameArea::gameFinished, this, &GameWidget::reset);
    QObject::connect(this->gameArea, &GameArea::gameFinished, this->gameArea, &GameArea::endGame);
}

void GameWidget::actionButtonClicked() {
    if (this->isInteractable()) {
        // Shoot cooldown
        auto newMeasure = this->gameArea->measure();
        if (newMeasure - this->lastPushTime > 1300) {
            this->numShots->setValue(this->numShots->value() + 1);
            emit this->shoot(this->speedOutput->value(), this->angleOutput->value());
            this->lastPushTime = newMeasure;
        }
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

void GameWidget::onGameFinished() {
    if (this->isInteractable()) {
        this->currentState |= GameWidget::MENU;
        QSound::play("sound/win.wav");
        QMessageBox::information(this, tr("Your score!"),
                                 QString("It took you %1 shots to hit the obstacle").arg(this->numShots->text()));
    }
}

void GameWidget::reset() {
    this->numShots->setValue(0);
    this->speedSlider->setValue(0);
    this->angleSlider->setValue(0);
    this->actionButton->setText("Start");
    this->currentState = GameWidget::MENU;
}

void GameWidget::keyPressEvent(QKeyEvent *event) {
    if (this->pressedKeys[static_cast<const Qt::Key>(event->key())] == RELEASED) {
        this->pressedKeys[static_cast<const Qt::Key>(event->key())] = PRESSED;
    } else if (this->pressedKeys[static_cast<const Qt::Key>(event->key())] == PRESSED ) {
        this->pressedKeys[static_cast<const Qt::Key>(event->key())] = HOLD;
    }
}

void GameWidget::keyReleaseEvent(QKeyEvent *event) {
    this->pressedKeys[static_cast<const Qt::Key>(event->key())] = RELEASED;
}

void GameWidget::paintEvent(QPaintEvent *event) {
    QWidget::paintEvent(event);
    if (this->pressedKeys[(Qt::Key_Left)] == PRESSED || this->pressedKeys[(Qt::Key_Left)] == HOLD) {
        this->angleSlider->setValue(this->angleSlider->value() + 1);
    }
    if (this->pressedKeys[(Qt::Key_Right)] == PRESSED || this->pressedKeys[(Qt::Key_Right)] == HOLD) {
        this->angleSlider->setValue(this->angleSlider->value() - 1);
    }
    if (this->pressedKeys[(Qt::Key_Up)] == PRESSED || this->pressedKeys[(Qt::Key_Up)] == HOLD){
        this->speedSlider->setValue(this->speedSlider->value() + 1);
    }
    if (this->pressedKeys[(Qt::Key_Down)] == PRESSED || this->pressedKeys[(Qt::Key_Down)] == HOLD) {
        this->speedSlider->setValue(this->speedSlider->value() - 1);
    }
    if (this->pressedKeys[(Qt::Key_Space)] == PRESSED) {
        this->actionButtonClicked();
        this->pressedKeys[(Qt::Key_Space)] = HOLD;
    }
}
