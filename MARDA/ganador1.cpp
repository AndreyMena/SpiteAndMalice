#include "ganador1.h"
#include "ui_ganador1.h"

Ganador1::Ganador1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ganador1)
{
    ui->setupUi(this);
}

Ganador1::~Ganador1()
{
    delete ui;
}

