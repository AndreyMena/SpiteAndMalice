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
#include <QDrag>
#include <QDropEvent>
#include <QtDebug>
#include <QAbstractItemView>

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
    //this->ui->listWidgetJ1_1.pos
    if (this->tablero.esTurnoJugador(1)) {
        this->ui->listWidgetJ2_1->setAcceptDrops(0);
        this->ui->listWidgetJ2_2->setAcceptDrops(0);
        this->ui->listWidgetJ2_3->setAcceptDrops(0);
        this->ui->listWidgetJ2_4->setAcceptDrops(0);
    }else{
        this->ui->listWidgetJ1_1->setAcceptDrops(0);
        this->ui->listWidgetJ1_2->setAcceptDrops(0);
        this->ui->listWidgetJ1_3->setAcceptDrops(0);
        this->ui->listWidgetJ1_4->setAcceptDrops(0);
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
    nuevaCarta->setText(stringCarta);
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
    std::cout << item->text().toStdString() << std::endl;
    if (this->ui->manoJugador1_5->count() == 1) {
        std::cout << "Se puede cambiar la carta" <<std::endl;
        QListWidgetItem *l1 = new QListWidgetItem(this->ui->manoJugador1_5);
        l1->setIcon(QIcon(":/img/img/7_of_clubs.png"));
        l1->setData(Qt::UserRole, QVariant("image: url(:/img/img/7_of_clubs.png)"));
        l1->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsDragEnabled);
    }

    vector<Carta> nuevasCartas = this->tablero.obtenerMazo().dividirMazo(3).obtenerCartasMazo();
    cout << "HOLAAAAAAA"<<endl;

    QString stringCarta(URL_REVERSO_CARTA_POR_DEFECTO.data());

    cout << ui->manoJugador1_1->count() << endl;

    cout << ui->manoJugador1_1->item(0)->text().toStdString() << endl;
    ui->manoJugador1_1->item(0)->setIcon(QIcon(stringCarta));
    //ui->manoJugador1_1.dr
    //ui->manoJugador1_1->currentItem()->setIcon(QIcon(stringCarta));
}


void PantallaJuego::on_listWidget_2_itemEntered(QListWidgetItem *item)
{
    cout << "heyyyy" << endl;
}

// Primer Jugador
void PantallaJuego::on_descarteJ1_1_clicked()
{
    if (this->ui->listWidgetJ1_1->count() >= 1) {
        cout << "Hay "<< this->ui->listWidgetJ1_1->count() << " elementos "<<endl;
    }else{
        cout << "No hay elementos"<<endl;
    }
    for (int i = 0; i < this->ui->listWidgetJ1_1->count(); i++) {
        qDebug() << this->ui->listWidgetJ1_1->item(i)->text();
    }

}


void PantallaJuego::on_descarteJ1_2_clicked()
{

}


void PantallaJuego::on_descarteJ1_3_clicked()
{

}


void PantallaJuego::on_descarteJ1_4_clicked()
{

}

// Segundo Jugador

void PantallaJuego::on_descarteJ2_1_clicked()
{

}


void PantallaJuego::on_descarteJ2_2_clicked()
{

}


void PantallaJuego::on_descarteJ2_3_clicked()
{

}


void PantallaJuego::on_descarteJ2_4_clicked()
{

}

void PantallaJuego::desactivarManoJugador(int jugador) {
    if (jugador == 1) {
        this->ui->manoJugador1_1->setEnabled(0);
        this->ui->manoJugador1_2->setEnabled(0);
        this->ui->manoJugador1_3->setEnabled(0);
        this->ui->manoJugador1_4->setEnabled(0);
        this->ui->manoJugador1_5->setEnabled(0);

        this->ui->manoJugador1_1->setDragEnabled(0);
        this->ui->manoJugador1_2->setDragEnabled(0);
        this->ui->manoJugador1_3->setDragEnabled(0);
        this->ui->manoJugador1_4->setDragEnabled(0);
        this->ui->manoJugador1_5->setDragEnabled(0);
    }else if (jugador == 2){
        this->ui->manoJugador2_1->setEnabled(0);
        this->ui->manoJugador2_2->setEnabled(0);
        this->ui->manoJugador2_3->setEnabled(0);
        this->ui->manoJugador2_4->setEnabled(0);
        this->ui->manoJugador2_5->setEnabled(0);

        this->ui->manoJugador2_1->setDragEnabled(0);
        this->ui->manoJugador2_2->setDragEnabled(0);
        this->ui->manoJugador2_3->setDragEnabled(0);
        this->ui->manoJugador2_4->setDragEnabled(0);
        this->ui->manoJugador2_5->setDragEnabled(0);
    }
}

void PantallaJuego::activarManoJugador(int jugador) {
    if (jugador == 1) {
        this->ui->manoJugador1_1->setEnabled(1);
        this->ui->manoJugador1_2->setEnabled(1);
        this->ui->manoJugador1_3->setEnabled(1);
        this->ui->manoJugador1_4->setEnabled(1);
        this->ui->manoJugador1_5->setEnabled(1);

        this->ui->manoJugador1_1->setDragEnabled(1);
        this->ui->manoJugador1_2->setDragEnabled(1);
        this->ui->manoJugador1_3->setDragEnabled(1);
        this->ui->manoJugador1_4->setDragEnabled(1);
        this->ui->manoJugador1_5->setDragEnabled(1);
    }else if (jugador == 2){
        this->ui->manoJugador2_1->setEnabled(1);
        this->ui->manoJugador2_2->setEnabled(1);
        this->ui->manoJugador2_3->setEnabled(1);
        this->ui->manoJugador2_4->setEnabled(1);
        this->ui->manoJugador2_5->setEnabled(1);

        this->ui->manoJugador2_1->setDragEnabled(1);
        this->ui->manoJugador2_2->setDragEnabled(1);
        this->ui->manoJugador2_3->setDragEnabled(1);
        this->ui->manoJugador2_4->setDragEnabled(1);
        this->ui->manoJugador2_5->setDragEnabled(1);
    }
}

// Pilas de descarte
void PantallaJuego::on_listWidgetJ1_1_itemChanged(QListWidgetItem *item)
{
    //desactivarManoJugador(1);
/*
    if (this->ui->listWidgetJ1_1->count() >= 1) {
        cout << "Hay "<< this->ui->listWidgetJ1_1->count() << " elementos "<<endl;
    }else{
        cout << "No hay elementos"<<endl;
    }
    for (int i = 0; i < this->ui->listWidgetJ1_1->count(); i++) {
        qDebug() << this->ui->listWidgetJ1_1->item(i)->text();
    }
    */
}

void PantallaJuego::on_listWidgetJ1_2_itemChanged(QListWidgetItem *item)
{
    desactivarManoJugador(1);
}


void PantallaJuego::on_listWidgetJ1_3_itemChanged(QListWidgetItem *item)
{
    desactivarManoJugador(1);
}

void PantallaJuego::on_listWidgetJ1_4_itemChanged(QListWidgetItem *item)
{
    desactivarManoJugador(1);
}


void PantallaJuego::on_listWidgetJ2_1_itemChanged(QListWidgetItem *item)
{
    desactivarManoJugador(2);
}


void PantallaJuego::on_listWidgetJ2_2_itemChanged(QListWidgetItem *item)
{
    desactivarManoJugador(2);
}


void PantallaJuego::on_listWidgetJ2_3_itemChanged(QListWidgetItem *item)
{
    desactivarManoJugador(2);
}


void PantallaJuego::on_listWidgetJ2_4_itemChanged(QListWidgetItem *item)
{
    desactivarManoJugador(2);
}

// Descartes
void PantallaJuego::on_descartarJ1_1_clicked()
{
    if (this->ui->listWidgetJ1_1->count() >= 1) {
        cout << "Hay "<< this->ui->listWidgetJ1_1->count() << " elementos "<<endl;
    }else{
        cout << "No hay elementos"<<endl;
    }
    for (int i = 0; i < this->ui->listWidgetJ1_1->count(); i++) {
        qDebug() << this->ui->listWidgetJ1_1->item(i)->text();
    }
}


void PantallaJuego::on_descartarJ1_2_clicked()
{

}


void PantallaJuego::on_descartarJ1_3_clicked()
{

}


void PantallaJuego::on_descartarJ1_4_clicked()
{

}

//

void PantallaJuego::on_descartarJ2_1_clicked()
{

}


void PantallaJuego::on_descartarJ2_2_clicked()
{

}


void PantallaJuego::on_descartarJ2_3_clicked()
{

}


void PantallaJuego::on_descartarJ2_4_clicked()
{

}

//Pilas
void PantallaJuego::on_boton_pilacentral_1_clicked()
{

}


void PantallaJuego::on_boton_pilacentral_2_clicked()
{

}


void PantallaJuego::on_boton_pilacentral_3_clicked()
{

}

