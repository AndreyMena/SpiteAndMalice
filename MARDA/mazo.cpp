#include "mazo.h"

Mazo::Mazo() {
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
            this->cartas.push_back(carta);
        }
    }
    this->barajarMazo();
}

void Mazo::barajarMazo() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(this->cartas.begin(), this->cartas.end(), std::default_random_engine(seed));
}

Carta Mazo::sacarCartaMazo(int posicion) {
    Carta carta = this->cartas[posicion];
    this->cartas.erase(this->cartas.begin()+posicion);
    return carta;
}

void Mazo::agregarCartaMazo(Carta carta, int posicion) {
    this->cartas.insert(this->cartas.begin()+posicion, carta);
}

void Mazo::agregarCartasMazo(vector<Carta> cartas) {
    for (auto &&n : cartas) {
        this->cartas.insert(this->cartas.begin(), n);
    }
}

Mazo Mazo::dividirMazo(unsigned int cantidadCartas) {
    Mazo nuevoMazo;
    vector<Carta> cartasAuxiliar;
    if (cantidadCartas < this->cartas.size()) {
        for (unsigned int i = 0; i < cantidadCartas; i++) {
            cartasAuxiliar.push_back(this->cartas.back());
            this->cartas.pop_back();
        }
        nuevoMazo.cartas = cartasAuxiliar;
    } else {
        throw "Numero de cartas a dividir invalido";
    }
    return nuevoMazo;
}

vector<Carta> Mazo::obtenerCartasMazo() {
    return this->cartas;
}
