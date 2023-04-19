#include "loginform.h"
#include "ui_loginform.h"
#include <QPixmap>

loginForm::loginForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::loginForm)
{
    ui->setupUi(this);
    setWindowFlags( (windowFlags() | Qt::CustomizeWindowHint) & ~Qt::WindowMaximizeButtonHint);
}

loginForm::~loginForm()
{
    delete ui;
}
