#include "pantallajuego.h"
#include "ui_pantallajuego.h"
#include "menujuego.h"
#include "mazo.h"

PantallaJuego::PantallaJuego(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PantallaJuego)
{
    ui->setupUi(this);
    mazo mazoBryan;
    std::string cartaSacadaDeMazo;
    cartaSacadaDeMazo = mazoBryan.obtenerCartaJugadorUno();
    std::cout << "Llega aca: " << cartaSacadaDeMazo << std::endl;

    QString carta = QString::fromStdString(cartaSacadaDeMazo);
    this->ui->label_5->setText(carta);
}

PantallaJuego::~PantallaJuego()
{
    delete ui;
}

void PantallaJuego::on_pushButton_2_clicked()
{
    //this->ui->label_5->setText("As de corazones");
    //mazo *m = new mazo();
    //m->CrearMazo()
    //this->ui->label_5->setText("As de corazones");
}
