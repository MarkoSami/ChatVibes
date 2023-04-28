
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

signals:
    void clicked();
};
#endif // QCLICKABLEGROUBOX_H
