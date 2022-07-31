#ifndef PILAABSTRACTA_H
#define PILAABSTRACTA_H

#include <stack>

using namespace std;

#include "carta.h"

class PilaAbstracta
{
public:
    PilaAbstracta();
    ~PilaAbstracta();

    /**
     * @brief Agrega una carta a la pila
     * @param carta
     * @return
     */
    virtual bool agregarCarta(Carta carta) = 0;

    /**
     * @brief Obtiene la carta de la pila indicada
     * @return
     */
    stack<Carta> obtenerCartas();

protected:
    /**
     * @brief pila de cartas
     */
    stack<Carta> cartas;
};

#endif // PILAABSTRACTA_H
