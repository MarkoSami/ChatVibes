#include "registerfrom.h"
#include "ui_registerfrom.h"
#include "lib/gui_lib.h"
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QAbstractAnimation>
#include "logic/user.h"
#include "application/application.h"
#include <string>


Registerfrom::Registerfrom(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registerfrom)
{
    ui->setupUi(this);
    GUI_lib::setUpWindow(this, "Register", ":/imgs/logo.png");
}

Registerfrom::~Registerfrom()
{
    delete ui;
}


void Registerfrom::on_pushButton_4_clicked()
{
    emit LoginClicked();
}


void Registerfrom::on_pushButton_3_clicked()
{
    std::string firstName = ui->firstNameLE->text().toStdString();
    std::string lastName = ui->secondNameLE->text().toStdString();
    std::string userName = ui->userNameLE->text().toStdString();
    std::string password = ui->passwordLE->text().toStdString();

    User *regUser = new User(userName,userName, firstName, lastName, password);

    if(Application::registerUser(regUser))
    {
        ui->RegisteredSuccessfully->setText("Registered successfully");

    }
    else qDebug()<< "Registeration failed";
}


void Registerfrom::on_backButton_clicked()
{
    emit BackClicked() ;
}

