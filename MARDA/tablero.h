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
    /**
     * @brief Destructor de la clase Tablero
     */
    ~Tablero();

    void asignarTurno(int numeroJugador);

    bool esTurnoJugador(int numeroJugador);

    vector<Jugador> obtenerJugadores();

    Mazo& obtenerMazo();

private:
    vector<Jugador> jugadores;
    int turnoJugador;
    Mazo mazoCentral;
    vector<PilaCentral> pilasCentrales;
};

#endif // TABLERO_H
