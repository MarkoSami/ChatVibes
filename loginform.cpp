#include "loginform.h"
#include "ui_loginform.h"
#include <QPixmap>
#include "lib/gui_lib.h"
#include "application/application.h"
#include <QTimer>
#include <QCoreApplication>


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


void loginForm::on_LoginBtn_clicked()
{

    std::string userName = ui->userNameLE->text().toStdString();
    std::string password = ui->passwordLE->text().toStdString();

    if (userName.empty() || password.empty()) {
         ui->loggedInSuccessfully->setStyleSheet("color:red");
         ui->loggedInSuccessfully->setText("sorry username and password are required");

         return;
    }

    if(Application::loginUser(userName , password))
    {
        ui->loggedInSuccessfully->setStyleSheet("color:green");
        ui->loggedInSuccessfully->setText("Logged in successfully!");
         // create a new QTimer instance and connect its timeout() signal to a lambda function
        QTimer* delayTimer = new QTimer(this);

        connect(delayTimer, &QTimer::timeout, [=]() {
            // close the current window
            emit LoggedInSuccessfully();
            delayTimer->disconnect(); // disconnect the signal after emitting once
        });

        delayTimer->setSingleShot(true); // make the QTimer emit only once

         // start the timer with a 1 second interval

         delayTimer->start(2000);

         // enter the application event loop
         QCoreApplication::processEvents();

    }
    else {
        ui->loggedInSuccessfully->setStyleSheet("color:red");
        ui->loggedInSuccessfully->setText("Login failed check your information again");
    }
}


void loginForm::on_backButton_clicked()
{
    emit BackClicked() ;
}

