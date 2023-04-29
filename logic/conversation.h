
#ifndef CONVERSATION_H
#define CONVERSATION_H
#include<iostream>
#include<string.h>
#include "logic/contact.h"
#include "logic/message.h"
#include "customGUI/qclickablegroubox.h"
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

    Contact* receiver;   // consider it as sender not reciever
    std::list<Message*> messages;
    std::string name;
    bool isFavourite;




public:

    enum messageSide  {
        right ,
        left
    };

    static QString breakText(QString& txt){

        if(txt.size() <=70) return txt;
        QString leftText = txt.mid(0,txt.size()/2);
        QString rightText = txt.mid(txt.size()/2,txt.size()-1);
        return breakText(leftText) + "\n" + breakText(rightText);
    }
    static int getHalfTextSize(QString& txt){
        txt =  txt.mid(0,txt.size()/2) + "\n" +txt.mid(txt.size()/2,txt.size()-1);
        return txt.size();
    }

    Conversation(Contact *_receiver, bool _isFavourite = false,std::string _name = "");
    // Setters
    void setReceiver(Contact _receiver) {
        receiver->setName(_receiver.getName());
        receiver->setImgPath(_receiver.getImgPath());
    }
    void setName(std::string _name) { name = _name; }
    void setIsFavourite(bool _isFavourite) { isFavourite = _isFavourite; }

    // Getters
    Contact* getReceiver(){ return receiver; }
    std::list<Message*> getMessages()   { return messages; }
    std::string getName(){ return name; }
    bool getIsFavourite(){ return isFavourite; }// get is the conversation favourite or not

    bool addNewMessage( Message *message );
    void setAsFavouriteMessage(std::string messageID);
    \
    void unsetAsFavouriteMessage(std::string messageID);

//_______________________________________






};

#endif // CONVERSATION_H
