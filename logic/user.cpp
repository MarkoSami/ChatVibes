
#include "user.h"
#include "message.h"
#include "contact.h"
#include <list>

User::User(std::string ID, std::string user_name, std::string first_name, std::string last_name, std::string password, std::string imgPath, bool loggedIn)
    : ID(ID), user_name(user_name), first_name(first_name), last_name(last_name), password(password), contacts(), messages(), FavouriteMessages(), imgPath(imgPath), loggedIn(loggedIn)
{
}

bool User::addContact(Contact &newContact) {

<<<<<<< HEAD
    // Check if the contact already exists
    for (auto &contact : contacts) {
        if (contact.getID() == newContact.getID()) {
            // Contact already exists, return false
            return false;
        }
    }

    // Add the new contact
    contacts.push_back(newContact);

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

void User::addToFavouriteMessages(std::string messageID) {

    for (auto it = messages.begin(); it != messages.end(); ++it) {
        if (it->getID() == messageID) {
            it->isFavourite();
            return ;
        }
    }
}

void User::removeFromFavouriteMessages(std::string messageID) {

    for (auto it = messages.begin(); it != messages.end(); ++it) {
        if (it->getID() == messageID) {
            it->isFavourite();
            return ;
        }
    }
}
=======
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

bool User::addNewMessage( const Message &message){
    this->messages.push_back(message);
    return true;
}

bool User::addToFavouriteMessages( const Message& message){
    this->FavouriteMessages.push_back(message);
    return true;
}

bool User::addContact( const Contact& newContact){
    this->contacts.push_back(newContact);
    return true;
}

>>>>>>> 904ca86c456cab439afdf13f84232e641f54e921
