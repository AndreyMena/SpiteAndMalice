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
  /**
   * @brief Jugador Constructor de la clase jugador
   * @param numeroJugador numero de jugador que se le asignara al nuevo jugador
   * @param mazoCentral una referencia al mazo central para que pueda acceder al mismo
   * @param pilasCentrales una referencia al vector que contiene las pilas centrales para poder acceder a las mismas
   */
  Jugador(int numeroJugador, Mazo *mazoCentral,
          vector<PilaCentral> *pilasCentrales);

  /**
   * @brief Jugador Constructor de la clase jugador
   * @param numeroJugadorAux numero de jugador que se le asignara al jugador creado
   * @param mazoCentral el mazo central del juego al cual el jugador tendra acceso
   * @param pilasCentralesAux un vector con las pilas centrales del juego a las cuales ambos jugadores acceden
   * @param manoAux la mano del jugador creado
   * @param mazoAux el mazo personal del jugador creado
   * @param PilasdeDescarteAux un vector que contiene las pilas de descarte del jugador creado
   */
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
   * @return retorna el numero entero que identifica al jugador
   */
  int obtenerNumeroJugador();

  /**
   * @brief Agrega una carta a la pila que se le indique
   * @param carta la carte que se agregara a la pila
   * @param tipoPila el tipo de pila a la que se le agregara la carta
   * @param posicion posicion donde se insertara la carta dentro de la pila
   * @return retorna un booleano con el resultado de la accion
   */
  bool agregarCartaPila(Carta carta, int tipoPila, int posicion);

  /**
   * @brief Rellena el mazo con cartas en orden aleatorio
   */
  void rellenarMano() override;

  /**
   * @brief Se obtiene un mazo personal para cada jugador
   * @return devuelve el mazo personal del jugador
   */
  Mazo obtenerMazoPersonal();

  /**
   * @brief Devuelve el contenido de una determinada pila de descarte
   * @param posicion posicion de la pila de descarte que se desea obtener
   * @return
   */
  PilaDescarte *obtenerPilaDescarte(int posicion);

  /**
   * @brief seDescartoCarta devuelve si la carta que se jugó fue hacia una pila de descarte
   * @return retorna el valor de cartaJugadaPilaDescarte, quien contiene si la carta que se jugó fue descartada
   */
  bool seDescartoCarta();
private:

  /**
   * @brief cartaJugadaPilaDescarte Denota si la carta que se jugó, fue hacia una pila de descarte
   */
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
