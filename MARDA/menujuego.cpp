#include "menujuego.h"
#include "ui_menujuego.h"
#include "reglas.h"
#include "pantallajuego.h"
#include "tablero.h"
#include <fstream>
#include <string>

#include "jugador.h"
#include "mazo.h"
#include "pilacentral.h"

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
    EleccionJugador *pantallaEleccion = new EleccionJugador();
    pantallaEleccion->show();
    this->hide();
}

void MenuJuego::on_pushButton_4_clicked()
{
    Reglas *reglas = new Reglas();
    reglas->show();
    this->hide();
}


void MenuJuego::on_cargarPartida_clicked()
{
    std::ifstream ifs ("../bitacora.txt", std::ifstream::in);
    string line;
    std::getline(ifs, line);
    int turnoJugadorAux = stoi(line);
    cout << "LA LINEA: "<<turnoJugadorAux<< endl;
    std::getline(ifs, line);
    cout << "LA LINEA: "<<line<< endl;
    std::getline(ifs, line);
    cout << "LA LINEA: "<<line<< endl;

    vector<PilaCentral>* pilasCentralesAux = new vector<PilaCentral>();
    Mazo *mazoPilaC1 = new Mazo();
    PilaCentral pilacentral1(mazoPilaC1);

    while (line.compare("$") != 0) {
        cout << line << endl;
        if (line.at(0)=='a') {  //ace
            Carta carta(line, 1);
            pilacentral1.agregarCarta(carta);
        }else if (line.at(0)=='k'){  //king
            Carta carta(line, 1);
            pilacentral1.agregarCarta(carta);
        }else if (line.at(0)=='q'){  //quenn
            Carta carta(line, 12);
            pilacentral1.agregarCarta(carta);
        }else if (line.at(0)=='j'){  //quenn
            Carta carta(line, 11);
            pilacentral1.agregarCarta(carta);
        }else if (line.at(0)=='V') {
            Carta carta(line, 0);
            pilacentral1.agregarCarta(carta);
        }else{
            char a = line.at(0);
            int num = a-48;
            Carta carta(line, num);
            pilacentral1.agregarCarta(carta);

        }
        std::getline(ifs, line);
        cout <<endl<< endl << pilacentral1.obtenerCartas().size() <<endl <<endl;
        //cout << "uwu" << endl;
    }
    pilasCentralesAux->push_back(pilacentral1);
    cout<< line<<endl;
    std::getline(ifs, line);



    //PilaCentral2
    Mazo *mazoPilaC2 = new Mazo();
    PilaCentral pilacentral2(mazoPilaC2);
    while (line.compare("$") != 0) {
        cout << line << endl;
        if (line.at(0)=='a') {  //ace
            Carta carta(line, 1);
            pilacentral2.agregarCarta(carta);
        }else if (line.at(0)=='k'){  //king
            Carta carta(line, 1);
            pilacentral2.agregarCarta(carta);
        }else if (line.at(0)=='q'){  //quenn
            Carta carta(line, 12);
            pilacentral2.agregarCarta(carta);
        }else if (line.at(0)=='j'){  //quenn
            Carta carta(line, 11);
            pilacentral2.agregarCarta(carta);
        }else if (line.at(0)=='V') {
            Carta carta(line, 0);
            pilacentral2.agregarCarta(carta);
        }else{
            char a = line.at(0);
            int num = a-48;
            Carta carta(line, num);
            pilacentral2.agregarCarta(carta);
        }
        std::getline(ifs, line);
    }
    pilasCentralesAux->push_back(pilacentral2);
    cout<< line<<endl;
    std::getline(ifs, line);

    //PilaCentral3

    Mazo *mazoPilaC3 = new Mazo();
    PilaCentral pilacentral3(mazoPilaC3);
    while (line.compare("$") != 0) {
        cout << line << endl;
        if (line.at(0)=='a') {  //ace
            Carta carta(line, 1);
            pilacentral3.agregarCarta(carta);
        }else if (line.at(0)=='k'){  //king
            Carta carta(line, 1);
            pilacentral3.agregarCarta(carta);
        }else if (line.at(0)=='q'){  //quenn
            Carta carta(line, 12);
            pilacentral3.agregarCarta(carta);
        }else if (line.at(0)=='j'){  //quenn
            Carta carta(line, 11);
            pilacentral3.agregarCarta(carta);
        }else if (line.at(0)=='V') {
            Carta carta(line, 0);
            pilacentral3.agregarCarta(carta);
        }else{
            char a = line.at(0);
            int num = a-48;
            Carta carta(line, num);
            pilacentral3.agregarCarta(carta);
        }
        std::getline(ifs, line);
    }
    pilasCentralesAux->push_back(pilacentral3);
    cout<< line<<endl;
    std::getline(ifs, line);

    //MazoCentral
    Mazo* mazoCentralAux = new Mazo();
    while (line.compare("$") != 0) {
        cout << line << endl;
        if (line.at(0)=='a') {  //ace
            Carta carta(line, 1);
            mazoCentralAux->agregarCartaMazo(carta, 0); //
        }else if (line.at(0)=='k'){  //king
            Carta carta(line, 1);
            mazoCentralAux->agregarCartaMazo(carta, 0); //
        }else if (line.at(0)=='q'){  //quenn
            Carta carta(line, 12);
            mazoCentralAux->agregarCartaMazo(carta, 0); //
        }else if (line.at(0)=='j'){  //quenn
            Carta carta(line, 11);
            mazoCentralAux->agregarCartaMazo(carta, 0); //
        }else if (line.at(0)=='V') {
            Carta carta(line, 0);
            mazoCentralAux->agregarCartaMazo(carta, 0); //
        }else{
            char a = line.at(0);
            int num = a-48;
            Carta carta(line, num);
            mazoCentralAux->agregarCartaMazo(carta, 0); //
        }
        std::getline(ifs, line);
    }
    cout<< line<<endl;
    std::getline(ifs, line);

    //ManoJ1
    vector<Carta> *manoAuxJ1 = new vector<Carta>();
    while (line.compare("$") != 0) {
        cout << line << endl;
        if (line.at(0)=='a') {  //ace
            Carta carta(line, 1);
            manoAuxJ1->push_back(carta);
        }else if (line.at(0)=='k'){  //king
            Carta carta(line, 1);
            manoAuxJ1->push_back(carta);
        }else if (line.at(0)=='q'){  //quenn
            Carta carta(line, 12);
            manoAuxJ1->push_back(carta);
        }else if (line.at(0)=='j'){  //quenn
            Carta carta(line, 11);
            manoAuxJ1->push_back(carta);
        }else if (line.at(0)=='V'){
            Carta carta(line, 0);
            manoAuxJ1->push_back(carta);
        }else{
            char a = line.at(0);
            int num = a-48;
            Carta carta(line, num);
            manoAuxJ1->push_back(carta);
        }
        std::getline(ifs, line);
    }
    cout<< line<<endl;
    std::getline(ifs, line);
    //ManoJ1
    vector<Carta> *manoAuxJ2 = new vector<Carta>();
    while (line.compare("$") != 0) {
        cout << line << endl;
        if (line.at(0)=='a') {  //ace
            Carta carta(line, 1);
            manoAuxJ2->push_back(carta);
        }else if (line.at(0)=='k'){  //king
            Carta carta(line, 1);
            manoAuxJ2->push_back(carta);
        }else if (line.at(0)=='q'){  //quenn
            Carta carta(line, 12);
            manoAuxJ2->push_back(carta);
        }else if (line.at(0)=='j'){  //quenn
            Carta carta(line, 11);
            manoAuxJ2->push_back(carta);
        }else if (line.at(0)=='V') {
            Carta carta(line, 0);
            manoAuxJ2->push_back(carta);
        }else{
            char a = line.at(0);
            int num = a-48;
            Carta carta(line, num);
            manoAuxJ2->push_back(carta);
        }
        std::getline(ifs, line);
    }
    cout<< line<<endl;
    std::getline(ifs, line);

    //MazoJ1
    Mazo mazoAuxJ1;
    while (line.compare("$") != 0) {
        cout << line << endl;
        if (line.at(0)=='a') {  //ace
            Carta carta(line, 1);
            mazoAuxJ1.agregarCartaMazo(carta, 0); //
        }else if (line.at(0)=='k'){  //king
            Carta carta(line, 1);
            mazoAuxJ1.agregarCartaMazo(carta, 0); //
        }else if (line.at(0)=='q'){  //quenn
            Carta carta(line, 12);
            mazoAuxJ1.agregarCartaMazo(carta, 0); //
        }else if (line.at(0)=='j'){  //quenn
            Carta carta(line, 11);
            mazoAuxJ1.agregarCartaMazo(carta, 0); //
        }else if (line.at(0)=='V') {
            Carta carta(line, 0);
            mazoAuxJ1.agregarCartaMazo(carta, 0); //
        }else{
            char a = line.at(0);
            int num = a-48;
            Carta carta(line, num);
            mazoAuxJ1.agregarCartaMazo(carta, 0); //
        }
        std::getline(ifs, line);
    }
    cout<< line<<endl;
    std::getline(ifs, line);

    cout << "holaasdasdasdasdsadasdasddasdsdadsdsasdasd" <<endl;
    //MazoJ2
    Mazo mazoAuxJ2;
    while (line.compare("$") != 0) {
        cout << line << endl;
        if (line.at(0)=='a') {  //ace
            Carta carta(line, 1);
            mazoAuxJ2.agregarCartaMazo(carta, 0); //
        }else if (line.at(0)=='k'){  //king
            Carta carta(line, 1);
            mazoAuxJ2.agregarCartaMazo(carta, 0); //
        }else if (line.at(0)=='q'){  //quenn
            Carta carta(line, 12);
            mazoAuxJ2.agregarCartaMazo(carta, 0); //
        }else if (line.at(0)=='j'){  //quenn
            Carta carta(line, 11);
            mazoAuxJ2.agregarCartaMazo(carta, 0); //
        }else if (line.at(0)=='V') {
            Carta carta(line, 0);
            mazoAuxJ2.agregarCartaMazo(carta, 0); //
        }else{
            char a = line.at(0);
            int num = a-48;
            Carta carta(line, num);
            mazoAuxJ2.agregarCartaMazo(carta, 0); //
        }
        std::getline(ifs, line);
    }
    cout<< line<<endl;
    std::getline(ifs, line);

    //Descartes
    vector<PilaDescarte*> PilasdeDescarteAux1;
    PilaDescarte* pilaDes1 = new PilaDescarte();
    while (line.compare("$") != 0) {
        cout << line << endl;
        if (line.at(0)=='a') {  //ace
            Carta carta(line, 1);
            pilaDes1->agregarCarta(carta);
        }else if (line.at(0)=='k'){  //king
            Carta carta(line, 1);
            pilaDes1->agregarCarta(carta);
        }else if (line.at(0)=='q'){  //quenn
            Carta carta(line, 12);
            pilaDes1->agregarCarta(carta);
        }else if (line.at(0)=='j'){  //quenn
            Carta carta(line, 11);
            pilaDes1->agregarCarta(carta);
        }else if (line.at(0)=='V') {
            Carta carta(line, 0);
            pilaDes1->agregarCarta(carta);
        }else{
            char a = line.at(0);
            int num = a-48;
            Carta carta(line, num);
            pilaDes1->agregarCarta(carta);
        }
        std::getline(ifs, line);
    }
    cout<< line<<endl;
    std::getline(ifs, line);

    PilaDescarte* pilaDes2 = new PilaDescarte();
    while (line.compare("$") != 0) {
        cout << line << endl;
        if (line.at(0)=='a') {  //ace
            Carta carta(line, 1);
            pilaDes2->agregarCarta(carta);
        }else if (line.at(0)=='k'){  //king
            Carta carta(line, 1);
            pilaDes2->agregarCarta(carta);
        }else if (line.at(0)=='q'){  //quenn
            Carta carta(line, 12);
            pilaDes2->agregarCarta(carta);
        }else if (line.at(0)=='j'){  //quenn
            Carta carta(line, 11);
            pilaDes2->agregarCarta(carta);
        }else if (line.at(0)=='V') {
            Carta carta(line, 0);
            pilaDes2->agregarCarta(carta);
        }else{
            char a = line.at(0);
            int num = a-48;
            Carta carta(line, num);
            pilaDes2->agregarCarta(carta);
        }
        std::getline(ifs, line);
    }
    cout<< line<<endl;
    std::getline(ifs, line);

    PilaDescarte* pilaDes3 = new PilaDescarte();
    while (line.compare("$") != 0) {
        cout << line << endl;
        if (line.at(0)=='a') {  //ace
            Carta carta(line, 1);
            pilaDes3->agregarCarta(carta);
        }else if (line.at(0)=='k'){  //king
            Carta carta(line, 1);
            pilaDes3->agregarCarta(carta);
        }else if (line.at(0)=='q'){  //quenn
            Carta carta(line, 12);
            pilaDes3->agregarCarta(carta);
        }else if (line.at(0)=='j'){  //quenn
            Carta carta(line, 11);
            pilaDes3->agregarCarta(carta);
        }else if (line.at(0)=='V') {
            Carta carta(line, 0);
            pilaDes3->agregarCarta(carta);
        }else{
            char a = line.at(0);
            int num = a-48;
            Carta carta(line, num);
            pilaDes3->agregarCarta(carta);
        }
        std::getline(ifs, line);
    }
    cout<< line<<endl;
    std::getline(ifs, line);

    PilaDescarte* pilaDes4 = new PilaDescarte();
    while (line.compare("$") != 0) {
        cout << line << endl;
        if (line.at(0)=='a') {  //ace
            Carta carta(line, 1);
            pilaDes4->agregarCarta(carta);
        }else if (line.at(0)=='k'){  //king
            Carta carta(line, 1);
            pilaDes4->agregarCarta(carta);
        }else if (line.at(0)=='q'){  //quenn
            Carta carta(line, 12);
            pilaDes4->agregarCarta(carta);
        }else if (line.at(0)=='j'){  //quenn
            Carta carta(line, 11);
            pilaDes4->agregarCarta(carta);
        }else if (line.at(0)=='V') {
            Carta carta(line, 0);
            pilaDes4->agregarCarta(carta);
        }else{
            char a = line.at(0);
            int num = a-48;
            Carta carta(line, num);
            pilaDes4->agregarCarta(carta);
        }
        std::getline(ifs, line);
    }
    PilasdeDescarteAux1.push_back(pilaDes1);
    PilasdeDescarteAux1.push_back(pilaDes2);
    PilasdeDescarteAux1.push_back(pilaDes3);
    PilasdeDescarteAux1.push_back(pilaDes4);
    cout<< line<<endl;
    std::getline(ifs, line);

    vector<PilaDescarte*> PilasdeDescarteAux2;
    PilaDescarte* pila2Des1 = new PilaDescarte();
    while (line.compare("$") != 0) {
        cout << line << endl;
        if (line.at(0)=='a') {  //ace
            Carta carta(line, 1);
            pila2Des1->agregarCarta(carta);
        }else if (line.at(0)=='k'){  //king
            Carta carta(line, 1);
            pila2Des1->agregarCarta(carta);
        }else if (line.at(0)=='q'){  //quenn
            Carta carta(line, 12);
            pila2Des1->agregarCarta(carta);
        }else if (line.at(0)=='j'){  //quenn
            Carta carta(line, 11);
            pila2Des1->agregarCarta(carta);
        }else if (line.at(0)=='V') {
            Carta carta(line, 0);
            pila2Des1->agregarCarta(carta);
        }else{
            char a = line.at(0);
            int num = a-48;
            Carta carta(line, num);
            pila2Des1->agregarCarta(carta);
        }
        std::getline(ifs, line);
    }
    cout<< line<<endl;
    std::getline(ifs, line);

    PilaDescarte* pila2Des2 = new PilaDescarte();
    while (line.compare("$") != 0) {
        cout << line << endl;
        if (line.at(0)=='a') {  //ace
            Carta carta(line, 1);
            pila2Des2->agregarCarta(carta);
        }else if (line.at(0)=='k'){  //king
            Carta carta(line, 1);
            pila2Des2->agregarCarta(carta);
        }else if (line.at(0)=='q'){  //quenn
            Carta carta(line, 12);
            pila2Des2->agregarCarta(carta);
        }else if (line.at(0)=='j'){  //quenn
            Carta carta(line, 11);
            pila2Des2->agregarCarta(carta);
        }else if (line.at(0)=='V') {
            Carta carta(line, 0);
            pila2Des2->agregarCarta(carta);
        }else{
            char a = line.at(0);
            int num = a-48;
            Carta carta(line, num);
            pila2Des2->agregarCarta(carta);
        }
        std::getline(ifs, line);
    }
    cout<< line<<endl;
    std::getline(ifs, line);

    PilaDescarte* pila2Des3 = new PilaDescarte();
    while (line.compare("$") != 0) {
        cout << line << endl;
        if (line.at(0)=='a') {  //ace
            Carta carta(line, 1);
            pila2Des3->agregarCarta(carta);
        }else if (line.at(0)=='k'){  //king
            Carta carta(line, 1);
            pila2Des3->agregarCarta(carta);
        }else if (line.at(0)=='q'){  //quenn
            Carta carta(line, 12);
            pila2Des3->agregarCarta(carta);
        }else if (line.at(0)=='j'){  //quenn
            Carta carta(line, 11);
            pila2Des3->agregarCarta(carta);
        }else if (line.at(0)=='V') {
            Carta carta(line, 0);
            pila2Des3->agregarCarta(carta);
        }else{
            char a = line.at(0);
            int num = a-48;
            Carta carta(line, num);
            pila2Des3->agregarCarta(carta);
        }
        std::getline(ifs, line);
    }
    cout<< line<<endl;
    std::getline(ifs, line);

    PilaDescarte* pila2Des4 = new PilaDescarte();
    while (line.compare("$") != 0) {
        cout << line << endl;
        if (line.at(0)=='a') {  //ace
            Carta carta(line, 1);
            pila2Des4->agregarCarta(carta);
        }else if (line.at(0)=='k'){  //king
            Carta carta(line, 1);
            pila2Des4->agregarCarta(carta);
        }else if (line.at(0)=='q'){  //quenn
            Carta carta(line, 12);
            pila2Des4->agregarCarta(carta);
        }else if (line.at(0)=='j'){  //quenn
            Carta carta(line, 11);
            pila2Des4->agregarCarta(carta);
        }else if (line.at(0)=='V') {
            Carta carta(line, 0);
            pila2Des4->agregarCarta(carta);
        }else{
            char a = line.at(0);
            int num = a-48;
            Carta carta(line, num);
            pila2Des4->agregarCarta(carta);
        }
        std::getline(ifs, line);
    }
    PilasdeDescarteAux2.push_back(pila2Des1);
    PilasdeDescarteAux2.push_back(pila2Des2);
    PilasdeDescarteAux2.push_back(pila2Des3);
    PilasdeDescarteAux2.push_back(pila2Des4);
    cout<< line<<endl;
    std::getline(ifs, line);

    //cout << "holaasdasdasd" <<endl;
    //Jugadores
    vector<Jugador*> jugadoresAux;
    Jugador* jugador1 = new Jugador(1, mazoCentralAux, pilasCentralesAux, manoAuxJ1, mazoAuxJ1, PilasdeDescarteAux1);
    Jugador* jugador2 = new Jugador(2, mazoCentralAux, pilasCentralesAux, manoAuxJ2, mazoAuxJ2, PilasdeDescarteAux1);
    jugadoresAux.push_back(jugador1);
    jugadoresAux.push_back(jugador2);
    Tablero tablero(/*Mazo**/ mazoCentralAux, /*vector<PilaCentral>* */pilasCentralesAux,/*int*/ turnoJugadorAux, /*vector<Jugador*> */jugadoresAux);

    PantallaJuego *pantallaJuego = new PantallaJuego(tablero, 1);
    pantallaJuego->show();
    this->hide();
}

