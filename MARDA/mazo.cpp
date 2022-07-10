#include "mazo.h"

Mazo::Mazo() {
    this->cartas = new vector<Carta>();
}

Mazo::~Mazo() {
}

void Mazo::llenarMazo() {
    for (unsigned int i = 0; i < this->numerosCarta.size(); i++) {
        for (unsigned int j=0; j < this->simbolosCarta.size(); j++) {
            string nombreCarta = this->numerosCarta[i]+this->simbolosCarta[j];
            int valorCarta = i+1;
            if (valorCarta == 13) {
                valorCarta = -1;
            }
            Carta carta(nombreCarta, valorCarta);
            this->cartas->push_back(carta);
        }
    }
    this->barajarMazo();
}

void Mazo::barajarMazo() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(this->cartas->begin(), this->cartas->end(), std::default_random_engine(seed));
}

Carta Mazo::sacarCartaMazo(int posicion) {
    Carta carta = this->cartas->at(posicion);
    this->cartas->erase(this->cartas->begin()+posicion);
    return carta;
}

void Mazo::agregarCartaMazo(Carta carta, int posicion) {
    this->cartas->insert(this->cartas->begin()+posicion, carta);
}

void Mazo::agregarCartasMazo(vector<Carta> cartasNuevas) {
   for (auto &&n : cartasNuevas) {
        this->cartas->insert(this->cartas->begin(), n);
    }
}

Mazo Mazo::dividirMazo(unsigned int cantidadCartas) {
    Mazo nuevoMazo;
    vector<Carta>* cartasAuxiliar = new vector<Carta>();
    if (cantidadCartas < this->cartas->size()) {
        for (unsigned int i = 0; i < cantidadCartas; i++) {
            cartasAuxiliar->push_back(this->cartas->back());
            this->cartas->pop_back();
        }
        nuevoMazo.cartas = cartasAuxiliar;
    } else {
        throw "Numero de cartas a dividir invalido";
    }
    return nuevoMazo;
}

vector<Carta>* Mazo::obtenerCartasMazo() {
    return this->cartas;
}
