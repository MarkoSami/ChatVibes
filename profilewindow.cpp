#include "profilewindow.h"
#include "ui_profilewindow.h"
#include <QPixmap>

profileWindow::profileWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::profileWindow)
{
    ui->setupUi(this);
    QPixmap profilePic("C:/DSProject/chatVibes/user.png");
    ui->ProfileImageLabel->setPixmap(profilePic.scaled(200,200,Qt::KeepAspectRatio));

}

profileWindow::~profileWindow()
{
    delete ui;
}
