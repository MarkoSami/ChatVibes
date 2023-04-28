
#include "qclickablegroubox.h"

QClickableGroupBox::QClickableGroupBox(QWidget *parent) : QGroupBox(parent)
{
}

void QClickableGroupBox::mousePressEvent(QMouseEvent *event)
{
    emit clicked();
}
