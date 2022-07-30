#include "jugador.h"

Jugador::Jugador(int numeroJugador, Mazo *mazoCentral, vector<PilaCentral>* pilasCentrales) :
    numeroJugador(numeroJugador),
    mazoCentral(mazoCentral),
    pilasCentrales(pilasCentrales)
{

    this->mano = new vector<Carta>();
    this->mazo = this->mazoCentral->dividirMazo(20);
    this->mano = this->mazoCentral->dividirMazo(5).obtenerCartasMazo();
    for (int i = 0; i < CANTIDAD_PILAS_DESCARTE; i++) {
        PilaDescarte* pilaDescarte = new PilaDescarte();
        this->pilasDescarte.push_back(pilaDescarte);
    }
}

Jugador::Jugador(int numeroJugadorAux, Mazo *mazoCentral, vector<PilaCentral>* pilasCentralesAux, vector<Carta> *manoAux, Mazo mazoAux, vector<PilaDescarte*> PilasdeDescarteAux)
{
    this->mano = manoAux;
    this->mazoCentral = mazoCentral;
    this->mazo = mazoAux;
    this->numeroJugador = numeroJugadorAux;
    this->pilasCentrales = pilasCentralesAux;
    this->pilasDescarte = PilasdeDescarteAux;
}

Jugador::~Jugador()
{

}

int Jugador::obtenerNumeroJugador() {
    return this->numeroJugador;
}

Carta Jugador::sacarCartaMano(int posicion) {
    Carta carta = this->mano->at(posicion);
    this->mano->erase(this->mano->begin()+posicion);
    return carta;
}

void Jugador::agregarCartaMano(Carta carta, int posicion) {
    this->mano->insert(this->mano->begin()+posicion, carta);
}

bool Jugador::agregarCartaPila(Carta carta, int tipoPila, int posicion) {
    bool resultado = false;
    if (tipoPila == TIPO_PILA_CENTRAL) {
        resultado = this->pilasCentrales->at(posicion).agregarCarta(carta);
    } else {
        resultado = this->pilasDescarte.at(posicion)->agregarCarta(carta);
    }
    return resultado;
}

void Jugador::rellenarMano() {
    for (unsigned int i = 0; i < this->mano->size(); i++) {
        if (this->mano->at(i).obtenerValor() == 0) {
            sacarCartaMano(i);
            int posicion = this->mazoCentral->obtenerCartasMazo()->size()-1;
            if (posicion != -1) {
                agregarCartaMano(this->mazoCentral->sacarCartaMazo(posicion), i);
            }
        }
    }
}

Mazo Jugador::obtenerMazoPersonal() {
    return this->mazo;
}

vector<Carta>* Jugador::obtenerMano() {
    return this->mano;
}

PilaDescarte* Jugador::obtenerPilaDescarte(int posicion) {
    return this->pilasDescarte.at(posicion);
}


