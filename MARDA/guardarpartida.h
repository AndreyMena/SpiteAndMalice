#ifndef GUARDARPARTIDA_H
#define GUARDARPARTIDA_H

#include <QWidget>

namespace Ui {
class guardarpartida;
}

class guardarpartida : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief guardarpartida se encarga de guardar la partida en el estado
     * que se encuentre en ese momento.
     * @param parent Parámetro de la clase padre QWidget
     */
    explicit guardarpartida(QWidget *parent = nullptr);
    ~guardarpartida();

private slots:
    /**
     * @brief Ejecuta las instrucciones que estén asociadas a dicho botón.
     */
    void on_pushButton_clicked();

private:
    Ui::guardarpartida *ui;
};

#endif // GUARDARPARTIDA_H
