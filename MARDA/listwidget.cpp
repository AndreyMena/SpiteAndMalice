#include "listwidget.h"
#include <QDebug>

ListWidget::ListWidget(QWidget *parent) : QListWidget (parent)
{
    setAcceptDrops(true);
}

void ListWidget::dropEvent(QDropEvent *event)
{
    qDebug() << "dropEvent"/*<<event*/;
    event->accept();
}
void ListWidget::dragEnterEvent(QDragEnterEvent *event)
{
    event->acceptProposedAction();
}
void ListWidget::dragMoveEvent(QDragMoveEvent *event)
{
    event->acceptProposedAction();
}
