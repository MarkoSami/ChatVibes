
#include "qclickablegroubox.h"
#include <QMouseEvent>

QClickableGroupBox::QClickableGroupBox(QWidget *parent) : QGroupBox(parent)
{
}

void QClickableGroupBox::mousePressEvent(QMouseEvent *event)
{
    emit clicked();
}

void QClickableGroupBox::mouseDoubleClickEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        emit doubleClickDetected();
    }
}
