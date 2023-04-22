#include "registerfrom.h"
#include "ui_registerfrom.h"
#include "lib/gui_lib.h"
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QAbstractAnimation>

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

