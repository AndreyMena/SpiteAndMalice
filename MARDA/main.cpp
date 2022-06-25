#include "menujuego.h"
#include "mazo.h"

#include <QApplication>

/**
 * @brief Metodo principal de Marda.
 * @author Brayan Sandí Barrantes.
 * @author Carlos Cartín Cascante.
 * @author Bryan Villegas Alvarado.
 * @author Andrey Mena Espinoza.
 *
 * @param argc int
 * @param argv char**
 * @return int
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MenuJuego w;
    w.show();

    return a.exec();
}
