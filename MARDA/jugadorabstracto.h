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

  JugadorAbstracto(string nombre, vector<Carta> *mano, int puntaje);
  /**
   * @brief Destructor de la clase JugadorAbstracto
   */
  ~JugadorAbstracto();

  string obtenerNombre();

  int obtenerPuntaje();

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

  virtual void rellenarMano() = 0;

protected:
  string nombre;
  vector<Carta> *mano;
  int puntaje;
  /**
   * @brief mano Cartas que el jugador tiene en la mano
   */
};

#endif // JUGADORABSTRACTO_H
