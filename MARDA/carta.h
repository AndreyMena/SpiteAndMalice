#ifndef CARTA_H
#define CARTA_H

#include <string>

using namespace std;

class Carta
{
public:
    /**
     * @brief Carta Crea una carta con un nombre y un valor
     * @param nombre Nombre de la carta representada
     * @param valor Valor de la carta representada
     */
    Carta(string nombre, int valor);

    /**
     * Destructor de la clase
    */
    ~Carta();

    /**
     * @brief obtenerNombre Obtiene el nombre de la carta
     * @return Devuelve un String con el nombre de la carta
     */
    string obtenerNombre();

    /**
     * @brief obtenerValor Obtiene el valor de la carta
     * @return Devuelve un int con el valor que representa la carta
     */
    int obtenerValor();

private:
    /**
     * @brief nombre Nombre de la carta
     */
    string nombre;

    /**
     * @brief valor Valor que tiene la carta
     */
    int valor;
};

#endif // CARTA_H



