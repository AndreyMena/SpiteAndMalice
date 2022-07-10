#include "ganador2.h"
#include "ui_ganador2.h"
#include "pantallajuego.h"

Ganador2::Ganador2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ganador2)
{
    ui->setupUi(this);
}

Ganador2::~Ganador2()
{
    delete ui;
}

