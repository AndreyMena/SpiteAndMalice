#ifndef PILACENTRAL_H
#define PILACENTRAL_H

#include <vector>

using namespace std;

#include "carta.h"
#include "pilaabstracta.h"
#include "mazo.h"

class PilaCentral : public PilaAbstracta
{
public:
    PilaCentral(Mazo *mazoCentral);
    ~PilaCentral();
    bool agregarCarta(Carta carta) override;
private:
    vector<Carta> sacarCartas();
    Mazo *mazoCentral;
};

#endif // PILACENTRAL_H
