#ifndef GANADOR2_H
#define GANADOR2_H

#include <QWidget>

namespace Ui {
class Ganador2;
}

class Ganador2 : public QWidget
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
    explicit Ganador2(QWidget *parent = nullptr);

    /**
     * Destructor de la clase
    */
    ~Ganador2();

private:
    Ui::Ganador2 *ui;
};

#endif // GANADOR2_H
