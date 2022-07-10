#ifndef PANTALLAJUEGO_H
#define PANTALLAJUEGO_H

#include <QWidget>
#include <QString>
#include <QListWidgetItem>

#include <iostream>
#include <map>
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

private slots:
    // Pilas Descarte

    void on_piladescarte_J1_1_itemChanged(QListWidgetItem *item);
    void on_piladescarte_J1_1_currentRowChanged(int currentRow);

    void on_piladescarte_J1_2_itemChanged(QListWidgetItem *item);
    void on_piladescarte_J1_2_currentRowChanged(int currentRow);

    void on_piladescarte_J1_3_itemChanged(QListWidgetItem *item);
    void on_piladescarte_J1_3_currentRowChanged(int currentRow);

    void on_piladescarte_J1_4_itemChanged(QListWidgetItem *item);
    void on_piladescarte_J1_4_currentRowChanged(int currentRow);

    void on_piladescarte_J2_1_itemChanged(QListWidgetItem *item);
    void on_piladescarte_J2_1_currentRowChanged(int currentRow);

    void on_piladescarte_J2_2_itemChanged(QListWidgetItem *item);
    void on_piladescarte_J2_2_currentRowChanged(int currentRow);

    void on_piladescarte_J2_3_itemChanged(QListWidgetItem *item);
    void on_piladescarte_J2_3_currentRowChanged(int currentRow);

    void on_piladescarte_J2_4_itemChanged(QListWidgetItem *item);
    void on_piladescarte_J2_4_currentRowChanged(int currentRow);

    // Pilas Centrales

    void on_pilacentral_1_itemChanged(QListWidgetItem *item);
    void on_pilacentral_1_currentRowChanged(int currentRow);

    void on_pilacentral_2_itemChanged(QListWidgetItem *item);
    void on_pilacentral_2_currentRowChanged(int currentRow);

    void on_pilacentral_3_itemChanged(QListWidgetItem *item);
    void on_pilacentral_3_currentRowChanged(int currentRow);

private:
    void asignarEspaciosJugadores();

    void generarCarta(Carta carta, QListWidget* espacio, int numeroJugador, int posicionCarta);

    void generarCartaOculta (QListWidget* espacio);

    void generarCartasJugador(int numeroJugador);

    void generarCartasOcultasJugador(int numeroJugador);

    void generarCartaMazoJugador(int numeroJugador);

    void borrarCartasJugadores();

    void cambiarTurno(int numeroJugador);

    void insertarCartaEnLaPila(std::string informacionCarta, int tipoPila, int numeroPila);

    void desactivarManoJugador(int jugador);

    void activarManoJugador(int jugador);

    Ui::PantallaJuego *ui;
    Tablero tablero;
    vector<vector<QListWidget*>> espacios;
    map<string,string> informacionCartaActual;
};

#endif // PANTALLAJUEGO_H
