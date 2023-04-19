
#include "message.h"

Message::Message(std::string _ID, std::string _messageTxt, std::string _receiverID, QDateTime _sendDate, bool _seen)
{
    this->ID = _ID;
    this->messageTxt = _messageTxt;
    this->receiverID = _receiverID;
    this->sendDate = _sendDate;
    this->seen = _seen;
}

