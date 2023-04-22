
#include "user.h"

#include "user.h"

User::User(std::string ID, std::string user_name, std::string first_name, std::string last_name, std::string password, std::string imgPath, bool loggedIn)
    : ID(ID), user_name(user_name), first_name(first_name), last_name(last_name), password(password), contacts(), messages(), FavouriteMessages(), imgPath(imgPath), loggedIn(loggedIn)
{
}

bool User::addContact(Contact &newContact) {

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
