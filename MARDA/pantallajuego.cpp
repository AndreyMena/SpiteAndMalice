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

#include <QDropEvent>
#include <QtDebug>
#include <QAbstractItemView>

#include "ganador1.h"
#include "ganador2.h"

PantallaJuego::PantallaJuego(Tablero tablero) :
    QWidget(nullptr),
    ui(new Ui::PantallaJuego),
    tablero(tablero)
{
    ui->setupUi(this);

    //Espacio de cartas Jugador 1
    vector<QListWidget*> espaciosJ1;
    espaciosJ1.push_back(this->ui->manoJugador1_1);
    espaciosJ1.push_back(this->ui->manoJugador1_2);
    espaciosJ1.push_back(this->ui->manoJugador1_3);
    espaciosJ1.push_back(this->ui->manoJugador1_4);
    espaciosJ1.push_back(this->ui->manoJugador1_5);
    espaciosJ1.push_back(this->ui->mazo_personal_J1);
    //Espacio de cartas Jugador 2
    vector<QListWidget*> espaciosJ2;
    espaciosJ2.push_back(this->ui->manoJugador2_1);
    espaciosJ2.push_back(this->ui->manoJugador2_2);
    espaciosJ2.push_back(this->ui->manoJugador2_3);
    espaciosJ2.push_back(this->ui->manoJugador2_4);
    espaciosJ2.push_back(this->ui->manoJugador2_5);
    espaciosJ2.push_back(this->ui->mazo_personal_J2);

    // Se generan los espacios para cada jugador
    this->espacios.push_back(espaciosJ1);
    this->espacios.push_back(espaciosJ2);

    for (auto &&n : *tablero.obtenerJugadores()) {
        Mazo *mazoJugador = n.obtenerMazoPersonal();
        Carta cartaMazoPersonal = mazoJugador->sacarCartaMazo(n.obtenerMazoPersonal()->obtenerCartasMazo().size()-1);
        if (this->tablero.esTurnoJugador(n.obtenerNumeroJugador())) {
            vector<Carta> *cartas = n.obtenerMano();
            int espacioContador = 0;
            for (auto &&carta : *cartas) {
                generarCarta(carta, espacios[n.obtenerNumeroJugador()-1][espacioContador], n.obtenerNumeroJugador(), espacioContador);
                espacioContador++;
            }
            generarCarta(cartaMazoPersonal, espacios[n.obtenerNumeroJugador()-1][espacioContador], n.obtenerNumeroJugador(), -1);
        } else {
            for (int i = 0; i < 5; i++) {
                generarCartaOculta(espacios[n.obtenerNumeroJugador()-1][i]);
            }
            generarCarta(cartaMazoPersonal, espacios[n.obtenerNumeroJugador()-1][5], n.obtenerNumeroJugador(), -1);
        }
    }
    //Desabilita las pilas del rival
    if (this->tablero.esTurnoJugador(1)) {
        this->ui->piladescarte_J2_1->setAcceptDrops(0);
        this->ui->piladescarte_J2_2->setAcceptDrops(0);
        this->ui->piladescarte_J2_3->setAcceptDrops(0);
        this->ui->piladescarte_J2_4->setAcceptDrops(0);
    }else {
        this->ui->piladescarte_J1_1->setAcceptDrops(0);
        this->ui->piladescarte_J1_2->setAcceptDrops(0);
        this->ui->piladescarte_J1_3->setAcceptDrops(0);
        this->ui->piladescarte_J1_4->setAcceptDrops(0);
    }
}

PantallaJuego::~PantallaJuego()
{
    delete ui;
}

void PantallaJuego::generarCarta(Carta carta, QListWidget* espacio, int numeroJugador, int posicionCarta) {
    string url = URL_POR_DEFECTO+carta.obtenerNombre() + EXTENSION_POR_DEFECTO;
    QString stringCarta(url.data());
    string texto = carta.obtenerNombre() + "," + std::to_string(carta.obtenerValor())
            + "," + std::to_string(numeroJugador) + "," + std::to_string(posicionCarta);
    QString textoCarta(texto.data());
    QListWidgetItem* nuevaCarta = new QListWidgetItem(espacio);
    nuevaCarta->setIcon(QIcon(stringCarta));
    nuevaCarta->setText(textoCarta);
    nuevaCarta->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsDragEnabled);
}

void PantallaJuego::generarCartaOculta(QListWidget* espacio) {
    QString stringCarta(URL_REVERSO_CARTA_POR_DEFECTO.data());
    QListWidgetItem* nuevaCarta = new QListWidgetItem(espacio);
    nuevaCarta->setIcon(QIcon(stringCarta));
    nuevaCarta->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
}

void PantallaJuego::cambiarTurno(int numeroJugador) {
    if (numeroJugador == 1) {
        tablero.asignarTurno(2);
    } else {
        tablero.asignarTurno(1);
    }
    //Desabilita las pilas del rival
    if (this->tablero.esTurnoJugador(1)) {
        this->ui->piladescarte_J1_1->setAcceptDrops(1);
        this->ui->piladescarte_J1_2->setAcceptDrops(1);
        this->ui->piladescarte_J1_3->setAcceptDrops(1);
        this->ui->piladescarte_J1_4->setAcceptDrops(1);
        this->ui->piladescarte_J2_1->setAcceptDrops(0);
        this->ui->piladescarte_J2_2->setAcceptDrops(0);
        this->ui->piladescarte_J2_3->setAcceptDrops(0);
        this->ui->piladescarte_J2_4->setAcceptDrops(0);
    } else {
        this->ui->piladescarte_J1_1->setAcceptDrops(0);
        this->ui->piladescarte_J1_2->setAcceptDrops(0);
        this->ui->piladescarte_J1_3->setAcceptDrops(0);
        this->ui->piladescarte_J1_4->setAcceptDrops(0);
        this->ui->piladescarte_J2_1->setAcceptDrops(1);
        this->ui->piladescarte_J2_2->setAcceptDrops(1);
        this->ui->piladescarte_J2_3->setAcceptDrops(1);
        this->ui->piladescarte_J2_4->setAcceptDrops(1);
    }
    for (auto &&n : *tablero.obtenerJugadores()) {
        if (this->tablero.esTurnoJugador(n.obtenerNumeroJugador())) {
            activarManoJugador(n.obtenerNumeroJugador());
            n.rellenarMano();
            vector<Carta> *cartas = n.obtenerMano();
            int espacioContador = 0;
            for (auto &&carta : *cartas) {
                for(int i = 0; i < this->espacios[n.obtenerNumeroJugador()-1][espacioContador]->count(); ++i)
                {
                    QListWidgetItem* cartaBorrada = this->espacios[n.obtenerNumeroJugador()-1][espacioContador]->item(i);
                    delete espacios[n.obtenerNumeroJugador()-1][espacioContador]->takeItem(espacios[n.obtenerNumeroJugador()-1][espacioContador]->row(cartaBorrada));
                }
                generarCarta(carta, espacios[n.obtenerNumeroJugador()-1][espacioContador], n.obtenerNumeroJugador(), espacioContador);
                espacioContador++;
            }
        } else {
            //desactivarManoJugador(n.obtenerNumeroJugador());
            for (int i = 0; i < 5; i++) {
                for(int j = 0; j < this->espacios[n.obtenerNumeroJugador()-1][j]->count(); ++j)
                {
                    QListWidgetItem* cartaBorrada = this->espacios[n.obtenerNumeroJugador()-1][i]->item(j);
                    delete espacios[n.obtenerNumeroJugador()-1][i]->takeItem(espacios[n.obtenerNumeroJugador()-1][i]->row(cartaBorrada));
                }
                generarCartaOculta(espacios[n.obtenerNumeroJugador()-1][i]);
            }
        }
    }
}

void PantallaJuego::insertarCartaEnLaPila(std::string informacionCarta, int tipoPila, int numeroPila) {
    //Modularizar este codigo
    std::string auxiliar = "";
    stringstream stringInformacionCartaString(informacionCarta);

    std::getline(stringInformacionCartaString,auxiliar,',');
    string nombreCarta = auxiliar;

    std::getline(stringInformacionCartaString,auxiliar,',');
    int valorCarta = stoi(auxiliar);

    std::getline(stringInformacionCartaString,auxiliar,',');
    int numeroJugador = stoi(auxiliar);

    std::getline(stringInformacionCartaString,auxiliar,',');
    int posicionCarta = stoi(auxiliar);

    Jugador *jugador = tablero.obtenerJugador(numeroJugador);
    if (posicionCarta == -1) {
        int posicion = jugador->obtenerMazoPersonal()->obtenerCartasMazo().size()-1;
        if (posicion != -1) {
            Carta cartaMazoPersonal = jugador->obtenerMazoPersonal()->sacarCartaMazo(posicion);
            generarCarta(cartaMazoPersonal, this->espacios[numeroJugador-1][5],numeroJugador, -1);
        } else {
            if (numeroJugador == 1) {
                Ganador1 *ganador1 = new Ganador1();
                ganador1->show();
            } else {
                Ganador2 *ganador2 = new Ganador2();
                ganador2->show();
            }
            this->hide();
        }
    } else {
        Carta cartaVacia("Vacia", 0);
        jugador->sacarCartaMano(posicionCarta);
        jugador->agregarCartaMano(cartaVacia, posicionCarta);

        cout << "Mano:" << endl;
        for (auto &&n : *jugador->obtenerMano()) {
            cout << "Carta: " << n.obtenerNombre() << " " << n.obtenerValor() << endl;
        }
    }

    Carta cartaJugador(nombreCarta, valorCarta);
    std::cout << "Carta Jugador: " << cartaJugador.obtenerNombre() << " " << cartaJugador.obtenerValor() << std::endl;
    jugador->agregarCartaPila(cartaJugador, tipoPila, numeroPila-1);
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

// Pilas Descartes Jugador1

void PantallaJuego::on_descartarJ1_1_clicked()
{
    if (this->ui->piladescarte_J1_1->count() >= 1) {
        insertarCartaEnLaPila( this->ui->piladescarte_J1_1->item(0)->text().toStdString(), TIPO_PILA_DESCARTE, 1);
        cambiarTurno(1);
    }
}

void PantallaJuego::on_descartarJ1_2_clicked()
{
    if (this->ui->piladescarte_J1_2->count() >= 1) {
        insertarCartaEnLaPila( this->ui->piladescarte_J1_2->item(0)->text().toStdString(), TIPO_PILA_DESCARTE, 2);
        cambiarTurno(1);
    }
}


void PantallaJuego::on_descartarJ1_3_clicked()
{
    if (this->ui->piladescarte_J1_3->count() >= 1) {
        insertarCartaEnLaPila( this->ui->piladescarte_J1_3->item(0)->text().toStdString(), TIPO_PILA_DESCARTE, 3);
        cambiarTurno(1);
    }
}

void PantallaJuego::on_descartarJ1_4_clicked()
{
    if (this->ui->piladescarte_J1_4->count() >= 1) {
        insertarCartaEnLaPila( this->ui->piladescarte_J1_4->item(0)->text().toStdString(), TIPO_PILA_DESCARTE, 4);
        cambiarTurno(1);
    }
}

// Pilas Descarte Jugador 2

void PantallaJuego::on_descartarJ2_1_clicked()
{
    if (this->ui->piladescarte_J2_1->count() >= 1) {
        insertarCartaEnLaPila( this->ui->piladescarte_J2_1->item(0)->text().toStdString(), TIPO_PILA_DESCARTE, 1);
        cambiarTurno(2);
    }
}


void PantallaJuego::on_descartarJ2_2_clicked()
{
    if (this->ui->piladescarte_J2_2->count() >= 1) {
        insertarCartaEnLaPila( this->ui->piladescarte_J2_2->item(0)->text().toStdString(), TIPO_PILA_DESCARTE, 2);
        cambiarTurno(2);
    }
}


void PantallaJuego::on_descartarJ2_3_clicked()
{
    if (this->ui->piladescarte_J2_3->count() >= 1) {
        insertarCartaEnLaPila( this->ui->piladescarte_J2_3->item(0)->text().toStdString(), TIPO_PILA_DESCARTE, 3);
        cambiarTurno(2);
    }
}


void PantallaJuego::on_descartarJ2_4_clicked()
{
    if (this->ui->piladescarte_J2_4->count() >= 1) {
        insertarCartaEnLaPila( this->ui->piladescarte_J2_4->item(0)->text().toStdString(), TIPO_PILA_DESCARTE, 4);
        cambiarTurno(2);
    }
}

//Pilas Centrales

void PantallaJuego::on_pilacentral_1_itemChanged(QListWidgetItem *item)
{
    for(int i = 1; i < this->ui->pilacentral_1->count(); ++i)
    {
        QListWidgetItem* cartaBorrada = this->ui->pilacentral_1->item(i);
        delete ui->pilacentral_1->takeItem(ui->pilacentral_1->row(cartaBorrada));
    }
}


void PantallaJuego::on_pilacentral_2_itemChanged(QListWidgetItem *item)
{
    for(int i = 1; i < this->ui->pilacentral_2->count(); ++i)
    {
        QListWidgetItem* cartaBorrada = this->ui->pilacentral_2->item(i);
        delete ui->pilacentral_2->takeItem(ui->pilacentral_2->row(cartaBorrada));
    }
}


void PantallaJuego::on_pilacentral_3_itemChanged(QListWidgetItem *item)
{
    for(int i = 1; i < this->ui->pilacentral_3->count(); ++i)
    {
        QListWidgetItem* cartaBorrada = this->ui->pilacentral_3->item(i);
        delete ui->pilacentral_3->takeItem(ui->pilacentral_3->row(cartaBorrada));
    }
}

void PantallaJuego::on_boton_pilacentral_1_clicked()
{
    if (this->ui->pilacentral_1->count() >= 1) {
        insertarCartaEnLaPila( this->ui->pilacentral_1->item(0)->text().toStdString(), TIPO_PILA_CENTRAL, 1);
    }
}


void PantallaJuego::on_boton_pilacentral_2_clicked()
{
    if (this->ui->pilacentral_2->count() >= 1) {
        insertarCartaEnLaPila( this->ui->pilacentral_2->item(0)->text().toStdString(), TIPO_PILA_CENTRAL, 2);
    }
}


void PantallaJuego::on_boton_pilacentral_3_clicked()
{
    if (this->ui->pilacentral_3->count() >= 1) {
        insertarCartaEnLaPila( this->ui->pilacentral_3->item(0)->text().toStdString(), TIPO_PILA_CENTRAL, 3);
    }
}

