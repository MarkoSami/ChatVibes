#include "qclickablegroubox.h"
#include <QMouseEvent>
#include <QDebug>

QClickableGroupBox::QClickableGroupBox(QWidget *parent) : QGroupBox(parent)
{
    // Create the context menu and connect the actions to their slots
    createContextMenu();
}

void QClickableGroupBox::createContextMenu()
{
    m_contextMenu = new QMenu(this);
    m_favAction = m_contextMenu->addAction("Preview");
    m_deleteAction = m_contextMenu->addAction("Delete");
    connect(m_favAction, &QAction::triggered, this, &QClickableGroupBox::handleFavAction);
    connect(m_deleteAction, &QAction::triggered, this, &QClickableGroupBox::handleDeleteAction);
}

void QClickableGroupBox::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton) {
        m_contextMenu->exec(event->globalPos());
    } else {
        emit clicked();
    }
}

void QClickableGroupBox::mouseDoubleClickEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        emit doubleClickDetected();
    }
}

void QClickableGroupBox::handleFavAction()
{
    // Show the preview window here
    qDebug() << "Preview window opened";
}

void QClickableGroupBox::handleDeleteAction()
{
    // Delete the selected item here
    qDebug() << "Item deleted";
}
