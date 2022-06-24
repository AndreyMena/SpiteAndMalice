#pragma once

#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>
#include <fstream>

class mazo {

public:
    int numeroAleatorio();
    void crearMazo();
    void inicializaArregloAuxiliar();
    void mazoCreado();
    void llenarMazos();
    void IniciarCartas();
    std::string obtenerCartaJugadorUno();

    int const CANTIDAD_DE_SIMBOLOS = 4;
    int const CANTIDAD_CARTAS_POR_MAZO =52;
    int const NUMEROS_EN_MAZO = 13;

    std::string numerosMazo[13] = {"As", "Dos", "Tres", "Cuatro", "Cinco", "Seis", "Siete", "Ocho", "Nueve",
                                   "Diez", "J", "Q", "K"};
    std::string simbolosDeCartas[4] = {" de corazones", " de diamantes", " de treboles", " de espadas"};
    std::string mazoJugadorUno[52];
    std::string mazoJugadorDos[52];
    bool mazoAuxiliar[52];

private:
    std::stack<std::string> mazoJugadorUnoFinal;
    std::stack<std::string> mazoJugadorDosFinal;
    std::vector<std::string> mazoJugadorUnoVector;
    //std::vector<std::string> mazoJugadorDosFinal;
};
