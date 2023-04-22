
#include "contact.h"
#include <string.h>
#include<iostream>
#include <list>

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

std::string Contact::getImgPath()
{
    return imgPath;
}

void Contact::setImgPath(std::string imgPath)
{
    this->imgPath = imgPath;
}

std::string Contact::getName()
{
    return name;
}

void Contact::setName(std::string name)
{
    this->name = name;
}



std::list<Message> Contact::getMessages()
{
    return messages;
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
