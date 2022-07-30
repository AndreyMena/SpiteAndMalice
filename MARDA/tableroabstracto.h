#ifndef TABLEROABSTRACTO_H
#define TABLEROABSTRACTO_H

#include <vector>

using namespace std;

#include "jugadorabstracto.h"
#include "mazoabstracto.h"

class TableroAbstracto
{
public:
    /**
     * @brief Tablero Constructor de la clase TableroAbstracto
     */
    TableroAbstracto(int turnoJugador, vector<JugadorAbstracto*> jugadores);
    /**
     * @brief Destructor de la clase TableroAbstracto
     */
    ~TableroAbstracto();


private:
  vector<JugadorAbstracto*> jugadores;
  int turnoJugador;
  MazoAbstracto* mazo;
};

#endif // TABLEROABSTRACTO_H

