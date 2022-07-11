#include "pilaabstracta.h"

PilaAbstracta::PilaAbstracta()
{

}

PilaAbstracta::~PilaAbstracta()
{

}


stack<Carta> PilaAbstracta::obtenerCartas() {
    return this->cartas;
}
