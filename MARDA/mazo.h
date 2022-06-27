#pragma once

#include <algorithm>
#include <exception>
#include <vector>
#include <random>
#include <chrono>
using namespace std;

#include "carta.h"

class Mazo {

public:
    /**
     * @brief Mazo Constructor de la clase
     */
    Mazo();
    /**
     * @brief Destructor de la clase Mazo
     */
    ~Mazo();
    /**
     * @brief llenarMazo Asigna al mazo las 52 cartas correspodientes de la baraja francesa y las baraja
     */
    void llenarMazo();
    /**
     * @brief barajarMazo Baraja el mazo de manera aleatoria
     */
    void barajarMazo();
    /**
     * @brief dividirMazo Separa la cantidad de cartas indicadas del mazo
     * @param cantidadCartas Cantidad de cartas que se quieren separar
     * @return Devuelve un mazo con las cartas extraidas
     */
    Mazo dividirMazo(unsigned int cantidadCartas);
    /**
     * @brief obtenerCartasMazo Devuelve las cartas que contiene el mazo
     * @return Devuelve un vector que contiene las cartas del mazo
     */
    vector<Carta> obtenerCartasMazo();
private:
    /**
     * @brief cartas Un vector con las cartas que contiene el mazo
     */
    vector<Carta> cartas;
    vector<string> numerosCarta{"As", "Dos", "Tres", "Cuatro", "Cinco", "Seis",
                                "Siete", "Ocho", "Nueve", "Diez", "J", "Q", "K"};
    vector<string> simbolosCarta{" de corazones", " de diamantes", " de treboles", " de picas"};
};
