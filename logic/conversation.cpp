#include "conversation.h"
#include<string.h>
#include "logic/contact.h"

Conversation::Conversation(Contact _receiver, bool _isFavourite, std::string _name)
    : receiver(_receiver) , isFavourite(_isFavourite)
{
    this->name = (_name == "")? _receiver.getID(): _name;
}

bool Conversation::addNewMessage(Message& newMessage){
    this->messages.push_back(newMessage);
    return true;
}

