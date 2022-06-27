#ifndef PANTALLAJUEGO_H
#define PANTALLAJUEGO_H

#include <QWidget>
#include <iostream>
#include <QString>

namespace Ui {
class PantallaJuego;
}

class PantallaJuego : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructor de la clase PantallaJuego donde se muestra y juega el
     * juego.
     * @param parent Parámetro de la clase padre QWidget
     */
    explicit PantallaJuego(QWidget *parent = nullptr);

    /**
     * Destructor de la clase PantallaJuego
     */
    ~PantallaJuego();

    /**
     * @brief Método para acceder a las imágenes de las cartas. De momento se
     * encuentra inhabilitado
     */
    void IniciarCartas();

private slots:
    /**
     * @brief Realiza las acciones que se dicten dentro del código del método
     * cuando el usuario le da clic a este botón en específico.
     */
    void on_pushButton_2_clicked();

private:
    Ui::PantallaJuego *ui;
};

#endif // PANTALLAJUEGO_H
