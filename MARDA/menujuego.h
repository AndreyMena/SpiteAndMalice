#ifndef MENUJUEGO_H
#define MENUJUEGO_H

#include <QMainWindow>

#include "pantallajuego.h"
#include "mazo.h"
#include "eleccionjugador.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MenuJuego; }
QT_END_NAMESPACE

class MenuJuego : public QMainWindow
{
    Q_OBJECT

public:
    MenuJuego(QWidget *parent = nullptr);
    ~MenuJuego();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MenuJuego *ui;
};
#endif // MENUJUEGO_H
