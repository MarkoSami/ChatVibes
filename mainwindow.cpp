
#include "mainwindow.h"
#include "profilewindow.h"
  #include "ui_mainwindow.h"
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
#include "customGUI/qclickablegroubox.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QCoreApplication::setAttribute(Qt::AA_UseOpenGLES);
     ui->setupUi(this);
    // Set the window to open as full screen

    ui->stackedWidget->setCurrentIndex(0);

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
    animation->setDuration(150);  // set the animation duration to 500 milliseconds
    animation->setStartValue(0.0);  // set the start opacity value to 0
    animation->setEndValue(1.0);  // set the end opacity value to 1

    // Connect the finished() signal of the animation to a slot that shows the window
    //    connect(animation, &QPropertyAnimation::finished, this, &MainWindow::show);

    animation->start(QAbstractAnimation::DeleteWhenStopped);

     // Make a copy of the original stack
    std::stack<Conversation*> tempConversations ;

    qDebug()<<Application::loggedUser->getUserName() ;
    qDebug()<<Application::loggedUser->getConversations().size();

    // Render the copied conversations
    while (!Application::loggedUser->getConversations().empty()) {

        qDebug()<<"con Name: "<<Application::loggedUser->getConversations().top()->getName();
        Conversation* conversationPtr = (Application::loggedUser->getConversations().top());
        tempConversations.push(conversationPtr);

        // Convert the address to a string
        std::stringstream ss;
        ss << conversationPtr;
        std::string conversationAddress = ss.str();

        // Create the QClickableGroupBox widget
        QClickableGroupBox *renderConversation = Application::renderConversation(conversationPtr);
        renderConversation->setObjectName(QString::fromStdString(conversationAddress));
        ui->contactsCont->layout()->addWidget(renderConversation);
        renderConversation->setEnabled(true);

        // Connect the clicked() signal to a lambda function
        connect(renderConversation, &QClickableGroupBox::clicked, [=]() {
            handleClickedConversation(renderConversation);
        });

        Application::loggedUser->getConversations().pop();
     }

    while(!tempConversations.empty()){
        Application::loggedUser->getConversations().push(tempConversations.top());
        tempConversations.pop();
     }


}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onRenderConversationClicked()
{

}

void MainWindow::handleClickedConversation(QGroupBox *renderConversation) {
    ui->stackedWidget->setCurrentIndex(1);

    if (!renderConversation) {
        qDebug() << "Render conversation is null";
        return;
    }

    // Create a stringstream object from the string.
    std::stringstream ss(renderConversation->objectName().toStdString());

    void* address;
    ss >> address;// Read the address from the stringstream.

    // Cast the void* pointer to the desired type.
    Conversation* conversation = static_cast<Conversation*>(address);

    qDebug()<< (Application::currentConversation );
    Application::currentConversation =  conversation;
    qDebug()<< (Application::currentConversation );


    QLayoutItem *item;
    while ((item = ui->verticalGroupBox_3->layout()->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    ui->label_3->setText(conversation->getName().c_str());
    for (auto &conv : conversation->getMessages()) {
        ui->verticalGroupBox_3->layout()->addWidget(Application::renderMessage(*conv));
    }
}





void MainWindow::on_pushButton_3_clicked()
{

//    Application::conversations.push(Conversation(Contact("sdfs")));
    fileSystem_lib::saveData();
    this->close();
}

void MainWindow::renderContactMain() {
//   ui->contactsCont->layout()->addWidget(Conversation::renderConversation(Application::loggedUser->getUserContacts().back()));
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
     connect(addContactWin, SIGNAL(renderConversation()), this, SLOT(renderContactMain()));
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
        Message *messageTest = new Message(Application::loggedUser->getUserName(), textMsg.toStdString(), Application::currentConversation->getReceiver()->getName(), QDateTime::currentDateTime(), false, false);
        Application::currentConversation->addNewMessage(messageTest);

        Conversation *receiverConv = Application::getReceiverConversation(Application::loggedUser->getUserName());
        if(receiverConv != nullptr)
            receiverConv->addNewMessage(messageTest);

        ui->verticalGroupBox_3->layout()->addWidget(Application::renderMessage(*messageTest));

        ui->sendMessageLineEdit->setText("");
        ui->scrollArea_2->verticalScrollBar()->setValue(ui->scrollArea_2->verticalScrollBar()->maximum());
      }
      qDebug()<<Application::currentConversation->getMessages().size();
         std::stack<Conversation*> convs = Application::loggedUser->getConversations();
        while(!convs.empty()){
        for(auto& message : convs.top()->getMessages() ){
            qDebug()<<message->getMessageTxt().c_str()<<"\n";
            }
            convs.pop();
        }
 }
