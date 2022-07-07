#include "pantallajuego.h"
#include "ui_pantallajuego.h"
#include "menujuego.h"
#include "mazo.h"
#include <QListWidgetItem>
#include <QDrag>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QPainter>

//#include <fstream>

PantallaJuego::PantallaJuego(Tablero tablero) :
    QWidget(nullptr),
    ui(new Ui::PantallaJuego),
    tablero(tablero)
{
    ui->setupUi(this);

    // Se generan los espacios para cada jugador
    this->espacios[1] = this->ui->listWidget;
    this->espacios[2] = this->ui->listWidget_3;

    for (auto &&n : tablero.obtenerJugadores()) {
        if (this->tablero.esTurnoJugador(n.obtenerNumeroJugador())) {
            vector<Carta> cartas = n.obtenerMano();
            for (auto &&carta : cartas) {
                generarCarta(carta, espacios[n.obtenerNumeroJugador()]);
            }
        } else {
            for (int i = 0; i < 5; i++) {
                generarCartaOculta(espacios[n.obtenerNumeroJugador()]);
            }
        }
    }
}

PantallaJuego::~PantallaJuego()
{
    delete ui;
}

void PantallaJuego::generarCarta(Carta carta, QListWidget* espacio) {
    string url = URL_POR_DEFECTO+carta.obtenerNombre() + EXTENSION_POR_DEFECTO;
    QString stringCarta(url.data());
    QListWidgetItem* nuevaCarta = new QListWidgetItem(espacio);
    nuevaCarta->setIcon(QIcon(stringCarta));
    //nuevaCarta->setData(Qt::UserRole, QVariant("image: url(:/img/img/7_of_clubs.png)"));
    nuevaCarta->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsDragEnabled);
}

void PantallaJuego::generarCartaOculta(QListWidget* espacio) {
    QString stringCarta(URL_REVERSO_CARTA_POR_DEFECTO.data());
    QListWidgetItem* nuevaCarta = new QListWidgetItem(espacio);
    nuevaCarta->setIcon(QIcon(stringCarta));
    //nuevaCarta->setData(Qt::UserRole, QVariant("image: url(:/img/img/7_of_clubs.png)"));
    nuevaCarta->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
}

/*void PantallaJuego::on_pushButton_2_clicked()
{
    this->ui->pushButton_2->setStyleSheet(
                "image: url(:/img/img/7_of_clubs.png)");
}*/

void PantallaJuego::on_listWidget_2_itemEntered(QListWidgetItem *item)
{
    std::cout << "Hola mundo" << std::endl;
}

void PantallaJuego::on_listWidget_2_itemChanged(QListWidgetItem *item)
{
    std::cout << "Hola mundo segundo intento" << std::endl;
}


void PantallaJuego::on_listWidget_5_itemChanged(QListWidgetItem *item)
{

}


void PantallaJuego::on_listWidget_2_itemActivated(QListWidgetItem *item)
{
    std::cout << "Hola mundo tercer intento" << std::endl;
}


void PantallaJuego::on_listWidget_2_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    std::cout << "Hola mundo cuarto intento" << std::endl;
}


void PantallaJuego::on_listWidget_2_currentRowChanged(int currentRow)
{
    std::cout << "Hola mundo quinto intento" << std::endl;
}

