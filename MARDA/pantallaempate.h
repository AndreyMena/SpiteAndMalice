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
    explicit pantallaempate(QWidget *parent = nullptr);
    ~pantallaempate();

private:
    Ui::pantallaempate *ui;
};

#endif // PANTALLAEMPATE_H
