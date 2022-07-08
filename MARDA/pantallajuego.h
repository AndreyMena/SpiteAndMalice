#ifndef PANTALLAJUEGO_H
#define PANTALLAJUEGO_H

#include <QWidget>
#include <QString>
#include <QListWidgetItem>

#include <iostream>
#include <string>
#include <sstream>

#include "tablero.h"
namespace Ui {
class PantallaJuego;
}

class PantallaJuego : public QWidget
{
    Q_OBJECT

public:
    const int TIPO_PILA_DESCARTE = 0;
    const int TIPO_PILA_CENTRAL = 1;
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

     void generarCarta(Carta carta, QListWidget* espacio, int numeroJugador, int posicionCarta);

     void generarCartaOculta (QListWidget* espacio);

private slots:

    void cambiarTurno(int numeroJugador);

    void insertarCartaEnLaPila(std::string informacionCarta, int tipoPila, int numeroPila);

    void desactivarManoJugador(int jugador);

    void activarManoJugador(int jugador);

    // Pilas Descarte

    void on_descartarJ1_1_clicked();

    void on_descartarJ1_2_clicked();

    void on_descartarJ1_3_clicked();

    void on_descartarJ1_4_clicked();

    void on_descartarJ2_1_clicked();

    void on_descartarJ2_2_clicked();

    void on_descartarJ2_3_clicked();

    void on_descartarJ2_4_clicked();

    // Pilas Centrales

    void on_pilacentral_1_itemChanged(QListWidgetItem *item);

    void on_pilacentral_2_itemChanged(QListWidgetItem *item);

    void on_pilacentral_3_itemChanged(QListWidgetItem *item);

    void on_boton_pilacentral_1_clicked();

    void on_boton_pilacentral_2_clicked();

    void on_boton_pilacentral_3_clicked();

private:
    Ui::PantallaJuego *ui;
    Tablero tablero;
    vector<vector<QListWidget*>> espacios;
};

#endif // PANTALLAJUEGO_H
