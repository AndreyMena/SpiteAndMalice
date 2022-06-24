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
    explicit Reglas(QWidget *parent = nullptr);
    ~Reglas();

private:
    Ui::Reglas *ui;
};

#endif // REGLAS_H
