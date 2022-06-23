#include "pantallajuego.h"
#include "ui_pantallajuego.h"
#include "menujuego.h"
#include "mazo.h"

PantallaJuego::PantallaJuego(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PantallaJuego)
{
    ui->setupUi(this);
    /*mazo mazoBryan;
    std::string cartaSacadaDeMazo;
    cartaSacadaDeMazo = mazoBryan.obtenerCartaJugadorUno();
    std::cout << "Llega aca: " << cartaSacadaDeMazo << std::endl;

    QString carta = QString::fromStdString(cartaSacadaDeMazo);*/
    //this->ui->pushButton_9->setText("carta");
    QPixmap pixmap("C:/Users/pc/Documents/PROYECTO_MARDA/SpiteAndMalice/imagenes/as");
    this->ui->label->setPixmap(pixmap);
    this->ui->label->setMask(pixmap.mask());
    this->ui->label->show();
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
