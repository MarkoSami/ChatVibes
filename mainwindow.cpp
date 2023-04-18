
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Set the window to open as full screen
    this->showMaximized();
    setWindowTitle("CHat Vibes");



}

MainWindow::~MainWindow()
{
    delete ui;
}


