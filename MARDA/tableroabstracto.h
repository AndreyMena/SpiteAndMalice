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
     * @param turnoJugador un entero para turno del jugador
     * @param jugadores un vector con los jugadores Abstractos
     */
    TableroAbstracto(int turnoJugador, vector<JugadorAbstracto*> jugadores);

    /**
     * @brief Contructor de tablero abstracto con mazoCentral
     * @param turnoJugador entero para turno jugador
     * @param jugadores  un vector con los jugadores Abstractos
     * @param mazoCentral Mazo central abstracto del tablero
     */
    TableroAbstracto(int turnoJugador, vector<JugadorAbstracto*> jugadores, MazoAbstracto* mazoCentral);

    /**
     * @brief Destructor de la clase TableroAbstracto
     */
    ~TableroAbstracto();

    /**
     * @brief Asigna el turno a un jugador
     * @param numeroJugador un entero para turno del jugador
     */
    void asignarTurno(int numeroJugador);

    /**
     * @brief Indica si es el turno de un jugador o del otro
     * @param numeroJugador un entero para turno del jugador
     * @return bool define si es el turno del jugador.
     */
    bool esTurnoJugador(int numeroJugador);

    /**
     * @brief Devuelve el jugador actual en turno
     * @param numeroJugador un entero para turno del jugador
     * @return JugadorAbstracto* retorna el jugador de acuerdo a su numero
     */
    JugadorAbstracto* obtenerJugador(int numeroJugador);

    /**
     * @brief Devuelve un vector con los jugadores actuales
     * @return vector<JugadorAbstracto*>& un vector de los Jugadores del tablero.
     */
    vector<JugadorAbstracto*>& obtenerJugadores();

    /**
     * @brief Devuelve el mazo central del tablero
     * @return MazoAbstracto* el mazo central del tablero
     */
    MazoAbstracto* obtenerMazoCentral();

    /**
     * @brief Metodo para realizar una jugada.
     * @param jugador el jugador que realizara la jugada
     * @param posicionCartaMano entero que refleja la posicion de la carta en la mano
     * @return No devuelve nada
     */
    void hacerJugada(JugadorAbstracto* jugador, int posicionCartaMano);

    /**
     * @brief Metodo para jugar Carta
     * @param jugador el jugador que realizara la jugada
     * @param posicionCartaMano
     * @return No devuelve nada
     */
    virtual void jugarCarta(JugadorAbstracto* jugador, int posicionCartaMano) = 0;

    /**
     * @brief Metodo para cambiar turno.
     * @param jugador el jugador que cambiara de turno
     * @return No devuelve nada
     */
    virtual void cambiarTurno(JugadorAbstracto* jugador) = 0;

    /**
     * @brief Metodo para verificar ganador
     * @param jugador el jugador que se verificara si es ganador
     * @return No devuelve nada
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
