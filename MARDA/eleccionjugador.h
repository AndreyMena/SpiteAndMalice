#ifndef ELECCIONJUGADOR_H
#define ELECCIONJUGADOR_H

#include <QWidget>

namespace Ui {
class EleccionJugador;
}

class EleccionJugador : public QWidget
{
    Q_OBJECT

public:
    explicit EleccionJugador(QWidget *parent = nullptr);
    ~EleccionJugador();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::EleccionJugador *ui;
};

#endif // ELECCIONJUGADOR_H
