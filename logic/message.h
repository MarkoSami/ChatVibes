
#ifndef MESSAGE_H
#define MESSAGE_H
#include<iostream>
#include<string.h>
#include<QDateTime>
#include <QGroupBox>
/*

Message text
Image or video -->extra
voice note without text --->extra
send date
seen
*/


class Message
{

private:
    std::string ID;
    std::string messageTxt;
    std::string receiverID;
    QDateTime sendDate;
    bool seen;
    bool Favourite;

public:
    Message(std::string _ID, std::string _messageTxt ,std::string _receiverID , QDateTime _sendDate, bool _seen , bool Favourite );
    std::string getID();
    std::string getMessageTxt();
    QDateTime getSendDate();
    std::string getReceiverId();
    bool isSeen();
    bool isFavourite();
    void setSeenStatus(bool seenStatus);

};

#endif // MESSAGE_H
