
#include "user.h"
#include "message.h"
#include "contact.h"
#include <list>

User::User(std::string _ID, std::string _user_name, std::string _first_name, std::string _last_name, std::string _password, std::string _imgPath, bool _loggedIn)
    : ID(_ID), user_name(_user_name),first_name(_first_name),last_name(_last_name), password(_password), contacts(), messages(), FavouriteMessages(), imgPath(_imgPath), loggedIn(_loggedIn)
{

}


// getters
std::string User::getFirstName(){
    return this->first_name;
}

std::string User::getlastName(){
    return this->last_name;
}

std::string User::getUserID(){
    return this->ID;

}
std::string User::getUserName(){
    return this->user_name;
};

std::string User::getUserPassword(){
    return this->password;
}

std::string User::getIMGpath(){
    return this->imgPath;
}

std::list<Message> User::getUserMessages(){
    return this->messages;
}

std::list<Message> User::getFavoriteMessages(){
    return this->FavouriteMessages;
}

std::list<Contact> User::getUserContacts(){
    return this->contacts;
}

bool User::isLoggedIn(){
    return this->loggedIn;
}


