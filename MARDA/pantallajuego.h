#ifndef PANTALLAJUEGO_H
#define PANTALLAJUEGO_H

#include <QWidget>
#include <iostream>
#include <QString>

namespace Ui {
class PantallaJuego;
}

class PantallaJuego : public QWidget
{
    Q_OBJECT

public:
    explicit PantallaJuego(QWidget *parent = nullptr);
    ~PantallaJuego();
    void IniciarCartas();

private slots:

    void on_pushButton_2_clicked();

private:
    Ui::PantallaJuego *ui;
};

#endif // PANTALLAJUEGO_H
