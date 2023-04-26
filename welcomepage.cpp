#include "welcomepage.h"
#include "ui_welcomepage.h"
#include "lib/filesystem_lib.h"
WelcomePage::WelcomePage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WelcomePage)
{
    fileSystem_lib::loadData();
    QMetaObject::connectSlotsByName(this);
    ui->setupUi(this);
    ui->stackedWidget->insertWidget(2,&logWin);
    ui->stackedWidget->insertWidget(3,&regWin);
    disconnect(&profWindow, SIGNAL(showWelcomePage()), this, SLOT(showWelcomePage()));
    connect(&profWindow, SIGNAL(showWelcomePage()), this, SLOT(showWelcomePage()));
    connect(&regWin, SIGNAL(LoginClicked()), this, SLOT(moveLogin()));
    connect(&regWin, SIGNAL(BackClicked()), this, SLOT(backHandler()));
    connect(&logWin, SIGNAL(BackClicked()), this, SLOT(backHandler()));
    connect(&logWin, SIGNAL(RegisterClicked()), this, SLOT(moveRegister()));
    connect(&logWin , SIGNAL(LoggedInSuccessfully()), this , SLOT(closedHandle()));


    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Window);
    mainWindowWin = new MainWindow();

}

WelcomePage::~WelcomePage()
{
    delete ui;
}

void WelcomePage::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void WelcomePage::moveLogin()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void WelcomePage::showWelcomePage() {
    qDebug() << "fsssss" ;
    this->close();
}

void WelcomePage::closedHandle() {
//    this->close() ;
    mainWindowWin->show();
}

void WelcomePage::moveRegister()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void WelcomePage::backHandler() {
    ui->stackedWidget->setCurrentIndex(1);
}

void WelcomePage::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void WelcomePage::on_pushButton_clicked()
{
      ui->stackedWidget->setCurrentIndex(1);
}


void WelcomePage::on_pushButton_7_clicked()
{
       this->close();
}


void WelcomePage::on_pushButton_8_clicked()
{
       if (window()->isMinimized()) {
           window()->showNormal();
       } else {
           window()->showMinimized();
       }
}

