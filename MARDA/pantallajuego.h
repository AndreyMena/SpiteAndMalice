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

    void desactivarManoJugador(int jugador);

    void activarManoJugador(int jugador);

    void on_listWidget_2_itemChanged(QListWidgetItem *item);

    void on_listWidget_5_itemChanged(QListWidgetItem *item);

    void on_listWidget_6_itemChanged(QListWidgetItem *item);

    void on_listWidget_8_itemChanged(QListWidgetItem *item);

    void on_listWidget_2_itemEntered(QListWidgetItem *item);

    void on_descarteJ1_1_clicked();

    void on_descarteJ1_2_clicked();

    void on_descarteJ1_3_clicked();

    void on_descarteJ1_4_clicked();

    void on_descarteJ2_1_clicked();

    void on_descarteJ2_2_clicked();

    void on_descarteJ2_3_clicked();

    void on_descarteJ2_4_clicked();

    void on_listWidgetJ1_1_itemChanged(QListWidgetItem *item);

    void on_listWidgetJ1_2_itemChanged(QListWidgetItem *item);

    void on_listWidgetJ1_3_itemChanged(QListWidgetItem *item);

    void on_listWidgetJ1_4_itemChanged(QListWidgetItem *item);

    void on_listWidgetJ2_1_itemChanged(QListWidgetItem *item);

    void on_listWidgetJ2_2_itemChanged(QListWidgetItem *item);

    void on_listWidgetJ2_3_itemChanged(QListWidgetItem *item);

    void on_listWidgetJ2_4_itemChanged(QListWidgetItem *item);

    void on_descartarJ1_1_clicked();

    void on_descartarJ1_2_clicked();

    void on_descartarJ1_3_clicked();

    void on_descartarJ1_4_clicked();

    void on_descartarJ2_1_clicked();

    void on_descartarJ2_2_clicked();

    void on_descartarJ2_3_clicked();

    void on_descartarJ2_4_clicked();

private:
    Ui::PantallaJuego *ui;
    Tablero tablero;
};

#endif // PANTALLAJUEGO_H
