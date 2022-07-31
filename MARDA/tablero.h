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

    /**
     * @brief Contructor de tablero especifico.
     * @param pilasCentrales
     * @param turnoJugador
     * @param jugadores
     */
    Tablero(vector<PilaCentral>* pilasCentrales,int turnoJugador, vector<JugadorAbstracto*> jugadores);

    /**
     * @brief Contructor de tablero para cargar partida.
     * @param pilasCentrales
     * @param turnoJugador
     * @param jugadores
     */
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

    /**
     * @brief Metodo plantilla para jugar una carta
     * @param jugador
     * @param posicionCartaMano
     * @return void
     */
    void jugarCarta(JugadorAbstracto* jugador, int posicionCartaMano) override;

    /**
     * @brief Metodo para cambiar el turno de un jugador a otro.
     * @param jugador
     * @return void
     */
    void cambiarTurno(JugadorAbstracto* jugador) override;

    /**
     * @brief Metodo que verifica el ganador
     * @param jugador
     * @return void
     */
    void verificarGanador(JugadorAbstracto* jugador) override;

private:

    /**
     * @brief pilasCentrales Almacena las pilas centrales creadas.
     */
    vector<PilaCentral>* pilasCentrales;
};

#endif // TABLERO_H
