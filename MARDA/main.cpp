#include "mainviewcardgames.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainViewCardGames menuJuegos;
    menuJuegos.show();
    return a.exec();
}
