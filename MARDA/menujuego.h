#ifndef MENUJUEGO_H
#define MENUJUEGO_H

#include <QMainWindow>

#include "pantallajuego.h"
#include "mazo.h"
#include "eleccionjugador.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MenuJuego; }
QT_END_NAMESPACE

/**
 * @brief Interfaz para el menu del juego
 * @details Esta interfaz permite seleccionar las opciones:
 *          Nueva partida
 *          Reglas
 *          Cargar partida
 *          Salir
 */
class MenuJuego : public QMainWindow
{
    Q_OBJECT

public:

    /**
     * @brief Constructor de interfaz eleccion MenuJuego
     * @param parent QWidget*
     */
    MenuJuego(QWidget *parent = nullptr);

    /**
     * @brief Destructor de interfaz MenuJuego.
     */
    ~MenuJuego();

private slots:

    /**
     * @brief Metodo llamado para presionar el boton: 1
     * @return void
     */
    void on_pushButton_clicked();

    /**
     * @brief Metodo llamado para presionar el boton: 4
     * @return void
     */
    void on_pushButton_4_clicked();

private:

    /**
     * @brief Puntero a la interfaz MenuJuego.
     */
    Ui::MenuJuego *ui;
};
#endif // MENUJUEGO_H
