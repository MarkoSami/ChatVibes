
#ifndef CONVERSATION_H
#define CONVERSATION_H
#include<iostream>
#include<string.h>
#include "logic/contact.h"
#include "logic/message.h"
#include <list>
#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <QGroupBox>
#include <QTextOption>

class Conversation
{
private:

    Contact receiver;
    std::list<Message> messages;
    std::string name;
    bool isFavourite;



public:

    enum messageSide  {
        right ,
        left
    };
    static QString breakText(QString& txt){
        if(txt.size() <=90) return txt;
        QString leftText = txt.mid(0,txt.size()/2);
        QString rightText = txt.mid(txt.size()/2,txt.size()-1);
        return breakText(leftText) + "\n" + breakText(rightText);
    }
    static int getHalfTextSize(QString& txt){
        txt =  txt.mid(0,txt.size()/2) + "\n" +txt.mid(txt.size()/2,txt.size()-1);
        return txt.size();
    }

    Conversation(Contact _receiver, bool _isFavourite = false,std::string _name = "");
    // Setters
    void setReceiver(Contact _receiver) { receiver = _receiver; }
    void setName(std::string _name) { name = _name; }
    void setIsFavourite(bool _isFavourite) { isFavourite = _isFavourite; }

    // Getters
    Contact getReceiver(){ return receiver; }
    std::list<Message> getMessages()   { return messages; }
    std::string getName(){ return name; }
    bool getIsFavourite(){ return isFavourite; }// get is the conversation favourite or not

    bool addNewMessage(const Message &message );
    void setAsFavouriteMessage(std::string messageID);
    \
    void unsetAsFavouriteMessage(std::string messageID);

//_______________________________________
    static QGroupBox* renderMessage(Message message , messageSide messageSide){
        QHBoxLayout *hLayout = new QHBoxLayout;
        QVBoxLayout *VLayout = new QVBoxLayout ;
        QLabel *textmsg = new QLabel() ;
        textmsg->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
         textmsg->setText(QString::fromStdString(message.getMessageTxt()));
        textmsg->setTextInteractionFlags(Qt::TextSelectableByMouse);
        // Set the cursor to the I-beam cursor
        textmsg->setCursor(Qt::IBeamCursor);

        QLabel *datemsg = new QLabel();
        datemsg->setText(message.getSendDate().toString());
        QString txt = textmsg->text();



        textmsg->setText(breakText(txt));
//        textmsg->setWordWrap(true);


        VLayout->addWidget(textmsg);
        VLayout->addWidget(datemsg);
        datemsg->setAlignment(Qt::AlignRight);
        datemsg->setStyleSheet("color:grey; font-size:11px");

        QGroupBox *VGroupBox = new QGroupBox();
        VLayout->setSpacing(0);
        VGroupBox->setLayout(VLayout);
        VGroupBox->setStyleSheet("background:#161a1d; font-size:15px ; color:white ;font-weight:bold ");
        QSpacerItem *hSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        if (messageSide==left) {
        hLayout->addWidget(VGroupBox);
        hLayout->addItem(hSpacer);
        }
        else {
        hLayout->addItem(hSpacer);
        hLayout->addWidget(VGroupBox);
        }
        QGroupBox *hGroupBox = new QGroupBox();
        hGroupBox->setLayout(hLayout);

        return hGroupBox;
    }

};

#endif // CONVERSATION_H
