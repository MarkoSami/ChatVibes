
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
#include "lib/filesystem_lib.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    fileSystem_lib ::loadData( );
     ui->setupUi(this);
    // Set the window to open as full screen

    GUI_lib::setUpWindow(this, "Chat Vibes", ":/imgs/logo.png");
//    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Window);
    for (int i = 0 ; i<20 ; i++) {
    QHBoxLayout *hLayout = new QHBoxLayout;
    QHBoxLayout *hLayoutParent = new QHBoxLayout;

    // Add QLabel widgets to the layout
    QLabel *ProfilePic = new QLabel();
    ProfilePic->setSizePolicy(QSizePolicy::Fixed , QSizePolicy::Fixed);
    ProfilePic->setMinimumHeight(30); ProfilePic->setMinimumWidth(30);
    ProfilePic->setStyleSheet("image: url(:/imgs/Profile (2).png);");

    QLabel *textMsg = new QLabel(" مارك الجياص مارك الجياص مارك الجياص مارك الجياص مارك الجياص مارك الجياص مارك الجياص مارك الجياص مارك الجياص مارك الجياص مارك الجياص");
    textMsg->setSizePolicy(QSizePolicy::Fixed , QSizePolicy::Fixed);
    textMsg->setMinimumHeight(30);
    textMsg->setStyleSheet("color : white ;font-weight :bold;font-size : 16px ;");

    // Add the QLabel to the child QGroupBox layout
    hLayout->addWidget(ProfilePic);
    hLayout->addWidget(textMsg);

    // Add a horizontal spacer to the parent QGroupBox layout
    QSpacerItem *hSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);


    // Create a new QGroupBox with the child QHBoxLayout as its layout
    QGroupBox *hGroupBox = new QGroupBox();
    hGroupBox->setMinimumHeight(60);
    hGroupBox->setMaximumWidth(300);
    hGroupBox->setStyleSheet("background :#161a1d ;");
    hLayout->setSpacing(30);
    hLayout->setContentsMargins(20,9,20,9);
    hGroupBox->setLayout(hLayout);

    // Add the child QGroupBox to the parent QGroupBox layout
    hLayoutParent->addWidget(hGroupBox);
    hLayoutParent->addItem(hSpacer);
    // Set the parent QGroupBox layout and style sheet
    QGroupBox *hGroupBoxParent = new QGroupBox();
    hGroupBoxParent->setLayout(hLayoutParent);
    ui->verticalGroupBox_3->layout()->addWidget(hGroupBoxParent);
    }
    welcomeWin = new WelcomePage();
    welcomeWin->show();
    fileSystem_lib::saveData();
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



