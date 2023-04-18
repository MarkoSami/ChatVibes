
#ifndef USER_H
#define USER_H
#include<iostream>
#include <string.h>
#include<vector>
 #include "message.h"
/*
--ID
username
password
List of Contacts
Messages
image
*/



class User
{
private:
    std::string ID;
    std::string user_name;
    std::string password;
    std::vector<User> contacts;
    std::vector<Message> messages;
    std::vector<Message> FavouriteMessages;
    std::string imgPath;
    bool loggedIn;



public:
    User();
    // getters and setters
    std::string getUserID();
    void setUserID(std::string ID);

    std::string getUserName();
    void setUserName(std::string userName);

    std::string getUserPassword();
    void setUserPassword(std::string password);

    std::vector<User> getUserContacts();
    void setUserContacts(std::vector<User> &contacts);

    std::vector<User> getUserMessages();
    void setUserMessages(std::vector<User> &messages);

    void setFavoriteMessages(std::vector<Message> &favMessages);
    std::vector<Message> getFavoriteMessages();


    // user logic functions
    bool registerUser();
    bool logUserIn();
    bool isLoggedIn();
    bool addContact(User &newContact);
    bool removeContact(std::string contactID);
    User findContact(std::string contactID);
    bool addToFavouriteMessages(std::string messageID);
    bool removeFromFavouriteMessages(std::string messageID);





};

#endif // USER_H
