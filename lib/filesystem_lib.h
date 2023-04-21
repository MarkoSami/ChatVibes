
#ifndef FILESYSTEM_LIB_H
#define FILESYSTEM_LIB_H

#include <strings.h>
#include<iostream>
#include<QFile>
#include<QDir>
#include <QJsonDocument>
#include <QJsonObject>
#include<QJsonArray>
#include "logic/user.h"
#include "logic/contact.h"
#include "application/application.h"
#include "logic/message.h"
#include <QDebug>

class fileSystem_lib
{
private :
    static  std::string PATH;
    static std::string fullPath;

//    static bool setUpFileSystem(){

//        QFile file(QString (fullPath.c_str() ) );

//        if(file.exists()){
//            return false;
//        }

//        if(file.open(QIODevice::WriteOnly)){
//            file.write("{}"); // Write an empty JSON object to the file
//            file.close();
//        }
//        return true;
//    }


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
    static   QJsonObject createNewJSONContact(Contact &contact){
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
    static   QJsonObject createNewJSONUser(User user){



        // preparing user data
        QJsonObject userData;
//        if( (&user) == nullptr ||user.getUserID().empty() || user.getUserName().empty() || user.getUserPassword().empty()){
//            return userData ;
//        }
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
            favMessages.append(createNewJSONMessage(message));
        }
        userData["favMessages"] = favMessages;

        return userData;

    }

    // _______this function constructs the users document to be ready to save at the disk
    static   QJsonDocument buildUsersJSONDocument(std::list<User> users){
        QJsonArray JSONUsers;
         for(auto &user : users){
            JSONUsers.append(createNewJSONUser(user));
        }

        return (QJsonDocument(JSONUsers));
    }

    //_______ this function saves takes a JSON document and save it to the disk
    static   bool storeJSONDocument(QJsonDocument &document){
        QFile file("users.json");
        if (file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream out(&file);
            out << document.toJson(QJsonDocument::Indented); // <-- Use QTextStream to write the formatted JSON data to the file
            file.close();
            return true;
        }
        return false;
    }



public:
    fileSystem_lib();
    // sets up the file system if it doesn't exist (can be used on the start of the programm to ensure the file system exists)

    static  bool saveData(){
        // constructing and saving users list in a json file
        QJsonDocument users = buildUsersJSONDocument(Application::users);
        storeJSONDocument(users);
         return true;
    }







};

#endif // FILESYSTEM_LIB_H
