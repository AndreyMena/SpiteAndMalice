#ifndef PANTALLAEMPATE_H
#define PANTALLAEMPATE_H

#include <QWidget>

namespace Ui {
class pantallaempate;
}

class PantallaEmpate : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Muestra un mensaje indicando que ha habido un empate
     * @param parent
     */
    explicit PantallaEmpate(QWidget *parent = nullptr);

    /**
     * @brief Destructor
     */
    ~PantallaEmpate();

private:
    Ui::pantallaempate *ui;
};

#endif // PANTALLAEMPATE_H
