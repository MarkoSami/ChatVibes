
#include "contact.h"
#include <string.h>
#include<iostream>

Contact::Contact( std::string _ID , std::string _imgPath = ":/imgs/Profile (2).png", std::string _name = "")
{
    this->ID = _ID;
    this->imgPath = _imgPath;
    this->name = _name;
}

std::string Contact::getID(){
    return this->ID;
}
