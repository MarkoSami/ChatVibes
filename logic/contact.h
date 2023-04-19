
#ifndef CONTACT_H
#define CONTACT_H
#include<iostream>
#include<string.h>
 #include "logic/message.h"

class Contact
{
private:
    std::string ID;
    std::string name;
    std::string imgPath;
    std::vector<Message> messages;

public:
    Contact(std::string _ID , std::string _imgPath , std::string _name  );

    std::string getID();

    std::string getImgPath();
    void setImgPath(std::string imgPath);

    std::string getName();
    void setName(std::string name);

    void addMessage(Message message);
    void removeMessage(Message message);
    std::vector<Message> getMessages();



};

#endif // CONTACT_H
