#include "logic/conversation.h"
#include<string.h>
#include "logic/contact.h"
#include <string>
#include <vector>


Conversation::Conversation(Contact _receiver, bool _isFavourite, std::string _name)
    : receiver(_receiver) , isFavourite(_isFavourite)
{
    this->name = (_name == "")? _receiver.getID(): _name;
}

bool Conversation::addNewMessage(const Message& newMessage){
    this->messages.push_back(newMessage);
    return true;
}





