#ifndef ELECCIONJUGADOR_H
#define ELECCIONJUGADOR_H

#include <QWidget>

#include "tablero.h"

namespace Ui {
class EleccionJugador;
}

class EleccionJugador : public QWidget
{
    Q_OBJECT

public:
    const int TURNO_JUGADOR1 = 1;
    const int TURNO_JUGADOR2 = 2;
    const int CANTIDAD_JUGADORES = 2;
    /**
     * @brief EleccionJugador Muestra la pantalla para elegir que jugador se quiere que juegue primero
     * @param parent Parámetro de la clase padre QWidget
     */
    explicit EleccionJugador(QWidget *parent = nullptr);
    ~EleccionJugador();

private slots:
    /**
     * @brief Permite que el Jugador 1 comienze la partida
     */
    void on_eleccionJugador1_clicked();
    /**
     * @brief Permite que el Jugador 2 comienze la partida
     */
    void on_eleccionJugador2_clicked();

private:
    Ui::EleccionJugador *ui;
};

#endif // ELECCIONJUGADOR_H
