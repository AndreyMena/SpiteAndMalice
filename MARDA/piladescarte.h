#ifndef PILADESCARTE_H
#define PILADESCARTE_H

#include "pilaabstracta.h"

#include <iostream>

class PilaDescarte : public PilaAbstracta
{
public:
    /**
     * @brief Constructor de PilaDescarte
     */
    PilaDescarte();

    /**
     * @brief Destructor de PilaDescarte
     */
    ~PilaDescarte();

    /**
     * @brief Agrega cartas a la pila de descarte y maneja las acciones que eso
     * conlleva
     * @param carta
     * @return
     */
    bool agregarCarta(Carta carta) override;
};

#endif // PILADESCARTE_H
