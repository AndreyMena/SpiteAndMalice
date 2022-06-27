#ifndef TABLERO_H
#define TABLERO_H

#include "jugador.h"

class Tablero
{
public:
    /**
     * @brief Tablero Constructor de la clase Tablero
     */
    Tablero();
    /**
     * @brief Destructor de la clase Tablero
     */
    ~Tablero();
private:
    Jugador jugador1;
    Jugador jugador2;
};

#endif // TABLERO_H
