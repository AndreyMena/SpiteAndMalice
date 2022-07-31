#ifndef MENUJUEGO_H
#define MENUJUEGO_H

#include <QMainWindow>

#include "pantallajuego.h"
#include "mazo.h"
#include "eleccionjugador.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MenuJuego; }
QT_END_NAMESPACE

class MenuJuego : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructor de la clase MenuJuego donde se muestra el menú del juego
     * juego.
     * @param parent Parámetro de la clase padre QWidget
     */
    MenuJuego(QWidget *parent = nullptr);
    /**
     * @brief Destructor de la clase MenuJuego
     */
    ~MenuJuego();

private slots:
    /**
     * @brief Muestra una pantalla que permite elegir el numero de jugador deseado
     */
    void on_pushButton_clicked();

    /**
     * @brief Muestra las reglas del juego cuando se de click al mismo
     */
    void on_pushButton_4_clicked();

    /**
     * @brief Realiza las acciones que se dicten dentro del código del método
     * cuando el usuario le da clic a este botón en específico.
     */
    void on_cargarPartida_clicked();

private:
    /**
     * @brief Puntero a interfaz de menujuego
     */
    Ui::MenuJuego *ui;
};
#endif // MENUJUEGO_H
