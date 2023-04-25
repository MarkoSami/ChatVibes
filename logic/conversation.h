
#ifndef CONVERSATION_H
#define CONVERSATION_H
#include<iostream>
#include<string.h>
#include "logic/contact.h"
#include "logic/message.h"
#include <list>

class Conversation
{
private:

    Contact receiver;
    std::list<Message> messages;
    std::string name;
    bool isFavourite;



public:
    Conversation(Contact _receiver, bool _isFavourite = false,std::string _name = "");
    // Setters
    void setReceiver(Contact _receiver) { receiver = _receiver; }
    void setName(std::string _name) { name = _name; }
    void setIsFavourite(bool _isFavourite) { isFavourite = _isFavourite; }

    // Getters
    Contact getReceiver(){ return receiver; }
    std::list<Message> getMessages()   { return messages; }
    std::string getName(){ return name; }
    bool getIsFavourite(){ return isFavourite; }

    bool addNewMessage(Message& newMessage);
};

#endif // CONVERSATION_H
