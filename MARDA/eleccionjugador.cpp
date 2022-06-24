#include "eleccionjugador.h"
#include "ui_eleccionjugador.h"
#include "pantallajuego.h".h"

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
void EleccionJugador::on_pushButton_3_clicked()
{
    PantallaJuego *pantallaJuego = new PantallaJuego();
    pantallaJuego->show();
    this->hide();
}

//Turno 2
void EleccionJugador::on_pushButton_4_clicked()
{
    PantallaJuego *pantallaJuego = new PantallaJuego();
    pantallaJuego->show();
    this->hide();
}

