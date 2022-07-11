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
    bool estaCompleta();
private:
    vector<Carta> sacarCartas();
    Mazo *mazoCentral;
    bool pilaCompleta;
};

#endif // PILACENTRAL_H
