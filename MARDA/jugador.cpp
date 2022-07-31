#include "jugador.h"

Jugador::Jugador(int numeroJugador, Mazo *mazoCentral,
                 vector<PilaCentral>* pilasCentrales) :
    numeroJugador(numeroJugador),
    mazoCentral(mazoCentral),
    pilasCentrales(pilasCentrales)
{
    this->nombre = "";
    this->puntaje = 0;
    this->mano = new vector<Carta>();
    this->mazo = this->mazoCentral->dividirMazo(20);
    this->mano = this->mazoCentral->dividirMazo(5).obtenerCartasMazo();
    for (int i = 0; i < CANTIDAD_PILAS_DESCARTE; i++) {
        PilaDescarte* pilaDescarte = new PilaDescarte();
        this->pilasDescarte.push_back(pilaDescarte);
    }
    this->cartaJugadaPilaDescarte = false;
}

Jugador::Jugador(int numeroJugadorAux, Mazo *mazoCentral,
                 vector<PilaCentral>* pilasCentralesAux, vector<Carta> *manoAux,
                 Mazo mazoAux, vector<PilaDescarte*> PilasdeDescarteAux)
{
    this->mano = manoAux;
    this->mazoCentral = mazoCentral;
    this->mazo = mazoAux;
    this->numeroJugador = numeroJugadorAux;
    this->pilasCentrales = pilasCentralesAux;
    this->pilasDescarte = PilasdeDescarteAux;
    this->cartaJugadaPilaDescarte = false;
}

Jugador::~Jugador()
{
}

int Jugador::obtenerNumeroJugador() {
    return this->numeroJugador;
}

bool Jugador::agregarCartaPila(Carta carta, int tipoPila, int posicion) {
    bool resultado = false;
    if (tipoPila == TIPO_PILA_CENTRAL) {
        resultado = this->pilasCentrales->at(posicion).agregarCarta(carta);
    } else {
        resultado = this->pilasDescarte.at(posicion)->agregarCarta(carta);
        this->cartaJugadaPilaDescarte = true;
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

PilaDescarte* Jugador::obtenerPilaDescarte(int posicion) {
    return this->pilasDescarte.at(posicion);
}

bool Jugador::seDescartoCarta() {
  return this->seAgregoCartaPilaDescarte;
}
