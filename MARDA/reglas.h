#ifndef REGLAS_H
#define REGLAS_H

#include <QWidget>

namespace Ui {
class Reglas;
}

/**
 * @brief Interfaz para visualizar las reglas del juego.
 */
class Reglas : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructor de interfaz Reglas
     * @param parent QWidget*
     */
    explicit Reglas(QWidget *parent = nullptr);

    /**
     * @brief Destructor de interfaz Reglas.
     */
    ~Reglas();

private:

    /**
     * @brief Puntero a la interfaz Reglas.
     */
    Ui::Reglas *ui;
};

#endif // REGLAS_H
