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
     * @param cargarPartida booleano que define si se carga una partida.
     */
     PantallaJuego(Tablero tablero, bool cargarPartida);

    /**
     * @brief Destructor de la clase PantallaJuego
     */
    ~PantallaJuego();

private slots:
     /**
      * @brief Método asociado a las acciones realizadas sobre las pilas de descarte.
      *        Son generados por el framework.
      * @param QListWidgetItem *item
      * @return void
      */
    void on_piladescarte_J1_1_itemChanged(QListWidgetItem *item);

    /**
     * @brief Método asociado a las acciones realizadas sobre las pilas de descarte.
     *        Son generados por el framework.
     * @param QListWidgetItem *item
     * @return void
     */
    void on_piladescarte_J1_2_itemChanged(QListWidgetItem *item);

    /**
     * @brief Método asociado a las acciones realizadas sobre las pilas de descarte.
     *        Son generados por el framework.
     * @param QListWidgetItem *item
     * @return void
     */

    void on_piladescarte_J1_3_itemChanged(QListWidgetItem *item);

    /**
     * @brief Método asociado a las acciones realizadas sobre las pilas de descarte.
     *        Son generados por el framework.
     * @param QListWidgetItem *item
     * @return void
     */
    void on_piladescarte_J1_4_itemChanged(QListWidgetItem *item);

    /**
     * @brief Método asociado a las acciones realizadas sobre las pilas de descarte.
     *        Son generados por el framework.
     * @param QListWidgetItem *item
     * @return void
     */
    void on_piladescarte_J2_1_itemChanged(QListWidgetItem *item);

    /**
     * @brief Método asociado a las acciones realizadas sobre las pilas de descarte.
     *        Son generados por el framework.
     * @param QListWidgetItem *item
     * @return void
     */
    void on_piladescarte_J2_2_itemChanged(QListWidgetItem *item);

    /**
     * @brief Método asociado a las acciones realizadas sobre las pilas de descarte.
     *        Son generados por el framework.
     * @param QListWidgetItem *item
     * @return void
     */
    void on_piladescarte_J2_3_itemChanged(QListWidgetItem *item);

    /**
     * @brief Método asociado a las acciones realizadas sobre las pilas de descarte.
     *        Son generados por el framework.
     * @param QListWidgetItem *item
     * @return void
     */
    void on_piladescarte_J2_4_itemChanged(QListWidgetItem *item);

    /**
     * @brief Método asociado a las acciones realizadas sobre las pilas de centrales.
     *        Son generados por el framework.
     * @param QListWidgetItem *item
     * @return void
     */
    void on_pilacentral_1_itemChanged(QListWidgetItem *item);

    /**
     * @brief Método asociado a las acciones realizadas sobre las pilas de centrales.
     *        Son generados por el framework.
     * @param QListWidgetItem *item
     * @return void
     */
    void on_pilacentral_2_itemChanged(QListWidgetItem *item);

    /**
     * @brief Método asociado a las acciones realizadas sobre las pilas de centrales.
     *        Son generados por el framework.
     * @param QListWidgetItem *item
     * @return void
     */
    void on_pilacentral_3_itemChanged(QListWidgetItem *item);

    // Botones del tablero

    /**
     * @brief Método asociado a las acciones realizadas para guardar partida.
     *        Son generados por el framework.
     * @return void
     */
    void on_pushButton_clicked();

    /**
     * @brief Método asociado a las acciones realizadas para abandonar partida.
     *        Son generados por el framework.
     * @return void
     */
    void on_pushButton_2_clicked();

private:
    /**
     * @brief Asigna el espacio a cada jugador
     */
    void asignarEspaciosJugadores();

    /**
     * @brief Genera una carta basándose en el espacio y en el jugador al que
     * se la asigna
     * @param carta Carta que se va a generar
     * @param espacio El espacio donde se va a generar dicha carta
     * @param numeroJugador Numero del jugador a quien pertenece la carta generada
     * @param posicionCarta Posicion de la carta que se va a generar
     */
    void generarCarta(Carta carta, QListWidget* espacio, int numeroJugador,
                      int posicionCarta);

    /**
     * @brief Genera una carta que muestra la parte trasera de una carta real
     * @param espacio Espacio donde se va a generar esta carta oculta
     */
    void generarCartaOculta (QListWidget* espacio);

    /**
     * @brief Genera las cartas de la mano de cada jugador
     * @param numeroJugador Numero del jugador al que se le generara la mano
     */
    void generarCartasJugador(int numeroJugador);

    /**
     * @brief Genera cartas vueltas (ocultas) de cada jugador
     * @param numeroJugador Numero del jugador al que se le generara una mano de cartas ocultas
     */
    void generarCartasOcultasJugador(int numeroJugador);

    /**
     * @brief Genera la carta del mazo personal de cada jugador
     * @param numeroJugador Numero del jugador a quien se le generara la carta del mazo
     */
    void generarCartaMazoJugador(int numeroJugador);

    /**
     * @brief Se encarga de esconder la carta de cada jugador cuando no es su
     * turno
     */
    void borrarCartasJugadores();

    /**
     * @brief Cambia el turno entre ambos jugadores
     * @param numeroJugador Numero que corresponde al jugador a quien se va a cambiar de turno
     */
    void cambiarTurno(int numeroJugador);

    /**
     * @brief Inserta una carta en la pila. Se refiere al proceso que conlleva,
     * desde la revision de reglas hasta las acciones que eso desencadena
     * @param informacionCarta Un String que contiene la informacion necesaria de la carta para poder identificarla
     * @param tipoPila El tipo de pila donde se insertara dicha carta
     * @param numeroPila El numero de la pila donde se va a insertar la carta
     */
    void insertarCartaEnLaPila(std::string informacionCarta, int tipoPila,
                               int numeroPila);

    /**
     * @brief Desactiva la mano de un jugador cuando no es su turno
     * @param jugador Numero del jugador a quien se desea desactivar la mano
     */
    void desactivarManoJugador(int jugador);

    /**
     * @brief Activa la mano de un jugador cuando le corresponde jugar
     * @param jugador Numero del jugador a quien se desea activar la mano
     */
    void activarManoJugador(int jugador);

    /**
     * @brief Puntero a interfaz de pantalla juego
     */
    Ui::PantallaJuego *ui;

    /**
     * @brief Tabler del juego
     */
    Tablero tablero;

    /**
     * @brief Espacios de la interfaz
     */
    vector<vector<QListWidget*>> espacios;

    /**
     * @brief mapa utilizado para accesar a la informacion de la carta
     */
    map<string,string> informacionCartaActual;

    /**
     * @brief Contador para pila central
     */
    int contadorPilaCentral1 = 0;

    /**
     * @brief Contador auxiliar para pila central
     */
    int contadorAuxPilaCentral1 = 0;
};

#endif // PANTALLAJUEGO_H
