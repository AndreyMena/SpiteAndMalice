#ifndef TABLEROABSTRACTO_H
#define TABLEROABSTRACTO_H

#include <vector>

using namespace std;

#include "jugadorabstracto.h"
#include "mazoabstracto.h"

class TableroAbstracto
{
public:
    TableroAbstracto();

    /**
     * @brief Contructor de tablero abstracto
     * @param turnoJugador
     * @param jugadores
     */
    TableroAbstracto(int turnoJugador, vector<JugadorAbstracto*> jugadores);

    /**
     * @brief Contructor de tablero abstracto con mazoCentral
     * @param turnoJugador
     * @param jugadores
     * @param mazoCentral
     */
    TableroAbstracto(int turnoJugador, vector<JugadorAbstracto*> jugadores, MazoAbstracto* mazoCentral);

    /**
     * @brief Destructor de la clase TableroAbstracto
     */
    ~TableroAbstracto();

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
    JugadorAbstracto* obtenerJugador(int numeroJugador);

    /**
     * @brief Devuelve un vector con los jugadores actuales
     * @return
     */
    vector<JugadorAbstracto*>& obtenerJugadores();

    /**
     * @brief Devuelve el mazo central del tablero
     * @return
     */
    MazoAbstracto* obtenerMazoCentral();

    /**
     * @brief Metodo para realizar una jugada.
     * @param jugador
     * @param posicionCartaMano
     * @return void
     */
    void hacerJugada(JugadorAbstracto* jugador, int posicionCartaMano);

    /**
     * @brief Metodo para jugar Carta
     * @param jugador
     * @param posicionCartaMano
     * @return void
     */
    virtual void jugarCarta(JugadorAbstracto* jugador, int posicionCartaMano) = 0;

    /**
     * @brief Metodo para cambiar turno.
     * @param jugador
     * @return void
     */
    virtual void cambiarTurno(JugadorAbstracto* jugador) = 0;

    /**
     * @brief Metodo para verificar ganador
     * @param jugador
     * @return void
     */
    virtual void verificarGanador(JugadorAbstracto* jugador) = 0;

protected:
    /**
   * @brief jugadores Vector que contiene los jugadores de la partida
   */
  vector<JugadorAbstracto*> jugadores;

  /**
   * @brief turnoJugador Almacena el turno de un jugador
   */
  int turnoJugador;

  /**
   * @brief mazo Instancia un nuevo Mazo Abstracto
   */
  MazoAbstracto* mazoCentral;
};

#endif // TABLEROABSTRACTO_
