
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
    QDateTime sendDate;
    bool seen;

public:
    Message();
};

#endif // MESSAGE_H
