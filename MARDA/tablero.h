#ifndef TABLERO_H
#define TABLERO_H

#include "jugador.h"

class Tablero
{
public:
    Tablero();
    ~Tablero();
private:
    Jugador jugador1;
    Jugador jugador2;
};

#endif // TABLERO_H
