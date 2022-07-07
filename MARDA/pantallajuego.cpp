#include "pantallajuego.h"
#include "ui_pantallajuego.h"
#include "menujuego.h"
#include "mazo.h"
#include <QListWidgetItem>
#include <QDrag>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QPainter>
#include <QListWidget>
#include <QMainWindow>

//#include <fstream>
#include <QtDebug>
PantallaJuego::PantallaJuego(Tablero tablero) :
    QWidget(nullptr),
    ui(new Ui::PantallaJuego),
    tablero(tablero)
{
    ui->setupUi(this);

    // Se generan los espacios para cada jugador
    vector<vector<QListWidget*>> espacios;

    //Espacio de cartas Jugador 1
    vector<QListWidget*> espaciosJ1;
    espaciosJ1.push_back(this->ui->manoJugador1_1);
    espaciosJ1.push_back(this->ui->manoJugador1_2);
    espaciosJ1.push_back(this->ui->manoJugador1_3);
    espaciosJ1.push_back(this->ui->manoJugador1_4);
    espaciosJ1.push_back(this->ui->manoJugador1_5);

    //Espacio de cartas Jugador 2
    vector<QListWidget*> espaciosJ2;
    espaciosJ2.push_back(this->ui->manoJugador2_1);
    espaciosJ2.push_back(this->ui->manoJugador2_2);
    espaciosJ2.push_back(this->ui->manoJugador2_3);
    espaciosJ2.push_back(this->ui->manoJugador2_4);
    espaciosJ2.push_back(this->ui->manoJugador2_5);

    espacios.push_back(espaciosJ1);
    espacios.push_back(espaciosJ2);

    for (auto &&n : tablero.obtenerJugadores()) {
        if (this->tablero.esTurnoJugador(n.obtenerNumeroJugador())) {
            vector<Carta> cartas = n.obtenerMano();
            int espacioContador = 0;
            for (auto &&carta : cartas) {
                generarCarta(carta, espacios[n.obtenerNumeroJugador()-1][espacioContador]);
                espacioContador++;
            }
        } else {
            for (int i = 0; i < 5; i++) {
                generarCartaOculta(espacios[n.obtenerNumeroJugador()-1][i]);
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

void PantallaJuego::on_listWidget_2_itemChanged(QListWidgetItem *item)
{
    std::cout << "Ingreso a pila 1" <<  std::endl;
    /*
    qDebug().nospace() << "abc" << qPrintable(item->icon().name()) << "def";
    qDebug("abc" + item->icon().name().toLatin1() + "def");
    qDebug(qUtf8Printable(item->icon().name()));
    cout << item->icon().name().size() << endl;
    cout << item->text().size() << endl;
    cout << item->whatsThis().size()<< endl;
    */
    //cout << item->listWidget().<< endl;
}

void PantallaJuego::on_listWidget_5_itemChanged(QListWidgetItem *item)
{
    std::cout << "Ingreso a pila 2" << std::endl;
}


void PantallaJuego::on_listWidget_6_itemChanged(QListWidgetItem *item)
{
    std::cout << "Ingreso a pila 3" <<std::endl;
}


void PantallaJuego::on_listWidget_8_itemChanged(QListWidgetItem *item)
{
    // Agregar los siguientes métodos
    // Voltear cartas de jugador que termina su jugada
    // Voltear las del jugador en turno
    // Llenar las cartas del otro jugador
    std::cout << "Esto pasa con el descarte" <<std::endl;
    std::cout << "Items: " << this->ui->manoJugador1_5->count() << std::endl;

    if (this->ui->manoJugador1_5->count() == 1) {
        std::cout << "Se puede cambiar la carta" <<std::endl;
        QListWidgetItem *l1 = new QListWidgetItem(this->ui->manoJugador1_5);
        l1->setIcon(QIcon(":/img/img/7_of_clubs.png"));
        l1->setData(Qt::UserRole, QVariant("image: url(:/img/img/7_of_clubs.png)"));
        l1->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsDragEnabled);
    }
}

