#include "guardarpartida.h"
#include "ui_guardarpartida.h"

guardarpartida::guardarpartida(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::guardarpartida)
{
    ui->setupUi(this);
}

guardarpartida::~guardarpartida()
{
    delete ui;
}

void guardarpartida::on_pushButton_clicked()
{
    // Código que agarra el nombre de la persona o lo que sea y guarda el
    // archivo con ese nombre.
    QString textoDigitado = this->ui->lineEdit->text();
    std::string nombreArchivo = textoDigitado.toStdString();
}

