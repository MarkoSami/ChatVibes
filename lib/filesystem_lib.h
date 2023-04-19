
#ifndef FILESYSTEM_LIB_H
#define FILESYSTEM_LIB_H

#include <strings.h>
#include<iostream>
#include<QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include<QJsonArray>
#include "logic/user.h"

class fileSystem_lib
{
private :
    static std::string PATH;
public:
    fileSystem_lib();
    // sets up the file system if it doesn't exist (can be used on the start of the programm to ensure the file system exists)
    static bool setUpFileSystem(){

        std::string fullPath = PATH + "User.json";
        QFile file(QString (fullPath.c_str() ) );

        if(file.exists()){
            return false;
        }

        if(file.open(QIODevice::WriteOnly)){
            file.write("{}"); // Write an empty JSON object to the file
            file.close();
            return true;
        }
        return true;
    }


    // ________create a new message QJson object ready to add for QJsonArray
    static QJsonObject createNewMessage(Message &message){
        QJsonObject JSONmessage;
        JSONmessage["ID"] = message.getID().c_str();
        JSONmessage["msgTxt"] = message.getMessageTxt().c_str();
        JSONmessage["seen"] = message.isSeen();
        JSONmessage["sendDate"] = QJsonValue::fromVariant(message.getSendDate());
        return JSONmessage;
    }

    // _______create new user file if it doesn't exist
    static bool createNewUser(User user){

        if(user.getUserID().empty() || user.getUserName().empty() || user.getUserPassword().empty()){
            return false;
        }
        if(!setUpFileSystem()){
            setUpFileSystem();
        }

        // preparing user data
        QJsonObject userData;
        userData["ID"] =  user.getUserID().c_str();
        userData["username"] =  user.getUserID().c_str();
        userData["password"] =  user.getUserID().c_str();
        userData["ID"] =  user.getUserID().c_str();
        userData["loggedIn"] = user.isLoggedIn();
        userData["imgPath"] = user.getIMGpath().c_str();

        // adding user contacts IDs to the QJson array
        QJsonArray contacts;
        for(auto &contact : user.getUserContacts()){
            contacts.append(contact.c_str());
        }
        userData["contacts"] = contacts;

        // adding user messages IDs to the QJson array
        QJsonArray messages;
        for(auto message : user.getUserMessages()){
            messages.append(createNewMessage(message));
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










};

#endif // FILESYSTEM_LIB_H
