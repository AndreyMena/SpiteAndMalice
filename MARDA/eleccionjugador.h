#ifndef ELECCIONJUGADOR_H
#define ELECCIONJUGADOR_H

#include <QWidget>

namespace Ui {
class EleccionJugador;
}

class EleccionJugador : public QWidget
{
    Q_OBJECT

public:
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
    void on_pushButton_3_clicked();
    /**
     * @brief Permite que el Jugador 2 comienze la partida
     */
    void on_pushButton_4_clicked();

private:
    Ui::EleccionJugador *ui;
};

#endif // ELECCIONJUGADOR_H
