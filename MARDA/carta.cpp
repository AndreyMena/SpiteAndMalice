#include "carta.h"

Carta::Carta(string nombre, int valor) : nombre(nombre), valor(valor)
{
}

Carta::~Carta()
{
}

string Carta::obtenerNombre() {
    return this->nombre;
}

int Carta::obtenerValor() {
    return this->valor;
}
