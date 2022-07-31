#ifndef JUGADORABSTRACTO_H
#define JUGADORABSTRACTO_H

#include <string>
#include <vector>

using namespace std;

#include "carta.h"

class JugadorAbstracto {
public:
  /**
   * @brief Tablero Constructor de la clase JugadorAbstracto
   */
  JugadorAbstracto();


  /**
   * @brief JugadorAbstracto
   * @param nombre Nombre deseado del jugador
   * @param mano Mano asignada al jugador
   * @param puntaje Entero que denota el puntaje del jugador en la partida
   */
  JugadorAbstracto(string nombre, vector<Carta> *mano, int puntaje);
  /**
   * @brief Destructor de la clase JugadorAbstracto
   */
  ~JugadorAbstracto();

  /**
   * @brief obtenerNombre Obtiene el nombre del jugador
   * @return Retorna un String con el nombre del jugador
   */
  string obtenerNombre();

  /**
   * @brief obtenerPuntaje Obtiene el puntaje del jugador
   * @return Devuelve un entero con el puntaje del jugador
   */
  int obtenerPuntaje();

  /**
   * @brief asignarPuntaje Asigna un puntaje al jugador
   * @param puntaje Un entero con la cantidad de puntos que se desean asignar
   */
  void asignarPuntaje(int puntaje);
  /**
   * @brief Genera la mano del jugador
   * @return Devuelve un vector con las cartas del jugador
   */
  vector<Carta> *obtenerMano();

  /**
   * @brief sacarCartaMano Saca una carta de la mano
   * @param posicion Posicion de la carta a sacar
   * @return Devuelve la carta sacada
   */
  Carta sacarCartaMano(int posicion);

  /**
   * @brief agregarCartaMano Agrega una carta a la mano
   * @param carta Carta a insertar en la mano
   * @param posicion Posicion a insertar la carta
   * @return No devuelve nada
   */
  void agregarCartaMano(Carta carta, int posicion);

  /**
   * @brief rellenarMano Rellena la mano del jugador
   */
  virtual void rellenarMano() = 0;

protected:
  /**
   * @brief nombre Nombre del jugador
   */
  string nombre;
  /**
   * @brief mano Un vector de cartas que conforman la mano del jugador
   */
  vector<Carta> *mano;
  /**
   * @brief puntaje Puntaje del jugador
   */
  int puntaje;
  /**
   * @brief mano Cartas que el jugador tiene en la mano
   */
};

#endif // JUGADORABSTRACTO_H
