#include "piladescarte.h"

PilaDescarte::PilaDescarte()
{

}

PilaDescarte::~PilaDescarte()
{

}

bool PilaDescarte::agregarCarta(Carta carta) {
    cout << "Carta: " << carta.obtenerNombre() << " " <<  carta.obtenerValor() << endl;
    this->cartas.push(carta);
    return true;
}
