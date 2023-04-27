
#include "mainwindow.h"
#include "profilewindow.h"
#include "loginform.h"
#include "registerfrom.h"
#include "ui_mainwindow.h"
#include "ui_registerfrom.h"
#include "lib/gui_lib.h"
#include<QString>
#include <QScreen>
#include <QPixmap>
#include <QDateTime>
#include "lib/filesystem_lib.h"
#include "addcontact.h"
#include <QPropertyAnimation>
#include "startnewchat.h"
#include "application/application.h"
#include <QScrollBar>
#include "logic/conversation.h"
#include "logic/message.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QCoreApplication::setAttribute(Qt::AA_UseOpenGLES);
     ui->setupUi(this);
    // Set the window to open as full screen



    connect(ui->sendMessageLineEdit, &QLineEdit::returnPressed,
     this, &MainWindow::on_pushButton_7_clicked);
    GUI_lib::setUpWindow(this, "Chat Vibes", ":/imgs/logo.png");
    ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->scrollArea_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Window);
    ui->scrollAreaWidgetContents->setContentsMargins(9,20,9,40);
    ui->scrollArea_2->verticalScrollBar()->setSingleStep(6);

    // Create a QPropertyAnimation object to animate the window's opacity
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(500);  // set the animation duration to 500 milliseconds
    animation->setStartValue(0.0);  // set the start opacity value to 0
    animation->setEndValue(1.0);  // set the end opacity value to 1

    // Connect the finished() signal of the animation to a slot that shows the window
    //    connect(animation, &QPropertyAnimation::finished, this, &MainWindow::show);

    animation->start(QAbstractAnimation::DeleteWhenStopped);



    for (auto &conversation : Application::loggedUser->getUserContacts()) {
        // Convert the address to a string
        std::stringstream ss;
        ss << &conversation;
        std::string conversationAddress = ss.str();

        // Create the QGroupBox widget
        QGroupBox *renderConversation = Conversation::renderConversation(conversation);
        renderConversation->setObjectName(QString::fromStdString(conversationAddress));
        ui->contactsCont->layout()->addWidget(renderConversation);
        renderConversation->setEnabled(true);
        // Connect the clicked() signal to a lambda function
        connect(renderConversation, &QGroupBox::clicked, [=]() {
            handleClickedConversation(renderConversation);
        });
    }


}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onRenderConversationClicked()
{

}

void MainWindow::handleClickedConversation(QGroupBox * renderConversation) {
    qDebug() << renderConversation->objectName() ;
}



void MainWindow::on_pushButton_3_clicked()
{

//    Application::conversations.push(Conversation(Contact("sdfs")));
    fileSystem_lib::saveData();
    this->close();
}

void MainWindow::renderContactMain() {
   ui->contactsCont->layout()->addWidget(Conversation::renderConversation(Application::loggedUser->getUserContacts().back()));
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


void MainWindow::on_pushButton_5_clicked()
{
     addContactWin = new AddContact() ;
      addContactWin->show();
      connect(addContactWin, SIGNAL(renderContact()), this, SLOT(renderContactMain()));
}


void MainWindow::on_pushButton_6_clicked()
{
      profWin = new profileWindow();
      profWin->show();
}


void MainWindow::on_pushButton_clicked()
{
      StartNewChatWin = new StartNewChat();
      StartNewChatWin->show();
}


void MainWindow::on_pushButton_7_clicked()
{
      QString textMsg = ui->sendMessageLineEdit->text();


      if (!textMsg.isEmpty()) { // check if the text is not empty
        Message messageTest("52", textMsg.toStdString(), "242", QDateTime::currentDateTime(), false, false);

        ui->verticalGroupBox_3->layout()->addWidget(Conversation::renderMessage(messageTest , Conversation::left ));
        ui->sendMessageLineEdit->setText("");
        ui->scrollArea_2->verticalScrollBar()->setValue(ui->scrollArea_2->verticalScrollBar()->maximum());
      }
}
