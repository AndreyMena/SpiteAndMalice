#ifndef PANTALLAJUEGO_H
#define PANTALLAJUEGO_H

#include <QWidget>
#include <iostream>
#include <QString>
#include <QListWidgetItem>

#include "tablero.h"
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
     * @param tablero Modelo que contiene toda la informacion de la partida
     */
     PantallaJuego(Tablero tablero);

    /**
     * @brief Destructor de la clase PantallaJuego
     */
    ~PantallaJuego();

private slots:
    /**
     * @brief Realiza las acciones que se dicten dentro del código del método
     * cuando el usuario le da clic a este botón en específico.
     */
    //void on_pushButton_2_clicked();

    void on_listWidget_2_itemEntered(QListWidgetItem *item);

    void on_listWidget_2_itemChanged(QListWidgetItem *item);

    void on_listWidget_5_itemChanged(QListWidgetItem *item);

    void on_listWidget_2_itemActivated(QListWidgetItem *item);

    void on_listWidget_2_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_listWidget_2_currentRowChanged(int currentRow);

private:
    Ui::PantallaJuego *ui;
    Tablero tablero;
};

#endif // PANTALLAJUEGO_H
