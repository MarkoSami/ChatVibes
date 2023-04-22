#include "loginform.h"
#include "ui_loginform.h"
#include <QPixmap>
#include "lib/gui_lib.h"

loginForm::loginForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::loginForm)
{
    ui->setupUi(this);
    setWindowFlags( (windowFlags() | Qt::CustomizeWindowHint) & ~Qt::WindowMaximizeButtonHint);
    GUI_lib::setUpWindow(this, "Chat Vibes", ":/imgs/logo.png");

}

loginForm::~loginForm()
{
    delete ui;
}

void loginForm::on_pushButton_2_clicked()
{
    emit RegisterClicked();
}

