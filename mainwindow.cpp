
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


    connect(&profWin, SIGNAL(exitMainWindow()), this, SLOT(on_pushButton_3_clicked()));
    connect(ui->sendMessageLineEdit, &QLineEdit::returnPressed,
     this, &MainWindow::on_pushButton_7_clicked);
    GUI_lib::setUpWindow(this, "Chat Vibes", ":/imgs/logo.png");
    ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->scrollArea_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Window);
    ui->scrollAreaWidgetContents->setContentsMargins(9,20,9,40);
    ui->scrollArea_2->verticalScrollBar()->setSingleStep(6);

    //-------------------------------------//

    QHBoxLayout *hLayout = new QHBoxLayout;
    QHBoxLayout *hLayoutChild = new QHBoxLayout ;
    QVBoxLayout *VLayout = new QVBoxLayout ;
    QSpacerItem* hChildSpacer = new QSpacerItem(10, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
    QLabel *pic = new QLabel() ;
    pic->setMinimumSize(40, 40);
    pic->setStyleSheet("image: url(:/imgs/Profile (2).png);background:none");

    QLabel *senderName = new QLabel("marko samy") ;
    QLabel *textmsg = new QLabel() ;
    textmsg->setText("Hi");
    textmsg->setLayoutDirection(Qt::LeftToRight);
    textmsg->setAlignment(Qt::AlignLeft);
    textmsg->setStyleSheet("color:gray ; font-size :12px ");
    textmsg->setWordWrap(true);
    textmsg->setTextFormat(Qt::RichText);
    VLayout->addWidget(senderName);

    VLayout->addWidget(textmsg);

    QGroupBox *HGroupBoxChild = new QGroupBox();

    QGroupBox *VGroupBox = new QGroupBox();
    VLayout->setSpacing(4);
    VGroupBox->setLayout(VLayout);
    VGroupBox->setStyleSheet("background:#161a1d; font-size:15px ; color:white ;font-weight:bold ");
    HGroupBoxChild->setLayout(hLayoutChild);
    HGroupBoxChild->layout()->addItem(hChildSpacer);
    hLayout->addWidget(pic);
    hLayout->addWidget(HGroupBoxChild);

    QGroupBox *hGroupBox = new QGroupBox();
    hGroupBox->setLayout(hLayout);
    QSpacerItem* hSpacer = new QSpacerItem(10, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
    hGroupBox->layout()->addItem(hSpacer);

    QLabel *datemsg = new QLabel();
    datemsg->setText(QDate::currentDate().toString());
    datemsg->setStyleSheet("color:grey; font-size:11px ; background:transparent");

    hGroupBox->layout()->addWidget(datemsg);
    hGroupBox->setStyleSheet("QGroupBox { border:none; background :#161a1d ;border-radius : 5px;}") ;
    ui->contactsCont->layout()->addWidget(hGroupBox);

}


MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_3_clicked()
{

//    Application::conversations.push(Conversation(Contact("sdfs")));
    fileSystem_lib::saveData();
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


void MainWindow::on_pushButton_5_clicked()
{
     addContactWin = new AddContact() ;
      addContactWin->show();
}


void MainWindow::on_pushButton_6_clicked()
{
      profWin.show();
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
