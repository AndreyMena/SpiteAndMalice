#ifndef TABLERO_H
#define TABLERO_H

#include <vector>

using namespace std;

#include "jugador.h"
#include "mazo.h"
#include "pilacentral.h"

class Tablero
{
public:
    const int CANTIDAD_PILAS_CENTRALES = 3;
    /**
     * @brief Tablero Constructor de la clase Tablero
     */
    Tablero(int cantidadJugadores);
    Tablero(Mazo* mazoCentral, vector<PilaCentral>* pilasCentrales,int turnoJugador, vector<Jugador*> jugadores);

    /**
     * @brief Destructor de la clase Tablero
     */
    ~Tablero();

    /**
     * @brief Asigna el turno a un jugador
     * @param numeroJugador
     */
    void asignarTurno(int numeroJugador);

    /**
     * @brief Indica si es el turno de un jugador o del otro
     * @param numeroJugador
     * @return
     */
    bool esTurnoJugador(int numeroJugador);

    /**
     * @brief Devuelve el jugador actual en turno
     * @param numeroJugador
     * @return
     */
    Jugador* obtenerJugador(int numeroJugador);

    /**
     * @brief Devuelve un vector con los jugadores actuales
     * @return
     */
    vector<Jugador*>& obtenerJugadores();

    /**
     * @brief Devuelve el mazo central del tablero
     * @return
     */
    Mazo* obtenerMazoCentral();

    /**
     * @brief Devuelve la pila central del tablero
     * @param posicion
     * @return
     */
    PilaCentral& obtenerPilaCentral(int posicion);

private:
    vector<Jugador*> jugadores;
    int turnoJugador;
    Mazo *mazoCentral;
    vector<PilaCentral>* pilasCentrales;
};

#endif // TABLERO_H


