#pragma once

#include <exception>
#include <vector>

using namespace std;

#include "carta.h"
#include "mazoabstracto.h"

class Mazo : public MazoAbstracto {

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
     * @brief llenarMazo Asigna al mazo las 52 cartas correspodientes de la
     * baraja francesa y las baraja
     */
    void llenarMazo() override;

    /**
     * @brief agregarCartaMazo Agrega una carta al mazo actual
     * @param carta Carta a insertar en el mazo
     * @param posicion Posicion a insertar la carta
     * @return No devuelve nada
     */
    void agregarCartaMazo(Carta carta, int posicion);

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

private:
    vector<string> numerosCarta{"ace", "2", "3", "4", "5", "6", "7", "8", "9",
                                "10", "jack", "queen", "king"};
    vector<string> simbolosCarta{"_of_hearts", "_of_diamonds", "_of_clubs",
                                 "_of_spades"};
};
