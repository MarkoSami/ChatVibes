#include "welcomepage.h"
#include "ui_welcomepage.h"

WelcomePage::WelcomePage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WelcomePage)
{
    ui->setupUi(this);
    ui->stackedWidget->insertWidget(2,&logWin);
    ui->stackedWidget->insertWidget(3,&regWin);
    connect(&regWin, SIGNAL(LoginClicked()), this, SLOT(moveLogin()));
    connect(&logWin, SIGNAL(RegisterClicked()), this, SLOT(moveRegister()));
}

WelcomePage::~WelcomePage()
{
    delete ui;
}

void WelcomePage::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void WelcomePage::moveLogin()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void WelcomePage::moveRegister()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void WelcomePage::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void WelcomePage::on_pushButton_clicked()
{
      ui->stackedWidget->setCurrentIndex(1);
}

