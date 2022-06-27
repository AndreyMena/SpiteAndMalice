#pragma once

#include <algorithm>
#include <vector>
#include <exception>
using namespace std;

#include "carta.h"

class Mazo {

public:
    Mazo();
    ~Mazo();
    void llenarMazo();
    void barajarMazo();
    Mazo dividirMazo(unsigned int cantidadCartas);
    vector<Carta> obtenerCartasMazo();
private:
    vector<Carta> cartas;
    vector<string> numerosCarta{"As", "Dos", "Tres", "Cuatro", "Cinco", "Seis",
                                "Siete", "Ocho", "Nueve", "Diez", "J", "Q", "K"};
    vector<string> simbolosCarta{" de corazones", " de diamantes", " de treboles", " de picas"};
};
