#include "pantallajuego.h"
#include "ui_pantallajuego.h"
#include "menujuego.h"
#include "mazo.h"
//#include <fstream>

PantallaJuego::PantallaJuego(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PantallaJuego)
{
    ui->setupUi(this);
    mazo mazoBryan;
    std::string cartaSacadaDeMazo;
    //cartaSacadaDeMazo = mazoBryan.obtenerCartaJugadorUno();
    //std::cout << "Llega aca: " << cartaSacadaDeMazo << std::endl;

    //QString carta = QString::fromStdString(cartaSacadaDeMazo);
    //this->ui->pushButton_9->setText("carta");
    mazoBryan.IniciarCartas();

    QPixmap pixmap("../PNG-cards-1.3/ace_of_clubs");
    this->ui->label_1->setPixmap(pixmap);
    this->ui->label_1->setMask(pixmap.mask());  //  C:\Users\andre\OneDrive\Escritorio\UCR\GitHub\SpiteAndMalice\PNG-cards-1.3
    this->ui->label_1->show();

    QPixmap pixmap1("../PNG-cards-1.3/2_of_diamonds");
    this->ui->label_2->setPixmap(pixmap1);
    this->ui->label_2->setMask(pixmap1.mask());  //  C:\Users\andre\OneDrive\Escritorio\UCR\GitHub\SpiteAndMalice\PNG-cards-1.3
    this->ui->label_2->show();

    QPixmap pixmap2("../PNG-cards-1.3/queen_of_spades2");
    this->ui->label_3->setPixmap(pixmap2);
    this->ui->label_3->setMask(pixmap2.mask());  //  C:\Users\andre\OneDrive\Escritorio\UCR\GitHub\SpiteAndMalice\PNG-cards-1.3
    this->ui->label_3->show();

    QPixmap pixmap3("../PNG-cards-1.3/6_of_hearts");
    this->ui->label_4->setPixmap(pixmap3);
    this->ui->label_4->setMask(pixmap3.mask());  //  C:\Users\andre\OneDrive\Escritorio\UCR\GitHub\SpiteAndMalice\PNG-cards-1.3
    this->ui->label_4->show();

    QPixmap pixmap4("../PNG-cards-1.3/3_of_diamonds");
    this->ui->label_5->setPixmap(pixmap4);
    this->ui->label_5->setMask(pixmap4.mask());  //  C:\Users\andre\OneDrive\Escritorio\UCR\GitHub\SpiteAndMalice\PNG-cards-1.3
    this->ui->label_5->show();

    //Segundo jugador
    QPixmap pixmap5("../PNG-cards-1.3/ace_of_clubs");
    this->ui->label_6->setPixmap(pixmap5);
    this->ui->label_6->setMask(pixmap5.mask());  //  C:\Users\andre\OneDrive\Escritorio\UCR\GitHub\SpiteAndMalice\PNG-cards-1.3
    this->ui->label_6->show();

    QPixmap pixmap6("../PNG-cards-1.3/2_of_diamonds");
    this->ui->label_7->setPixmap(pixmap6);
    this->ui->label_7->setMask(pixmap6.mask());  //  C:\Users\andre\OneDrive\Escritorio\UCR\GitHub\SpiteAndMalice\PNG-cards-1.3
    this->ui->label_7->show();

    QPixmap pixmap7("../PNG-cards-1.3/queen_of_spades2");
    this->ui->label_8->setPixmap(pixmap7);
    this->ui->label_8->setMask(pixmap7.mask());  //  C:\Users\andre\OneDrive\Escritorio\UCR\GitHub\SpiteAndMalice\PNG-cards-1.3
    this->ui->label_8->show();

    QPixmap pixmap8("../PNG-cards-1.3/6_of_hearts");
    this->ui->label_9->setPixmap(pixmap8);
    this->ui->label_9->setMask(pixmap8.mask());  //  C:\Users\andre\OneDrive\Escritorio\UCR\GitHub\SpiteAndMalice\PNG-cards-1.3
    this->ui->label_9->show();

    QPixmap pixmap9("../PNG-cards-1.3/3_of_diamonds");
    this->ui->label_10->setPixmap(pixmap9);
    this->ui->label_10->setMask(pixmap9.mask());  //  C:\Users\andre\OneDrive\Escritorio\UCR\GitHub\SpiteAndMalice\PNG-cards-1.3
    this->ui->label_10->show();
    //IniciarCartas();

}
/*
void PantallaJuego::IniciarCartas()
{

    std::ifstream archivo("../Cartas.txt");

    std::string linea;
    // Obtener línea de archivo, y almacenar contenido en "linea"
    while (std::getline(archivo, linea)) {
        // Lo vamos imprimiendo
        std::cout << linea << std::endl;
    }


}
*/


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
