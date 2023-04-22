
#ifndef FILESYSTEM_LIB_H
#define FILESYSTEM_LIB_H

#include <strings.h>
#include<iostream>
#include<QFile>
#include<QDir>
#include <list>
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
    static  QJsonObject createNewJSONContact(Contact &contact){
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
    static QJsonObject createNewJSONUser(User user){



        // preparing user data
        QJsonObject userData;
        if( (&user) == nullptr ||user.getUserID().empty() || user.getUserName().empty() || user.getUserPassword().empty()){
            return userData ;
        }
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

    //____ this function creates a new Message object from a QJsonObj
    static  Message createNewMessageObject(const QJsonObject& jsonMessageObj){
        Message message
            (
                jsonMessageObj["ID"].toString().toStdString(),
                jsonMessageObj["msgTxt"].toString().toStdString(),
                jsonMessageObj["receiverID"].toString().toStdString(),
                jsonMessageObj["sendDate"].toVariant().toDateTime(),
                jsonMessageObj["seen"].toBool(),
                jsonMessageObj["Favourite"].toBool()
            );
        return message;
    }

    //____ this function creates a new Contact object from a QJsonObj
    static Contact createNewContactObject(const QJsonObject& jsonContactObj){
        Contact contact
            (
                jsonContactObj["ID"].toString().toStdString(),
                jsonContactObj["imgPath"].toString().toStdString(),
                jsonContactObj["name"].toString().toStdString()
            );
        return contact;
    }

    //_____ this function creates new user object from a user QJsonObj
    static User createNewUserObject(QJsonObject& jsonUserObj){
        // adding basic data from the json Filel oaded from the disk
        User user
            (
                jsonUserObj["ID"].toString().toStdString(),jsonUserObj["userName"].toString().toStdString(),
                jsonUserObj["firstName"].toString().toStdString(),jsonUserObj["lastName"].toString().toStdString(),
                jsonUserObj["password"].toString().toStdString(),jsonUserObj["imgPath"].toString().toStdString(),
                jsonUserObj["loggedIn"].toBool()
            );

            // adding lists data from the json file loaded from the disk

            // adding messages
            QJsonArray jsonMessages = jsonUserObj["messages"].toArray();
            for(auto message : jsonMessages){
                user.addNewMessage(createNewMessageObject(message.toObject()));
            }

            // adding favMessages
            QJsonArray jsonFavMessages = jsonUserObj["favMessages"].toArray();
            for(auto message : jsonFavMessages){
                user.addToFavouriteMessages(createNewMessageObject(message.toObject()));
            }

            // adding contacts
            QJsonArray jsonContacts = jsonUserObj["contacts"].toArray();
            for(auto contact : jsonContacts){
                user.addContact(createNewContactObject(contact.toObject()));
            }

        return user;
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
        /*//______ NEED TO DO THE SAME FOR CONVERSATIONS _________\\*/

         return true;
    }

    //______loading application data from the json files
    static void loadData(){
        QFile file("users.json");
         if (!file.open(QIODevice::ReadOnly)) {
            qWarning("Failed to open file");
            return;
         }
         QByteArray jsonData = file.readAll();
         file.close();

         QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
         if (!jsonDoc.isObject()) {
            qWarning("JSON data is not an object");
            return;
         }

         if (!Application::users.empty()) {
            std::list<User>& mutableUsers = const_cast<std::list<User>&>(Application::users);
            mutableUsers.clear();
         }

         if (jsonDoc.isArray()) {
            QJsonArray jsonArray = jsonDoc.array();
            for (QJsonArray::const_iterator arrayItr = jsonArray.constBegin(); arrayItr != jsonArray.constEnd(); ++arrayItr) {
                if (arrayItr->isObject()) {
                    QJsonObject jsonUserObj = arrayItr->toObject();
                    Application::users.push_back(createNewUserObject(jsonUserObj));
                }
            }
         }

    }



/*std::string _ID, std::string _user_name, std::string _first_name, std::string _last_name, std::string _password, std::string _imgPath, bool _loggedIn)*/



};

#endif // FILESYSTEM_LIB_H
