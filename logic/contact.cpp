
#include "contact.h"
#include <string.h>
#include<iostream>

Contact::Contact( std::string _ID , std::string _imgPath = ":/imgs/Profile (2).png", std::string _name = "")
{
    this->ID = _ID;
    this->imgPath = _imgPath;
    this->name = _name;
}

Contact::Contact(){

}

std::string Contact::getID(){
    return this->ID;
}

void Contact::addMessage(Message message) {
    messages.push_back(message)    ;
}

void Contact::removeMessage(Message message) {
    for (auto it = messages.begin() ; it != messages.end() ; it++) {
        if (it->getID() == message.getID()) {
            messages.erase(it) ;
        }
    }
}
