
#include "mainwindow.h"
#include "profilewindow.h"
#include "loginform.h"
#include "registerfrom.h"
#include "ui_mainwindow.h"
#include "ui_registerfrom.h"
#include "welcomepage.h"
#include "lib/gui_lib.h"
#include<QString>
#include <QScreen>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Set the window to open as full screen
    this->showMaximized();
    GUI_lib::setUpWindow(this, "Chat Vibes", ":/imgs/logo.png");
//    this->setWindowFlags( Qt::WindowTitleHint);
    welcomeWin = new WelcomePage();
    welcomeWin->show();

    // Add the parent QGroupBox to the vertical layout
//    ui->verticalGroupBox_3->layout()->addWidget(hGroupBoxParent);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_3_clicked()
{
    this->close();
}


void MainWindow::on_pushButton_4_clicked()
{
    if (this->isMaximized()) {
        this->showNormal();
    } else {
        this->showMaximized();
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    if (window()->isMinimized()) {
        window()->showNormal();
    } else {
        window()->showMinimized();
    }
}



