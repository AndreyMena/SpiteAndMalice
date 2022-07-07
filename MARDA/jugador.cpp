#include "jugador.h"

Jugador::Jugador(int numeroJugador, Mazo *mazoCentral, vector<PilaCentral> *pilasCentrales) :
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

vector<Carta> Jugador::obtenerMano() {
    return this->mano;
}
