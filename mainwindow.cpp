
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
#include "lib/filesystem_lib.h"
#include "addcontact.h"
#include <QPropertyAnimation>
#include "startnewchat.h"
#include "application/application.h"
#include <QScrollBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QCoreApplication::setAttribute(Qt::AA_UseOpenGLES);
     ui->setupUi(this);
    // Set the window to open as full screen

    GUI_lib::setUpWindow(this, "Chat Vibes", ":/imgs/logo.png");
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Window);

    ui->scrollAreaWidgetContents->setContentsMargins(9,20,9,40);
    ui->scrollArea_2->verticalScrollBar()->setSingleStep(6);
    for (int i = 0; i < 5; i++) {
        QHBoxLayout *hLayout = new QHBoxLayout;
        QVBoxLayout *VLayout = new QVBoxLayout ;
        QLabel *textmsg = new QLabel("Hello , how are u ? ") ;
        textmsg->setTextInteractionFlags(Qt::TextSelectableByMouse);
         // Set the cursor to the I-beam cursor
        textmsg->setCursor(Qt::IBeamCursor);
        QLabel *datemsg = new QLabel("1:00Am");
        textmsg->setWordWrap(true);
        VLayout->addWidget(textmsg);
        VLayout->addWidget(datemsg);
        datemsg->setAlignment(Qt::AlignRight);
        datemsg->setStyleSheet("color:grey; font-size:11px");

        QGroupBox *VGroupBox = new QGroupBox();
        VLayout->setSpacing(0);
        VGroupBox->setLayout(VLayout);
        VGroupBox->setStyleSheet("background:#161a1d; font-size:15px ; color:white ;font-weight:bold ");
        QSpacerItem *hSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
        if (i % 2 == 0 ) {
        hLayout->addWidget(VGroupBox);
        hLayout->addItem(hSpacer);
        }
        if (i % 2 != 0 ) {
        textmsg->setText("i'm Fine XD");
        hLayout->addItem(hSpacer);
        hLayout->addWidget(VGroupBox);
        }

        QGroupBox *hGroupBox = new QGroupBox();
        hGroupBox->setLayout(hLayout);
        ui->verticalGroupBox_3->layout()->addWidget(hGroupBox);
    }

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
      profWin = new profileWindow() ;
      profWin->show();
}


void MainWindow::on_pushButton_clicked()
{
      StartNewChatWin = new StartNewChat();
      StartNewChatWin->show();
}

