#ifndef CARTA_H
#define CARTA_H

#include <string>

using namespace std;

class Carta
{
public:
    Carta(string nombre, int valor);
    ~Carta();
    string obtenerNombre();
    int obtenerValor();
private:
    string nombre;
    int valor;
};

#endif // CARTA_H
