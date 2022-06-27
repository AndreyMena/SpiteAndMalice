#include "menujuego.h"
#include "mazo.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MenuJuego w;
    w.show();

    return a.exec();
}
