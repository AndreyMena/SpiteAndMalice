#include "pantallajuego.h"
#include "ui_pantallajuego.h"
#include "menujuego.h"
#include "mazo.h"
#include <QListWidgetItem>
#include <QDrag>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QPainter>

//#include <fstream>

PantallaJuego::PantallaJuego(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PantallaJuego)
{
    ui->setupUi(this);


    //QHBoxLayout *frameLayout = new QHBoxLayout(this->ui->frame);
    QListWidgetItem *l1 = new QListWidgetItem(this->ui->listWidget);
    QListWidgetItem* l2 = new QListWidgetItem(this->ui->listWidget);
    QListWidgetItem* l3 = new QListWidgetItem(this->ui->listWidget);

    l1->setIcon(QIcon(":/img/img/7_of_clubs.png"));
    l1->setData(Qt::UserRole, QVariant("image: url(:/img/img/7_of_clubs.png)"));
    l1->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsDragEnabled);

    l2->setIcon(QIcon(":/img/img/7_of_clubs.png"));
    l2->setData(Qt::UserRole, QVariant("image: url(:/img/img/7_of_clubs.png)"));
    l2->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsDragEnabled);

    l3->setIcon(QIcon(":/img/img/7_of_clubs.png"));
    l3->setData(Qt::UserRole, QVariant("image: url(:/img/img/7_of_clubs.png)"));
    l3->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsDragEnabled);
}

PantallaJuego::~PantallaJuego()
{
    delete ui;
}

/*void PantallaJuego::on_pushButton_2_clicked()
{
    this->ui->pushButton_2->setStyleSheet(
                "image: url(:/img/img/7_of_clubs.png)");
}*/

void PantallaJuego::on_listWidget_2_itemEntered(QListWidgetItem *item)
{
    std::cout << "Hola mundo" << std::endl;
}

void PantallaJuego::on_listWidget_2_itemChanged(QListWidgetItem *item)
{
    std::cout << "Hola mundo segundo intento" << std::endl;
}


void PantallaJuego::on_listWidget_5_itemChanged(QListWidgetItem *item)
{

}


void PantallaJuego::on_listWidget_2_itemActivated(QListWidgetItem *item)
{
    std::cout << "Hola mundo tercer intento" << std::endl;
}


void PantallaJuego::on_listWidget_2_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    std::cout << "Hola mundo cuarto intento" << std::endl;
}


void PantallaJuego::on_listWidget_2_currentRowChanged(int currentRow)
{
    std::cout << "Hola mundo quinto intento" << std::endl;
}

