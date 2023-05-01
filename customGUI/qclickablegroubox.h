
#ifndef QCLICKABLEGROUBOX_H
#define QCLICKABLEGROUBOX_H

#include <QGroupBox>



class QClickableGroupBox : public QGroupBox
{
    Q_OBJECT

public:
    explicit QClickableGroupBox(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;

signals:
    void clicked();
    void doubleClickDetected();
};
#endif // QCLICKABLEGROUBOX_H
