
#ifndef USER_H
#define USER_H
#include<iostream>
#include <string.h>
#include<list>
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
    std::list<Contact> contacts;
    std::list<Message> messages;
    std::list<Message> FavouriteMessages;
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

    std::list<Contact> getUserContacts();
    void setUserContacts(std::list<std::string> &contacts);

    std::list<Message> getUserMessages();
    void setUserMessages(std::list<Message> &messages);

    std::list<Message> getFavoriteMessages();
    void setFavoriteMessages(std::list<std::string> &favMessages);

    std::string getIMGpath();
    void setIMGpath(std::string);

    std::string getlastName();
    void setlastName(std::string name);

    std::string getFirstName();
    void setFirstName(std::string name);


    // user logic functions
    bool isLoggedIn();
    bool addContact(const Contact& newContact);
    bool removeContact(std::string contactID);
    Contact findContact(std::string contactID);
    void addToFavouriteMessages(Message message);
    void removeFromFavouriteMessages(std::string messageID);
    bool addNewMessage(const Message &message);




};

#endif // USER_H
