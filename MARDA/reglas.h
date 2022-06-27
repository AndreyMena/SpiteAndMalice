#ifndef REGLAS_H
#define REGLAS_H

#include <QWidget>

namespace Ui {
class Reglas;
}

class Reglas : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructor de la clase Reglas donde se muestran las reglas del juego
     * juego.
     * @param parent Parámetro de la clase padre QWidget
     */
    explicit Reglas(QWidget *parent = nullptr);
    /**
     * @brief Destructor de la clase Reglas
     */
    ~Reglas();

private:
    Ui::Reglas *ui;
};

#endif // REGLAS_H
