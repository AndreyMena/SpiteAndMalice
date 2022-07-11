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
    explicit guardarpartida(QWidget *parent = nullptr);
    ~guardarpartida();

private slots:
    void on_pushButton_clicked();

private:
    Ui::guardarpartida *ui;
};

#endif // GUARDARPARTIDA_H
