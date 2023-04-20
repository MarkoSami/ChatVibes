
#ifndef USER_H
#define USER_H
#include<iostream>
#include <string.h>
#include<vector>
#include "message.h"
#include "logic/contact.h"



class User
{
private:
    std::string ID;
    std::string user_name;
    std::string first_name;
    std::string last_name;
    std::string password;
    std::vector<Contact> contacts;
    std::vector<Message> messages;
    std::vector<Message> FavouriteMessages;
    std::string imgPath;
    bool loggedIn;



public:
    User(std::string _ID, std::string _user_name, std::string _first_name, std::string _last_name ,std::string _password, std::string _imgPath = ":/imgs/Profile (2).png", bool _loggedIn = false);
    // getters and setters
    std::string getUserID();
    void setUserID(std::string ID);

    std::string getUserName();
    void setUserName(std::string userName);

    std::string getUserPassword();
    void setUserPassword(std::string password);

    std::vector<Contact> getUserContacts();
    void setUserContacts(std::vector<std::string> &contacts);

    std::vector<Message> getUserMessages();
    void setUserMessages(std::vector<Message> &messages);

    std::vector<std::string> getFavoriteMessages();
    void setFavoriteMessages(std::vector<std::string> &favMessages);

    std::string getIMGpath();
    void setIMGpath(std::string);

    std::string getlastName();
    void setlastName(std::string name);

    std::string getFirstName();
    void setFirstName(std::string name);


    // user logic functions
    bool registerUser();
    bool logUserIn();
    bool isLoggedIn();
    bool addContact(Contact &newContact);
    bool removeContact(std::string contactID);
    User findContact(std::string contactID);
    bool addToFavouriteMessages(std::string messageID);
    bool removeFromFavouriteMessages(std::string messageID);





};

#endif // USER_H
