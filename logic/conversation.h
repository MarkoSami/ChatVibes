
#ifndef CONVERSATION_H
#define CONVERSATION_H
#include<iostream>
#include<string.h>
#include "logic/contact.h"
#include "logic/message.h"
#include <vector>

class Conversation
{
private:
    Contact receiver;
    std::vector<Message> messages;
    std::string name;
    bool isFavourite;



public:
    Conversation(Contact _receiver, bool _isFavourite = false,std::string _name = "");
};

#endif // CONVERSATION_H
