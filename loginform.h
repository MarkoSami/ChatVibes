#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QWidget>


namespace Ui {
class loginForm;
}

class loginForm : public QWidget
{
    Q_OBJECT

public:
    explicit loginForm(QWidget *parent = nullptr);
    ~loginForm();




private:
    Ui::loginForm *ui;

signals:
    void RegisterClicked();
private slots:
    void on_pushButton_2_clicked();
};

#endif // LOGINFORM_H
