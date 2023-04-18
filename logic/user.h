
#ifndef USER_H
#define USER_H
#include<iostream>
#include <string.h>
#include<vector>
#include "message.h"



class User
{
private:
    std::string ID;
    std::string user_name;
    std::string password;
    std::vector<std::string> contacts;
    std::vector<Message> messages;
    std::vector<std::string> FavouriteMessages;
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

    std::vector<std::string> getUserContacts();
    void setUserContacts(std::vector<std::string> &contacts);

    std::vector<Message> getUserMessages();
    void setUserMessages(std::vector<Message> &messages);

    std::vector<std::string> getFavoriteMessages();
    void setFavoriteMessages(std::vector<std::string> &favMessages);

    std::string getIMGpath();
    void setIMGpath(std::string);


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
