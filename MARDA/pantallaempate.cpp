#include "pantallaempate.h"
#include "ui_pantallaempate.h"

PantallaEmpate::PantallaEmpate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pantallaempate)
{
    ui->setupUi(this);
}

PantallaEmpate::~PantallaEmpate()
{
    delete ui;
}
