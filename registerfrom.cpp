#include "registerfrom.h"
#include "ui_registerfrom.h"
#include "lib/gui_lib.h"

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
