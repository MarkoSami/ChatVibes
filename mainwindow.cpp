
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "lib/gui_lib.h"
#include<QString>
#include <QPixmap>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Set the window to open as full screen
    this->showMaximized();
    GUI_lib::setUpWindow(this, "Chat Vibes", ":/imgs/logo.png");
    int width = ui->Textimg2->width() ;
    int height= ui->Textimg2->height() ;
    QPixmap myPixmap(":/imgs/undraw_new_message_re_fp03.svg");
    ui->Textimg2->setPixmap(myPixmap.scaled(width,height,Qt::KeepAspectRatio));
    // Set the width of the pixmap using a style sheet

}

MainWindow::~MainWindow()
{
    delete ui;
}


