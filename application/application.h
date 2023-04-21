
#ifndef APPLICATION_H
#define APPLICATION_H
#include "logic/user.h"
#include <list>
#include"logic/user.h"
#include "logic/conversation.h"

class Application
{
public:

    Application();
    static std::list<User> users;
    static std::list<Conversation> conversations;
    static bool registerUser(User& user);
    static bool logUserIn(User& user);
};

#endif // APPLICATION_H
