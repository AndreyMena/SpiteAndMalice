#include "menujuego.h"
#include "ui_menujuego.h"

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
    mazo *m = new mazo;
    m->crearMazo();

    PantallaJuego *pantallaJuego = new PantallaJuego();
    pantallaJuego->show();
    this->hide();
}

