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
     * @brief agregarCartasMazo Agrega el vector de cartas al mazo actual
     * @param cartas Cartas a insertar en el mazo
     * @return No devuelve nada
     */
    void agregarCartasMazo(vector<Carta> cartas);
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
    vector<string> numerosCarta{"ace", "2", "3", "4", "5", "6",
                                "7", "8", "9", "10", "jack", "queen", "king"};
    vector<string> simbolosCarta{"_of_hearts", "_of_diamonds", "_of_clubs", "_of_spades"};
};
