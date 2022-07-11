#ifndef PANTALLAEMPATE_H
#define PANTALLAEMPATE_H

#include <QWidget>

namespace Ui {
class pantallaempate;
}

class pantallaempate : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Muestra un mensaje indicando que ha habido un empate
     * @param parent
     */
    explicit pantallaempate(QWidget *parent = nullptr);
    ~pantallaempate();

private:
    Ui::pantallaempate *ui;
};

#endif // PANTALLAEMPATE_H
