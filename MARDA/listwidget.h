#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QListWidget>
#include <QDropEvent>
#include <QDragEnterEvent>

class ListWidget : public QListWidget
{
public:
    ListWidget(QWidget *parent = nullptr);
protected:
    void dropEvent(QDropEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
};

#endif // LISTWIDGET_H
