#include "tablero.h"

Tablero::Tablero(int cantidadJugadores)
{
    this->mazoCentral = new Mazo();
    this->pilasCentrales = new vector<PilaCentral>();
    //Se llena el mazo central con 52 cartas por jugador en el caso que sean dos jugadores por ejemplo
    // se llenaria el mazo con 104 cartas
    for (int i = 0; i < cantidadJugadores; i++) {
        this->mazoCentral->llenarMazo();
    }
    //Se define el turno de jugador en -1 indicando que ningun jugador tiene un turno asignado aun.
    this->turnoJugador = -1;

    for (int i = 0; i < CANTIDAD_PILAS_CENTRALES; i++) {

        PilaCentral pilaCentral((Mazo*) mazoCentral);
        this->pilasCentrales->push_back(pilaCentral);
        //this->pilasCentrales.emplace_back(PilaCentral(&mazoCentral));
    }

    // Se crean los jugadores y se añaden al vector de jugadores del tablero
    for (int i = 0; i < cantidadJugadores; i++) {
        Jugador* jugador = new Jugador(i+1,(Mazo*) mazoCentral, this->pilasCentrales);
        this->jugadores.push_back(jugador);
    }
}

Tablero::Tablero(vector<PilaCentral>* pilasCentrales,int turnoJugador, vector<JugadorAbstracto*> jugadores)
: TableroAbstracto(turnoJugador,jugadores), pilasCentrales(pilasCentrales)

{
}

Tablero::Tablero(MazoAbstracto* mazoCentral, vector<PilaCentral>* pilasCentrales,int turnoJugador, vector<JugadorAbstracto*> jugadores)
: TableroAbstracto(turnoJugador, jugadores, mazoCentral), pilasCentrales(pilasCentrales)
{
}

Tablero::~Tablero()
{
}

PilaCentral& Tablero::obtenerPilaCentral(int posicion) {
    return this->pilasCentrales->at(posicion);
}

void Tablero::jugarCarta(JugadorAbstracto* jugador, int posicionCartaMano) {
  /*
  if (posicionCartaMano)
  Carta cartaVacia("Vacia", 0);
  jugador->sacarCartaMano(posicionCartaMano);
  jugador->agregarCartaMano(cartaVacia, posicionCartaMano);
    */
}
void Tablero::cambiarTurno(JugadorAbstracto* jugador) {

}

void Tablero::verificarGanador(JugadorAbstracto* jugador) {
  //if ()
}
