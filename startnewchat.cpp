#include "startnewchat.h"
#include "ui_startnewchat.h"
#include "application/application.h"
#include <QThread>
#include <QProgressBar>
#include <QTimer>
StartNewChat::StartNewChat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartNewChat)
{
    ui->setupUi(this);
        this->setWindowFlags(Qt::FramelessWindowHint | Qt::Window);
}

StartNewChat::~StartNewChat()
{
    delete ui;
}

void StartNewChat::on_pushButton_clicked()
{
    std::string id = ui->contactName->text().toStdString();
    Contact *newContact = new Contact(id);
    Conversation* newConversation = new Conversation(newContact , false , id);
    newConversation->setAnonymously(true);
    Application::loggedUser->addNewConversation(newConversation);
    newConversation->getReceiver()->setImgPath(Application::renderWithPhoto(newContact->getName()));
    emit renderConversation() ;
}


void StartNewChat::on_pushButton_5_clicked()
{
    this->close();
}

