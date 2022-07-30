#include "mainviewcardgames.h"
#include "ui_mainviewcardgames.h"

MainViewCardGames::MainViewCardGames(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainViewCardGames)
{
    ui->setupUi(this);
    agregaItemsJuego();
}

MainViewCardGames::~MainViewCardGames()
{
    delete ui;
}

void MainViewCardGames::agregaItemsJuego() {
    for (int i = 0; i < CANTIDAD_JUEGOS; i++) {
        this->ui->comboBox->addItem(QString::fromStdString(nombresJuegos[i]));
    }
}

void MainViewCardGames::on_comboBox_activated(int index)
{
    indiceJuegoSeleccionado = index;
}

void MainViewCardGames::on_pushButton_clicked()
{
   cargaJuegoSeleccionado(indiceJuegoSeleccionado);
}

void MainViewCardGames::cargaJuegoSeleccionado(int indiceJuegoSeleccionado) {
    switch (indiceJuegoSeleccionado)
    {
    case 0: {
        MenuJuego *juegoSpiteMalice = new MenuJuego;
        juegoSpiteMalice->show();
        this->hide();
        break;
    }
    case 1:
        // Código para el siguiente juego. Se debe realizar un nuevo case para
        // cada uno de los juegos. El orden corresponde al mostrado en la vista
        // iniciando con S&M con el índice 0. Luego sigue 21 con el índice 1 y
        // así sucesivamente
        break;
    }
}
