#include "pilacentral.h"

PilaCentral::PilaCentral(Mazo *mazoCentral) :
    mazoCentral(mazoCentral)
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
    } else {
        if (!this->cartas.empty()) {
            if (this->cartas.top().obtenerValor() == -1 || carta.obtenerValor() == -1
                || carta.obtenerValor()+1 == this->cartas.top().obtenerValor()) {
                if (this->cartas.size() == 11) {
                    this->cartas.push(carta);
                    this->mazoCentral->agregarCartasMazo(sacarCartas());
                    this->mazoCentral->barajarMazo();
                } else {
                    this->cartas.push(carta);
                }
                resultado = true;
            }
        }
    }
    return resultado;
}

vector<Carta> PilaCentral::sacarCartas() {
    vector<Carta> cartas;
    while (!this->cartas.empty()) {
        cartas.push_back(this->cartas.top());
        this->cartas.pop();
    }
    return cartas;
}
