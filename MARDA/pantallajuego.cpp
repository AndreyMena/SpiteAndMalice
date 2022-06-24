#include "pantallajuego.h"
#include "ui_pantallajuego.h"
#include "menujuego.h"
#include "mazo.h"
#include <fstream>

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

    QPixmap pixmap("../PNG-cards-1.3/ace_of_clubs");
    this->ui->label->setPixmap(pixmap);
    this->ui->label->setMask(pixmap.mask());  //  C:\Users\andre\OneDrive\Escritorio\UCR\GitHub\SpiteAndMalice\PNG-cards-1.3
    this->ui->label->show();

    QPixmap pixmap1("../PNG-cards-1.3/ace_of_spades");
    this->ui->label_2->setPixmap(pixmap1);
    this->ui->label_2->setMask(pixmap1.mask());  //  C:\Users\andre\OneDrive\Escritorio\UCR\GitHub\SpiteAndMalice\PNG-cards-1.3
    this->ui->label_2->show();
    IniciarCartas();

}

void PantallaJuego::IniciarCartas()
{
    std::string nombreArchivo = "videojuegos.txt";
    std::ifstream archivo("../Cartas.txt");

    std::string linea;
    // Obtener línea de archivo, y almacenar contenido en "linea"
    while (getline(archivo, linea)) {
        // Lo vamos imprimiendo
        std::cout << linea << std::endl;
    }

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
