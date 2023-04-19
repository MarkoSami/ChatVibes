
#ifndef MESSAGE_H
#define MESSAGE_H
#include<iostream>
#include<string.h>
#include<QDateTime>

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

public:
    Message(std::string _ID, std::string _messageTxt ,std::string _receiverID , QDateTime _sendDate, bool _seen  );
    std::string getID();
    std::string getMessageTxt();
    QDateTime getSendDate();
    bool isSeen();
    void setSeenStatus(bool seenStatus);
};

#endif // MESSAGE_H
