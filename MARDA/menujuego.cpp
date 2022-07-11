#include "menujuego.h"
#include "ui_menujuego.h"
#include "reglas.h"
#include "pantallajuego.h"
#include "tablero.h"
#include <fstream>

MenuJuego::MenuJuego(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MenuJuego)
{
    ui->setupUi(this);
}

MenuJuego::~MenuJuego()
{
    delete ui;
}

void MenuJuego::on_pushButton_clicked()
{
    EleccionJugador *pantallaEleccion = new EleccionJugador();
    pantallaEleccion->show();
    this->hide();
}


void MenuJuego::on_pushButton_4_clicked()
{
    Reglas *reglas = new Reglas();
    reglas->show();
    this->hide();
}


void MenuJuego::on_cargarPartida_clicked()
{
    Tablero tablero(2);
    std::ifstream ifs ("../bitacora.txt", std::ifstream::in);
    string line;
    std::getline(ifs, line);
    cout << "LA LINEA: "<<line<< endl;
    //tablero.asignarTurno(TURNO_JUGADOR2);
    //PantallaJuego *pantallaJuego = new PantallaJuego(tablero);
    //pantallaJuego->show();
    //this->hide();
}

