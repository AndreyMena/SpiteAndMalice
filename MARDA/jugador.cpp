#include "jugador.h"

Jugador::Jugador(int numeroJugador, Mazo *mazoCentral, vector<PilaCentral*> pilasCentrales) :
    numeroJugador(numeroJugador),
    mazoCentral(mazoCentral),
    pilasCentrales(pilasCentrales)
{
    this->mazo = this->mazoCentral->dividirMazo(20);
    this->mano = this->mazoCentral->dividirMazo(5).obtenerCartasMazo();
    for (int i = 0; i < CANTIDAD_PILAS_DESCARTE; i++) {
        this->pilasDescarte.emplace_back(PilaDescarte());
    }
}

Jugador::~Jugador()
{

}

int Jugador::obtenerNumeroJugador() {
    return this->numeroJugador;
}

Carta Jugador::sacarCartaMano(int posicion) {
    Carta carta = this->mano[posicion];
    this->mano.erase(this->mano.begin()+posicion);
    return carta;
}

void Jugador::agregarCartaMano(Carta carta, int posicion) {
    this->mano.insert(this->mano.begin()+posicion, carta);
}

void Jugador::agregarCartaPila(Carta carta, int tipoPila, int posicion) {
    if (tipoPila == TIPO_PILA_CENTRAL) {
        this->pilasCentrales.at(posicion)->agregarCarta(carta);
    } else {
        this->pilasDescarte.at(posicion).agregarCarta(carta);
    }
}

void Jugador::rellenarMano() {
    for (unsigned int i = 0; i < this->mano.size(); i++) {
        if (this->mano[i].obtenerValor() == 0) {
            sacarCartaMano(i);
            int posicion = this->mazo.obtenerCartasMazo().size()-1;
            if (posicion != -1) {
                agregarCartaMano(this->mazo.sacarCartaMazo(posicion), i);
            }
        }
    }
}


Mazo* Jugador::obtenerMazoPersonal() {
    return &this->mazo;
}

vector<Carta>* Jugador::obtenerMano() {
    return &this->mano;
}
