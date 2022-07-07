#include "tablero.h"

Tablero::Tablero(int cantidadJugadores)
{
    //Se llena el mazo central con 52 cartas por jugador en el caso que sean dos jugadores por ejemplo
    // se llenaria el mazo con 104 cartas
    for (int i = 0; i < cantidadJugadores; i++) {
        this->mazoCentral.llenarMazo();
    }
    //Se define el turno de jugador en -1 indicando que ningun jugador tiene un turno asignado aun.
    this->turnoJugador = -1;
    // Se crean los jugadores y se añaden al vector de jugadores del tablero
    for (int i = 0; i < cantidadJugadores; i++) {
        this->jugadores.emplace_back(Jugador(i+1, &mazoCentral, &pilasCentrales));
    }

    for (int i = 0; i < CANTIDAD_PILAS_CENTRALES; i++) {
        this->pilasCentrales.emplace_back(PilaCentral(&mazoCentral));
    }
}

Tablero::~Tablero()
{

}

void Tablero::asignarTurno(int numeroJugador) {
    this->turnoJugador = numeroJugador;
}

bool Tablero::esTurnoJugador(int numeroJugador) {
    bool resultado = false;
    if (this->turnoJugador == numeroJugador) {
        resultado = true;
    }
    return resultado;
}

vector<Jugador> Tablero::obtenerJugadores() {
    return this->jugadores;
}

Mazo& Tablero::obtenerMazo() {
    return this->mazoCentral;
}
