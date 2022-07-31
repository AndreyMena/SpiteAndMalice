#include "jugadorabstracto.h"

JugadorAbstracto::JugadorAbstracto(string nombre, vector<Carta> *mano,
                                   int puntaje)
    : nombre(nombre), mano(mano), puntaje(puntaje) {}

JugadorAbstracto::~JugadorAbstracto() {}

string JugadorAbstracto::obtenerNombre() { return this->nombre; }

int JugadorAbstracto::obtenerPuntaje() { return this->puntaje; }

void JugadorAbstracto::asignarPuntaje(int puntaje) { this->puntaje = puntaje; }

vector<Carta> *JugadorAbstracto::obtenerMano() { return this->mano; }

Carta JugadorAbstracto::sacarCartaMano(int posicion) {
  Carta carta = this->mano->at(posicion);
  this->mano->erase(this->mano->begin() + posicion);
  return carta;
}

void JugadorAbstracto::agregarCartaMano(Carta carta, int posicion) {
  this->mano->insert(this->mano->begin() + posicion, carta);
}
