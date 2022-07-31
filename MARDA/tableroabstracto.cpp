#include "tableroabstracto.h"

TableroAbstracto::TableroAbstracto() {}

TableroAbstracto::TableroAbstracto(int turnoJugador, vector<JugadorAbstracto*> jugadores)
: turnoJugador(turnoJugador), jugadores(jugadores) {

}

TableroAbstracto::TableroAbstracto(int turnoJugador, vector<JugadorAbstracto*> jugadores, MazoAbstracto* mazoCentral) :
    turnoJugador(turnoJugador),  jugadores(jugadores) , mazoCentral(mazoCentral)
{

}

TableroAbstracto::~TableroAbstracto() {

}

void TableroAbstracto::asignarTurno(int numeroJugador) {
    this->turnoJugador = numeroJugador;
}

bool TableroAbstracto::esTurnoJugador(int numeroJugador) {
    bool resultado = false;
    if (this->turnoJugador == numeroJugador) {
        resultado = true;
    }
    return resultado;
}

JugadorAbstracto* TableroAbstracto::obtenerJugador(int numeroJugador) {
    return this->jugadores.at(numeroJugador-1);
}

vector<JugadorAbstracto*>& TableroAbstracto::obtenerJugadores() {
    return this->jugadores;
}

MazoAbstracto* TableroAbstracto::obtenerMazoCentral() {
    return this->mazoCentral;
}

void TableroAbstracto::hacerJugada(JugadorAbstracto* jugador, int posicionCartaMano) {
  this->jugarCarta(jugador, posicionCartaMano);
  this->cambiarTurno(jugador);
  this->verificarGanador(jugador);
}
