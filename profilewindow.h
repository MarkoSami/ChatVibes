#ifndef PROFILEWINDOW_H
#define PROFILEWINDOW_H

#include <QWidget>

namespace Ui {
class profileWindow;
}

class profileWindow : public QWidget
{
    Q_OBJECT

public:
    explicit profileWindow(QWidget *parent = nullptr);
    ~profileWindow();

private:
    Ui::profileWindow *ui;
};

#endif // PROFILEWINDOW_H
