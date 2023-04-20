
#ifndef FILESYSTEM_LIB_H
#define FILESYSTEM_LIB_H

#include <strings.h>
#include<iostream>
#include<QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include<QJsonArray>
#include "logic/user.h"
#include "logic/contact.h"

class fileSystem_lib
{
private :
    static  std::string PATH;
    static std::string fullPath;

public:
    fileSystem_lib();
    // sets up the file system if it doesn't exist (can be used on the start of the programm to ensure the file system exists)
    static bool setUpFileSystem(){

        QFile file(QString (fullPath.c_str() ) );

        if(file.exists()){
            return false;
        }

        if(file.open(QIODevice::WriteOnly)){
            file.write("{}"); // Write an empty JSON object to the file
            file.close();
        }
        return true;
    }


    // ________create a new message QJson object ready to add for QJsonArray
    static QJsonObject createNewJSONMessage(Message &message){
        QJsonObject JSONmessage;
        JSONmessage["ID"] = message.getID().c_str();
        JSONmessage["msgTxt"] = message.getMessageTxt().c_str();
        JSONmessage["seen"] = message.isSeen();
        JSONmessage["sendDate"] = QJsonValue::fromVariant(message.getSendDate());
        JSONmessage["receiverID"] = message.getReceiverId().c_str();
        return JSONmessage;
    }

    // ________create a new Contact QJson object ready to add for QJsonArray
    static QJsonObject createNewJSONContact(Contact &contact){
        QJsonObject JSONContact;
        JSONContact["ID"] = contact.getID().c_str();
        JSONContact["name"] = contact.getName().c_str();
        JSONContact["imgPath"] = contact.getImgPath().c_str();

        QJsonArray messages;
        for(auto message : contact.getMessages()){
            messages.append(createNewJSONMessage(message));
        }

        JSONContact["messages"] = messages;
        return JSONContact;

    }

    // _______create new user file if it doesn't exist
    static bool createNewJSONUser(User user){

        if( (&user) == nullptr ||user.getUserID().empty() || user.getUserName().empty() || user.getUserPassword().empty()){
            return false;
        }
        if(!setUpFileSystem()){
            setUpFileSystem();
        }

        // preparing user data
        QJsonObject userData;
        userData["ID"] =  user.getUserID().c_str();
        userData["firstName"] =  user.getUserName().c_str();
        userData["lastName"] =  user.getlastName().c_str();

        userData["username"] =  user.getUserName().c_str();
        userData["password"] =  user.getUserPassword().c_str();
        userData["loggedIn"] = user.isLoggedIn();
        userData["imgPath"] = user.getIMGpath().c_str();

        // adding user contacts IDs to the QJson array
        QJsonArray contacts;
        for(auto &contact : user.getUserContacts()){
            contacts.append(createNewJSONContact(contact));
        }
        userData["contacts"] = contacts;

        // adding user messages IDs to the QJson array
        QJsonArray messages;
        for(auto message : user.getUserMessages()){
            messages.append(createNewJSONMessage(message));
        }
        userData["messages"] = messages;

        // adding the user favourite messages to the QJsonArray
        QJsonArray favMessages;
        for(auto &message : user.getFavoriteMessages()){
            favMessages.append(message.c_str());
        }
        userData["favMessages"] = favMessages;

        return true;

    }



/*
{
    ID:2342354,
    firstName:marko
    pass
    contacts: [],
    messages: [],
}

*/






};

#endif // FILESYSTEM_LIB_H
