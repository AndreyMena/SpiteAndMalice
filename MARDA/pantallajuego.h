#ifndef PANTALLAJUEGO_H
#define PANTALLAJUEGO_H

#include <QWidget>
#include <QString>
#include <QListWidgetItem>
#include <QDrag>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QPainter>
#include <QListWidget>
#include <QMainWindow>
#include <QDropEvent>
#include <QtDebug>
#include <QAbstractItemView>

#include <fstream>

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
    // Métodos asociados a las acciones realizadas sobre las pilas de descarte.
    // Son generados por el framework

    void on_piladescarte_J1_1_itemChanged(QListWidgetItem *item);
    void on_piladescarte_J1_2_itemChanged(QListWidgetItem *item);
    void on_piladescarte_J1_3_itemChanged(QListWidgetItem *item);
    void on_piladescarte_J1_4_itemChanged(QListWidgetItem *item);

    void on_piladescarte_J2_1_itemChanged(QListWidgetItem *item);
    void on_piladescarte_J2_2_itemChanged(QListWidgetItem *item);
    void on_piladescarte_J2_3_itemChanged(QListWidgetItem *item);
    void on_piladescarte_J2_4_itemChanged(QListWidgetItem *item);

    // Métodos asociados a las acciones realizadas sobre las pilas de centrales.
    // Son generados por el framework

    void on_pilacentral_1_itemChanged(QListWidgetItem *item);
    void on_pilacentral_2_itemChanged(QListWidgetItem *item);
    void on_pilacentral_3_itemChanged(QListWidgetItem *item);

    // Botones del tablero

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    /**
     * @brief Asigna el espacio a cada jugador
     */
    void asignarEspaciosJugadores();

    /**
     * @brief Genera una carta basándose en el espacio y en el jugador al que
     * se la asigna
     * @param carta
     * @param espacio
     * @param numeroJugador
     * @param posicionCarta
     */
    void generarCarta(Carta carta, QListWidget* espacio, int numeroJugador, int posicionCarta);

    /**
     * @brief Genera una carta que muestra la parte trasera de una carta real
     * @param espacio
     */
    void generarCartaOculta (QListWidget* espacio);

    /**
     * @brief Genera las cartas de la mano de cada jugador
     * @param numeroJugador
     */
    void generarCartasJugador(int numeroJugador);

    /**
     * @brief Genera cartas vueltas (ocultas) de cada jugador
     * @param numeroJugador
     */
    void generarCartasOcultasJugador(int numeroJugador);

    /**
     * @brief Genera la carta del mazo personal de cada jugador
     * @param numeroJugador
     */
    void generarCartaMazoJugador(int numeroJugador);

    /**
     * @brief Se encarga de esconder la carta de cada jugador cuando no es su
     * turno
     */
    void borrarCartasJugadores();

    /**
     * @brief Cambia el turno entre ambos jugadores
     * @param numeroJugador
     */
    void cambiarTurno(int numeroJugador);

    /**
     * @brief Inserta una carta en la pila. Se refiere al proceso que conlleva,
     * desde la revision de reglas hasta las acciones que eso desencadena
     * @param informacionCarta
     * @param tipoPila
     * @param numeroPila
     */
    void insertarCartaEnLaPila(std::string informacionCarta, int tipoPila, int numeroPila);

    /**
     * @brief Desactiva la mano de un jugador cuando no es su turno
     * @param jugador
     */
    void desactivarManoJugador(int jugador);

    /**
     * @brief Activa la mano de un jugador cuando le corresponde jugar
     * @param jugador
     */
    void activarManoJugador(int jugador);

    Ui::PantallaJuego *ui;
    Tablero tablero;
    vector<vector<QListWidget*>> espacios;
    map<string,string> informacionCartaActual;
    int contadorPilaCentral1 = 0;
    int contadorAuxPilaCentral1 = 0;
};

#endif // PANTALLAJUEGO_H
