#ifndef PILADESCARTE_H
#define PILADESCARTE_H

#include "pilaabstracta.h"

class PilaDescarte : public PilaAbstracta
{
public:
    PilaDescarte();
    ~PilaDescarte();
    bool agregarCarta(Carta carta) override;
};

#endif // PILADESCARTE_H
