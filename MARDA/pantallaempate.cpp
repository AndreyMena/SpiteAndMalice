#include "pantallaempate.h"
#include "ui_pantallaempate.h"

pantallaempate::pantallaempate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pantallaempate)
{
    ui->setupUi(this);
}

pantallaempate::~pantallaempate()
{
    delete ui;
}
