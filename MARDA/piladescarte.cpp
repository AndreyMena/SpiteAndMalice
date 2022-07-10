#include "piladescarte.h"

PilaDescarte::PilaDescarte()
{

}

PilaDescarte::~PilaDescarte()
{

}

bool PilaDescarte::agregarCarta(Carta carta) {
    this->cartas.push(carta);
    return true;
}
