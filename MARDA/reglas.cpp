#include "reglas.h"
#include "ui_reglas.h"

Reglas::Reglas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Reglas)
{
    ui->setupUi(this);
}

Reglas::~Reglas()
{
    delete ui;
}
