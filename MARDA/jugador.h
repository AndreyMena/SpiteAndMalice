#ifndef JUGADOR_H
#define JUGADOR_H

#include "carta.h"
#include "jugadorabstracto.h"
#include "mazo.h"
#include "pilacentral.h"
#include "piladescarte.h"

class Jugador : public JugadorAbstracto {
public:
  const int TIPO_PILA_DESCARTE = 0;
  const int TIPO_PILA_CENTRAL = 1;
  const int CANTIDAD_PILAS_DESCARTE = 4;

  /**
   * @brief Constructores de la clase Jugador
   */
  Jugador(int numeroJugador, Mazo *mazoCentral,
          vector<PilaCentral> *pilasCentrales);

  Jugador(int numeroJugadorAux, Mazo *mazoCentral,
          vector<PilaCentral> *pilasCentralesAux, vector<Carta> *manoAux,
          Mazo mazoAux, vector<PilaDescarte *> PilasdeDescarteAux);

  /**
   * @brief Destructor de la clase Jugador
   */
  ~Jugador();

  /**
   * @brief obtenerNumeroJugador Devuelve un entero con el número que
   * identifica a un jugador
   * @return
   */
  int obtenerNumeroJugador();

  /**
   * @brief Agrega una carta a la pila que se le indique
   * @param carta
   * @param tipoPila
   * @param posicion
   * @return
   */
  bool agregarCartaPila(Carta carta, int tipoPila, int posicion);

  /**
   * @brief Rellena el mazo con cartas en orden aleatorio
   */
  void rellenarMano() override;

  /**
   * @brief Se obtiene un mazo personal para cada jugador
   * @return
   */
  Mazo obtenerMazoPersonal();

  /**
   * @brief Devuelve el contenido de una determinada pila de descarte
   * @param posicion
   * @return
   */
  PilaDescarte *obtenerPilaDescarte(int posicion);

  bool seDescartoCarta();
private:

  bool cartaJugadaPilaDescarte;
  /**
   * @brief numeroJugador Identificador único de cada jugador
   */
  int numeroJugador;

  /**
   * @brief mazo Mazo que corresponde al jugador
   */
  Mazo mazo;

  /**
   * @brief mazoCentral Mazo que corresponde al mazo central del tablero
   */
  Mazo *mazoCentral;

  /**
   * @brief pilasDescarte Pilas donde el jugador puede descartar las cartas
   * que no quiera usar
   */
  vector<PilaCentral> *pilasCentrales;

  /**
   * @brief pilasDescarte Pilas donde el jugador puede descartar las cartas
   * que no quiera usar
   */
  vector<PilaDescarte *> pilasDescarte;
};

#endif // JUGADOR_H
