
#include "contact.h"
#include <string.h>
#include<iostream>
#include <list>

Contact::Contact( std::string _ID , std::string _imgPath  , std::string _name  )
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


