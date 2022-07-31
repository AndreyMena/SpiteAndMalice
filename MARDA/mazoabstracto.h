#ifndef MAZOABSTRACTO_H
#define MAZOABSTRACTO_H

#include <algorithm>
#include <random>
#include <chrono>
#include <vector>
using namespace std;

#include "carta.h"

class MazoAbstracto
{
public:
    /**
     * @brief Tablero Constructor de la clase MazoAbstracto
     */
    MazoAbstracto();

    /**
     * @brief Constructor de copias de la clase MazoAbstracto
     */
    MazoAbstracto(vector<Carta>* cartas);

    /**
     * @brief Destructor de la clase MazoAbstracto
     */
    ~MazoAbstracto();

    /**
     * @brief llenarMazo Asigna al mazo las 52 cartas correspodientes de la
     * baraja francesa y las baraja
     */
    virtual void llenarMazo() = 0;

    /**
     * @brief barajarMazo Baraja el mazo de manera aleatoria
     */
    void barajarMazo();

    /**
     * @brief sacarCartaMazo Saca una carta al mazo actual
     * @param posicion Posicion de la carta a sacar
     * @return Devuelve la carta sacada
     */
    Carta sacarCartaMazo(int posicion);

    /**
     * @brief obtenerCartasMazo Devuelve las cartas que contiene el mazo
     * @return Devuelve un vector que contiene las cartas del mazo
     */
    vector<Carta>* obtenerCartasMazo();

    /**
     * @brief obtenerTamanioMazo Devuelve la cantidad de cartas del mazo
     * @return Devuelve un entero que corresponde a la cantidad de cartas del
     * mazo
     */
    int obtenerTamanioMazo();

protected:
    /**
     * @brief cartas Un vector con las cartas que contiene el mazo
     */
    vector<Carta> *cartas;
};

#endif // MAZOABSTRACTO_H
