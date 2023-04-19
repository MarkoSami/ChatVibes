#include "profilewindow.h"
#include "ui_profilewindow.h"
#include <QPixmap>

profileWindow::profileWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::profileWindow)
{
    ui->setupUi(this);
//    ui->ProfileUploadBtn->setStyleSheet("QPushButton#ProfileUploadBtn{background-color: #3663fd; border-radius: 5px; font-size: 20px; color: white; font-weight: bold;}"
//                                      "QPushButton#ProfileUploadBtn:hover{color : red;}");
}

profileWindow::~profileWindow()
{
    delete ui;
}
