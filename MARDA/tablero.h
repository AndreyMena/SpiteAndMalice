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
     * @param pilasCentrales vector de las pilas centrales del tablero.
     * @param turnoJugador entero que define el turno de jugador
     * @param jugadores vector de jugadores del tablero
     */
    Tablero(vector<PilaCentral>* pilasCentrales,int turnoJugador, vector<JugadorAbstracto*> jugadores);

    /**
     * @brief Contructor de tablero para cargar partida.
     * @param MazoAbstracto* MazoAbstracto
     * @param pilasCentrales vector de pilas centrales del tablero
     * @param turnoJugador entero que define el turno de jugador
     * @param jugadores vector de jugadores del tablero
     */
    Tablero(MazoAbstracto* mazoCentral, vector<PilaCentral>* pilasCentrales,int turnoJugador, vector<JugadorAbstracto*> jugadores);

    /**
     * @brief Destructor de la clase Tablero
     */
    ~Tablero();

    /**
     * @brief Devuelve la pila central del tablero
     * @param posicion entero para la posicion de la pila.
     * @return PilaCentral pila central del tablero.
     */
    PilaCentral& obtenerPilaCentral(int posicion);

    /**
     * @brief Metodo plantilla para jugar una carta
     * @param jugador Jugador abstracto que jugara la carta.
     * @param posicionCartaMano entero que refleja la posicion de la carta en la mano.
     * @return void
     */
    void jugarCarta(JugadorAbstracto* jugador, int posicionCartaMano) override;

    /**
     * @brief Metodo para cambiar el turno de un jugador a otro.
     * @param jugador Jugador abstracto que cambiara de turno
     * @return void
     */
    void cambiarTurno(JugadorAbstracto* jugador) override;

    /**
     * @brief Metodo que verifica el ganador
     * @param jugador Jugador abstracto que se verificara si es ganador
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
