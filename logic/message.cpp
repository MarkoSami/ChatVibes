
#include "message.h"

Message::Message(std::string _ID, std::string _messageTxt, std::string _receiverID, QDateTime _sendDate, bool _seen)
{
    this->ID = _ID;
    this->messageTxt = _messageTxt;
    this->receiverID = _receiverID;
    this->sendDate = _sendDate;
    this->seen = _seen;
}


std::string Message::getID()
{
    return ID;
}

std::string Message::getMessageTxt()
{
    return messageTxt;
}

QDateTime Message::getSendDate()
{
    return sendDate;
}

std::string Message::getReceiverId()
{
    return receiverID;
}

bool Message::isSeen()
{
    return seen;
}

void Message::setSeenStatus(bool seenStatus)
{
    seen = seenStatus;
}

