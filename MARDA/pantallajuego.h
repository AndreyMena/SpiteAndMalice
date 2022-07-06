#ifndef PANTALLAJUEGO_H
#define PANTALLAJUEGO_H

#include <QWidget>
#include <iostream>
#include <QString>
#include <QListWidgetItem>

namespace Ui {
class PantallaJuego;
}

class PantallaJuego : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructor de la clase PantallaJuego donde se muestra y juega el
     * juego.
     * @param parent Parámetro de la clase padre QWidget
     */
    explicit PantallaJuego(QWidget *parent = nullptr);

    /**
     * @brief Destructor de la clase PantallaJuego
     */
    ~PantallaJuego();

private slots:
    /**
     * @brief Realiza las acciones que se dicten dentro del código del método
     * cuando el usuario le da clic a este botón en específico.
     */
    //void on_pushButton_2_clicked();

    void on_listWidget_2_itemEntered(QListWidgetItem *item);

    void on_listWidget_2_itemChanged(QListWidgetItem *item);

private:
    Ui::PantallaJuego *ui;
};

#endif // PANTALLAJUEGO_H
