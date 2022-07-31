#ifndef TABLERO_H
#define TABLERO_H

#include <vector>

using namespace std;

#include "jugador.h"
#include "mazo.h"
#include "pilacentral.h"
#include "tableroabstracto.h"
class Tablero : public TableroAbstracto
{
public:
    const int CANTIDAD_PILAS_CENTRALES = 3;
    /**
     * @brief Tablero Constructores de la clase Tablero
     */
    Tablero(int cantidadJugadores);
    Tablero(vector<PilaCentral>* pilasCentrales,int turnoJugador, vector<JugadorAbstracto*> jugadores);
    Tablero(MazoAbstracto* mazoCentral, vector<PilaCentral>* pilasCentrales,int turnoJugador, vector<JugadorAbstracto*> jugadores);

    /**
     * @brief Destructor de la clase Tablero
     */
    ~Tablero();

    /**
     * @brief Devuelve la pila central del tablero
     * @param posicion
     * @return
     */
    PilaCentral& obtenerPilaCentral(int posicion);

    void jugarCarta(JugadorAbstracto* jugador, int posicionCartaMano) override;

    void cambiarTurno(JugadorAbstracto* jugador) override;

    void verificarGanador(JugadorAbstracto* jugador) override;

private:

    /**
     * @brief pilasCentrales Almacena las pilas centrales creadas.
     */
    vector<PilaCentral>* pilasCentrales;
};

#endif // TABLERO_H
