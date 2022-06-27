#ifndef JUGADOR_H
#define JUGADOR_H

#include "carta.h"
#include "mazo.h"

class Jugador
{
public:
    /**
     * @brief Constructor de la clase Jugador
     */
    Jugador();
    /**
     * @brief Destructor de la clase Jugador
     */
    ~Jugador();
private:
    /**
     * @brief mazo Mazo que corresponde al jugador
     */
    Mazo mazo;
    /**
     * @brief mano Cartas que el jugador tiene en la mano
     */
    vector<Carta> mano;
};

#endif // JUGADOR_H
