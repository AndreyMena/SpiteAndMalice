#ifndef JUGADOR_H
#define JUGADOR_H

#include "carta.h"
#include "mazo.h"
#include "piladescarte.h"
#include "pilacentral.h"

class Jugador
{
public:
    const int CANTIDAD_PILAS_DESCARTE = 4;
    /**
     * @brief Constructor de la clase Jugador
     */
    Jugador(int numeroJugador, Mazo *mazoCentral, vector<PilaCentral> *pilasCentrales);
    /**
     * @brief Destructor de la clase Jugador
     */
    ~Jugador();

    int obtenerNumeroJugador();

    vector<Carta> obtenerMano();
private:
    int numeroJugador;
    /**
     * @brief mazo Mazo que corresponde al jugador
     */
    Mazo mazo;
    /**
     * @brief mano Cartas que el jugador tiene en la mano
     */
    vector<Carta> mano;
    /**
     * @brief mazoCentral Mazo que corresponde al mazo central del tablero
     */
    Mazo *mazoCentral;
    /**
     * @brief pilasDescarte Pilas donde el jugador puede descartar las cartas que no quiera usar
     */
    vector<PilaCentral> *pilasCentrales;
    /**
     * @brief pilasDescarte Pilas donde el jugador puede descartar las cartas que no quiera usar
     */
    vector<PilaDescarte> pilasDescarte;
};

#endif // JUGADOR_H
