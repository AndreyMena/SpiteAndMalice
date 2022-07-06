#ifndef PILAABSTRACTA_H
#define PILAABSTRACTA_H

#include <stack>

using namespace std;

#include "carta.h"

class PilaAbstracta
{
public:
    PilaAbstracta();
    ~PilaAbstracta();
    virtual bool agregarCarta(Carta carta) = 0;
protected:
    stack<Carta> cartas;
};

#endif // PILAABSTRACTA_H
