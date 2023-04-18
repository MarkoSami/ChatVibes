#include "profilewindow.h"
#include "ui_profilewindow.h"

profileWindow::profileWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::profileWindow)
{
    ui->setupUi(this);
}

profileWindow::~profileWindow()
{
    delete ui;
}
