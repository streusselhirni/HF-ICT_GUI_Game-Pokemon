#include <QApplication>
#include "GameWindow.h"

int main(int argc, char** argv)
{
    QApplication a(argc, argv);
    GameWindow gw;
    gw.show();

    return a.exec();
}