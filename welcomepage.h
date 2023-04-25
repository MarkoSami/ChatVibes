#ifndef WELCOMEPAGE_H
#define WELCOMEPAGE_H

#include <QDialog>
#include "registerfrom.h"
#include "loginform.h"

namespace Ui {
class WelcomePage;
}

class WelcomePage : public QDialog
{
    Q_OBJECT

public:
    explicit WelcomePage(QWidget *parent = nullptr);
    ~WelcomePage();

private slots:
    void on_pushButton_2_clicked();
    void moveLogin();
    void moveRegister();
    void on_pushButton_3_clicked();
    void on_pushButton_clicked();
    void closedHandle() ;

private:
    Ui::WelcomePage *ui;
    Registerfrom regWin ;
    loginForm logWin ;
};

#endif // WELCOMEPAGE_H
