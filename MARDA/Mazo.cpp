#include "mazo.h"

void mazo::crearMazo() {
    inicializaArregloAuxiliar();
    for (int i = 0; i < CANTIDAD_DE_SIMBOLOS; i++) {
        for (int j = 0; j < NUMEROS_EN_MAZO; j++) {
            std::string cartaCreada = numerosMazo[j] + simbolosDeCartas[i];
            mazoJugadorUno[numeroAleatorio()] = cartaCreada;
        }
    }

    inicializaArregloAuxiliar();
    for (int i = 0; i < CANTIDAD_DE_SIMBOLOS; i++) {
        for (int j = 0; j < NUMEROS_EN_MAZO; j++) {
            std::string cartaCreada = numerosMazo[j] + simbolosDeCartas[i];
            mazoJugadorDos[numeroAleatorio()] = cartaCreada;
        }
    }
    llenarMazos();
    mazoCreado();
}

int mazo::numeroAleatorio() {
    bool estaSeleccionado = false;
    int valorAleatorio;

    while (!estaSeleccionado) {
        valorAleatorio = rand() % CANTIDAD_CARTAS_POR_MAZO;
        if (!mazoAuxiliar[valorAleatorio]) {
            estaSeleccionado = true;
            mazoAuxiliar[valorAleatorio] = true;
        }
    }
    return valorAleatorio;
}

void mazo::inicializaArregloAuxiliar() {
    for (int i = 0; i < CANTIDAD_CARTAS_POR_MAZO; i++) {
        mazoAuxiliar[i] = false;
    }
}

void mazo::llenarMazos() {
    for (int i = 0; i < CANTIDAD_CARTAS_POR_MAZO; i++) {
        std::string valor = mazoJugadorUno[i];
        std::string valor1 = mazoJugadorDos[i];
        //std::cout << "* " << valor << " *" << std::endl;
        mazoJugadorUnoVector.push_back(valor);
        mazoJugadorUnoFinal.push(valor);
        mazoJugadorDosFinal.push(valor1);
    }
}

/*std::string mazo::obtenerCartaJugadorUno() {
    std::cout << "Holaaaaaaaaaaaaaaaaaaaaaa" << std::endl;
    std::string valorDeCarta = mazoJugadorUnoVector.at(5);
    return valorDeCarta;
}*/

void mazo::IniciarCartas()
{
    std::string nombreArchivo = "videojuegos.txt";
    std::ifstream archivo("../Cartas.txt");

    std::string linea;
    // Obtener línea de archivo, y almacenar contenido en "linea"
    while (getline(archivo, linea)) {
        // Lo vamos imprimiendo
        std::cout << linea << std::endl;
    }

}
