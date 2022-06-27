#ifndef JUGADOR_H
#define JUGADOR_H

#include "carta.h"
#include "mazo.h"

class Jugador
{
public:
    Jugador();
    ~Jugador();
private:
    Mazo mazo;
    vector<Carta> mano;
};

#endif // JUGADOR_H
