
#include "mainwindow.h"
#include "profilewindow.h"
#include "ui_mainwindow.h"
#include "lib/gui_lib.h"

#include<QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Set the window to open as full screen
    this->showMaximized();
    GUI_lib::setUpWindow(this, "Chat Vibes", ":/imgs/logo.png");
    profWin = new profileWindow();

    profWin->show();




}

MainWindow::~MainWindow()
{
    delete ui;
}


