#include "eleccionjugador.h"
#include "ui_eleccionjugador.h"
#include "pantallajuego.h"

EleccionJugador::EleccionJugador(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EleccionJugador)
{
    ui->setupUi(this);
}

EleccionJugador::~EleccionJugador()
{
    delete ui;
}

//Turno 1
void EleccionJugador::on_eleccionJugador1_clicked()
{
    Tablero tablero(CANTIDAD_JUGADORES);
    tablero.asignarTurno(TURNO_JUGADOR1);
    PantallaJuego *pantallaJuego = new PantallaJuego(tablero, 0);
    pantallaJuego->show();
    this->hide();
}

//Turno 2
void EleccionJugador::on_eleccionJugador2_clicked()
{
    Tablero tablero(CANTIDAD_JUGADORES);
    tablero.asignarTurno(TURNO_JUGADOR2);
    PantallaJuego *pantallaJuego = new PantallaJuego(tablero, 0);
    pantallaJuego->show();
    this->hide();
}
