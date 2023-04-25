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

private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();

private:
    Ui::Registerfrom *ui;

signals:
    void LoginClicked();
};

#endif // REGISTERFROM_H
