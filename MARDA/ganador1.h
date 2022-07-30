#ifndef GANADOR1_H
#define GANADOR1_H

#include <QWidget>

namespace Ui {
class Ganador1;
}

class Ganador1 : public QWidget
{
    Q_OBJECT

public:
    const int TURNO_JUGADOR1 = 1;
    const int TURNO_JUGADOR2 = 2;
    const int CANTIDAD_JUGADORES = 2;
    /**
     * @brief EleccionJugador Muestra la pantalla para elegir que jugador se
     * quiere que juegue primero
     * @param parent Parámetro de la clase padre QWidget
     */
    explicit Ganador1(QWidget *parent = nullptr);

    ~Ganador1();

private:
    Ui::Ganador1 *ui;
};

#endif // GANADOR1_H
