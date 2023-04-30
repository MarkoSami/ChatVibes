
#ifndef GUI_RENDER_H
#define GUI_RENDER_H

#include <QMainWindow>

#include "customGUI/qclickablegroubox.h"
#include "logic/story.h"
#include "QHBoxLayout"
#include "QVBoxLayout"
#include "QLabel"
#include "QDate"
#include "application/application.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "lib/utils.h"



class GUI_render
{
public:
    GUI_render();

    static void renderStories(MainWindow* mainWindow){


        for(auto& contact : Application::loggedUser->getUserContacts()){
            qDebug()<<Application::loggedUser->getUserName();
            qDebug()<<contact->getName();
            std::list<Story*> storiesList = Application::stories[contact->getName()];
            for(auto& story : storiesList){
                QClickableGroupBox* storyBox = renderStory(story);
                MainWindow::connect(storyBox, &QClickableGroupBox::clicked, [=]() {
                    MainWindow::handleStoryClicked(storyBox);
                });
                mainWindow->getUI()->StoriesContainer->layout()->addWidget(renderStory(story));
            }
        }

    }


    static QClickableGroupBox* renderStory(Story* story){

        QHBoxLayout *hLayout = new QHBoxLayout;
        QVBoxLayout *VLayout = new QVBoxLayout ;
        QHBoxLayout *hLabelChild = new QHBoxLayout ;
        QHBoxLayout *hLabelName = new QHBoxLayout ;
        QLabel *pic = new QLabel() ;

        QString IMG_PATH = QString::fromStdString(story->getPublisher()->getImgPath());
        QSize imgMaxSize = (IMG_PATH == ":/imgs/Profile (2).png")? *new QSize(40,40) : *new QSize(50,40);

        if(IMG_PATH == ":/imgs/Profile (2).png")
            pic->setMaximumSize(imgMaxSize);

        pic->setMinimumSize(imgMaxSize);

        QString imgType = IMG_PATH == ":/imgs/Profile (2).png"? "image" : "border-image";
        pic->setStyleSheet( imgType+  ":url(" + IMG_PATH + ");border-radius:8px");

        QLabel *senderName = new QLabel(QString::fromStdString(story->getPublisher()->getName())) ;
        QLabel *textmsg = new QLabel() ;
        QString texttest = "Start Chat!";
        QSpacerItem* hchildSpacer = new QSpacerItem(10, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
        QSpacerItem* hchildSpacerName = new QSpacerItem(10, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
        hLabelName->addWidget(senderName);
        hLabelName->addItem(hchildSpacerName);
        hLabelName->setContentsMargins(0,0,0,0);
        hLabelChild->addWidget(textmsg) ;
        hLabelChild->addItem(hchildSpacer) ;
        hLabelChild->setContentsMargins(0,0,0,0);

        QGroupBox *hGroupBoxName = new QGroupBox();
        QGroupBox *hGroupBoxChild = new QGroupBox();
        hGroupBoxName->setLayout(hLabelName);
        hGroupBoxChild->setLayout(hLabelChild);
        textmsg->setStyleSheet("color:gray ; font-size :12px ");
        textmsg->setWordWrap(true);
        textmsg->setTextFormat(Qt::RichText);
        VLayout->addWidget(hGroupBoxName);
        VLayout->addWidget(hGroupBoxChild);
        int maxWidth = 130; // Maximum width in pixels
        QFont font("Arial", 12);
        QFontMetrics fontMetrics(font);
        QString elidedText = fontMetrics.elidedText(texttest, Qt::ElideRight, maxWidth);
        textmsg->setText(elidedText);
        QGroupBox *VGroupBox = new QGroupBox();
        VGroupBox->setContentsMargins(0,0,0,0);
        VLayout->setSpacing(4);
        VGroupBox->setLayout(VLayout);
        VGroupBox->setStyleSheet("background:#161a1d; font-size:15px ; color:white ;font-weight:bold ");
        hLayout->addWidget(pic);
        hLayout->addWidget(VGroupBox);

        QClickableGroupBox* storyGroupBox = new QClickableGroupBox();

        storyGroupBox->setLayout(hLayout);
        QSpacerItem* hSpacer = new QSpacerItem(10, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
        storyGroupBox->layout()->addItem(hSpacer);

        QLabel *datemsg = new QLabel();
        datemsg->setText(QDate::currentDate().toString());
        datemsg->setStyleSheet("color:grey; font-size:11px ; background:transparent");

        storyGroupBox->layout()->addWidget(datemsg);
        storyGroupBox->setStyleSheet("QGroupBox { border:none; background :#161a1d ;border-radius : 5px;}") ;

        storyGroupBox->setCursor(Qt::PointingHandCursor);
        storyGroupBox->setObjectName(utils::convertAddressToString(story));

        return storyGroupBox;
    }

};

#endif // GUI_RENDER_H
