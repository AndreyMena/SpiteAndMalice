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

    /**
     * @brief Agrega una carta a la pila central y maneja las acciones que eso
     * conlleva
     * @param carta
     * @return
     */
    bool agregarCarta(Carta carta) override;

    /**
     * @brief Revisa si la pila está completa para liberarla
     * @return
     */
    bool estaCompleta();

private:
    /**
     * @brief Saca cartas de la pila central
     * @return
     */
    vector<Carta> sacarCartas();
    Mazo *mazoCentral;
    bool pilaCompleta;
};

#endif // PILACENTRAL_H
