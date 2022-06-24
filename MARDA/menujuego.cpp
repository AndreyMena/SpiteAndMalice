#include "menujuego.h"
#include "ui_menujuego.h"
#include "reglas.h""

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
    mazo *m = new mazo;
    m->crearMazo();

    EleccionJugador *pantallaEleccion = new EleccionJugador();
    pantallaEleccion->show();
    this->hide();
/*
    PantallaJuego *pantallaJuego = new PantallaJuego();
    pantallaJuego->show();
    this->hide();
    */
}


void MenuJuego::on_pushButton_4_clicked()
{
    Reglas *reglas = new Reglas();
    reglas->show();
    this->hide();
}

