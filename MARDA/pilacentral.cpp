#include "pilacentral.h"

PilaCentral::PilaCentral(Mazo *mazoCentral) :
    mazoCentral(mazoCentral),
    pilaCompleta(false)
{

}

PilaCentral::~PilaCentral()
{

}

bool PilaCentral::agregarCarta(Carta carta) {
    bool resultado = false;
   // Si la carta es -1 es porque es un comodin y puede sustituir cualquier cara
    // la otra opcion es que la carta que se quiere insertar sea 1 valor mas arriba de la que esta
    // en la parte superior de la pila e.g se quiere insertar un 2 encima de un AS
    // y por ultimo el caso final es que la carta a insertar sea un AS que es la que inicia las pilas
    if ((carta.obtenerValor() == 1 && this->cartas.empty())
       || (carta.obtenerValor() == -1 && this->cartas.empty())) {
        this->cartas.push(carta);
        resultado = true;
        this->pilaCompleta = false;
    } else {
        if (!this->cartas.empty()) {
            if (carta.obtenerValor() == -1 || carta.obtenerValor() == (int)this->cartas.size()+1) {
                if (this->cartas.size() == 11) {
                    this->cartas.push(carta);
                    this->mazoCentral->agregarCartasMazo(sacarCartas());
                    this->mazoCentral->barajarMazo();
                    this->pilaCompleta = true;
                } else {
                    this->cartas.push(carta);
                }
                resultado = true;
            }
        }
    }
    return resultado;
}

bool PilaCentral::estaCompleta() {
    return this->pilaCompleta;
}

vector<Carta> PilaCentral::sacarCartas() {
    vector<Carta> cartasVector;
    while (!this->cartas.empty()) {
        cartasVector.push_back(this->cartas.top());
        this->cartas.pop();
    }
    return cartasVector;
}

