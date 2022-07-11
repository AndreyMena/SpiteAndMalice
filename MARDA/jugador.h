#ifndef JUGADOR_H
#define JUGADOR_H

#include "carta.h"
#include "mazo.h"
#include "piladescarte.h"
#include "pilacentral.h"

class Jugador
{
public:
    const int TIPO_PILA_DESCARTE = 0;
    const int TIPO_PILA_CENTRAL = 1;
    const int CANTIDAD_PILAS_DESCARTE = 4;
    /**
     * @brief Constructor de la clase Jugador
     */
    Jugador(int numeroJugador, Mazo *mazoCentral, vector<PilaCentral>* pilasCentrales);

    Jugador(int numeroJugadorAux, Mazo *mazoCentral, vector<PilaCentral>* pilasCentralesAux, vector<Carta> *manoAux, Mazo mazoAux, vector<PilaDescarte*> PilasdeDescarteAux);
    /**
     * @brief Destructor de la clase Jugador
     */
    ~Jugador();

    int obtenerNumeroJugador();

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

    bool agregarCartaPila(Carta carta, int tipoPila, int posicion);

    void rellenarMano();

    Mazo obtenerMazoPersonal();

    vector<Carta>* obtenerMano();

    PilaDescarte* obtenerPilaDescarte(int posicion);
private:
    int numeroJugador;
    /**
     * @brief mazo Mazo que corresponde al jugador
     */
    Mazo mazo;
    /**
     * @brief mano Cartas que el jugador tiene en la mano
     */
    vector<Carta> *mano;
    /**
     * @brief mazoCentral Mazo que corresponde al mazo central del tablero
     */
    Mazo *mazoCentral;
    /**
     * @brief pilasDescarte Pilas donde el jugador puede descartar las cartas que no quiera usar
     */
    vector<PilaCentral>* pilasCentrales;
    /**
     * @brief pilasDescarte Pilas donde el jugador puede descartar las cartas que no quiera usar
     */
    vector<PilaDescarte*> pilasDescarte;
};

#endif // JUGADOR_H
