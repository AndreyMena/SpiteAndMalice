#ifndef PANTALLAJUEGO_H
#define PANTALLAJUEGO_H

#include <QWidget>
#include <QString>
#include <QListWidgetItem>

#include <iostream>

#include "tablero.h"
namespace Ui {
class PantallaJuego;
}

class PantallaJuego : public QWidget
{
    Q_OBJECT

public:
    const string URL_POR_DEFECTO = ":/img/img/";
    const string EXTENSION_POR_DEFECTO = ".png";
    const string URL_REVERSO_CARTA_POR_DEFECTO =  ":/img/img/backsideCard.png";
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

     void generarCarta(Carta carta, QListWidget* espacio);

     void generarCartaOculta (QListWidget* espacio);

private slots:
    /**
     * @brief Realiza las acciones que se dicten dentro del código del método
     * cuando el usuario le da clic a este botón en específico.
     */
    //void on_pushButton_2_clicked();

    void on_listWidget_2_itemChanged(QListWidgetItem *item);

    void on_listWidget_5_itemChanged(QListWidgetItem *item);

    void on_listWidget_6_itemChanged(QListWidgetItem *item);

    void on_listWidget_8_itemChanged(QListWidgetItem *item);

    void on_listWidget_2_itemEntered(QListWidgetItem *item);

private:
    Ui::PantallaJuego *ui;
    Tablero tablero;
};

#endif // PANTALLAJUEGO_H
