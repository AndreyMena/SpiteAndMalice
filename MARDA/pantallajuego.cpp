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
    this->ui->pushButton_2->setStyleSheet(
                "image: url(:/img/img/7_of_clubs.png)");
}
