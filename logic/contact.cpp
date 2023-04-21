
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

std::string Contact::getID()
{
    return ID;
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
