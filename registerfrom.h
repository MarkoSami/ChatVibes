#ifndef REGISTERFROM_H
#define REGISTERFROM_H

#include <QDialog>

namespace Ui {
class Registerfrom;
}

class Registerfrom : public QDialog
{
    Q_OBJECT

public:
    explicit Registerfrom(QWidget *parent = nullptr);
    ~Registerfrom();

private:
    Ui::Registerfrom *ui;
};

#endif // REGISTERFROM_H
