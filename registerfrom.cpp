#include "registerfrom.h"
#include "ui_registerfrom.h"

Registerfrom::Registerfrom(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registerfrom)
{
    ui->setupUi(this);
}

Registerfrom::~Registerfrom()
{
    delete ui;
}
