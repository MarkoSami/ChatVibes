
#include "user.h"
#include "message.h"
#include "contact.h"
#include <list>

User::User(std::string ID, std::string user_name, std::string first_name, std::string last_name, std::string password, std::string imgPath, bool loggedIn)
    : ID(ID), user_name(user_name), first_name(first_name), last_name(last_name), password(password), contacts(), messages(), FavouriteMessages(), imgPath(imgPath), loggedIn(loggedIn)
{
}

bool User::addContact( const Contact& newContact){
    this->contacts.push_back(newContact);
    return true;
}

bool User::removeContact(std::string contactID) {
    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
        if (it->getID() == contactID) {
            contacts.erase(it);
            return true; // contact found and removed, return from function
        }
    }
    return false; // contact not found
}

Contact User::findContact(std::string contactID) {

    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
        if (it->getID() == contactID) {
            return *it;
        }
    }
    return Contact(); // contact not found
}

void User::addToFavouriteMessages(Message message,const Conversation& conversation) {


}

void User::removeFromFavouriteMessages(std::string messageID,const Conversation& conversation) {

    for (auto it = messages.begin(); it != messages.end(); ++it) {
        if (it->getID() == messageID) {
            it->isFavourite();
            return ;
        }
    }
}

bool User::addNewMessage( const Message &message){
    this->messages.push_back(message);
    return true;
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
}
void User::setUserName(std::string userName)
{
    this->user_name = userName;
}
std::string User::getUserPassword(){
    return this->password;
}

std::string User::getIMGpath(){
    return this->imgPath;
}
void User::setIMGpath(std::string img)
{
    this->imgPath = img;
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

void User::setLoggedIn(bool value) {
    this->loggedIn = value;
}


