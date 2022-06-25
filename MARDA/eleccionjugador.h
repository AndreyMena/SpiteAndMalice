#ifndef ELECCIONJUGADOR_H
#define ELECCIONJUGADOR_H

#include <QWidget>
/**
 * @brief Interfaz para eleccion de jugador.
 * @details Esta interfaz permite elegir el turno 1 o el turno 2,
 *          respectivamente para el jugador 1 y 2, una vez se
 *          selecciona el turno, se da comienzo al juego.
 */
namespace Ui {
class EleccionJugador;
}

class EleccionJugador : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructor de interfaz EleccionJugador.
     * @param parent QWidget*
     */
    explicit EleccionJugador(QWidget *parent = nullptr);

    /**
     * @brief Destructor de interfaz EleccionJugador.
     */
    ~EleccionJugador();

private slots:

    /**
     * @brief Metodo llamado para presionar el boton: 3.
     * @return void
     */
    void on_pushButton_3_clicked();

    /**
     * @brief Metodo llamado para presionar el boton: 4.
     * @return void
     */
    void on_pushButton_4_clicked();

private:

    /**
     * @brief Puntero a la interfaz EleccionJugador.
     */
    Ui::EleccionJugador *ui;
};

#endif // ELECCIONJUGADOR_H
