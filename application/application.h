
#ifndef APPLICATION_H
#define APPLICATION_H
#include <list>
#include <stack>
#include "logic/user.h"
#include"logic/user.h"
#include "logic/conversation.h"
class Application
{
public:

    Application();

    static std::list<User> users ;
    static std::stack<Conversation> conversations;

    static bool logUserIn(User& user);

    static bool registerUser(User& user)
    {
        if(Application::isAlreadyRegistered(user)){
            return false;
        }
        Application::users.push_back(user);
        return true;
    }

    static bool isAlreadyRegistered(User& user)
    {
        std::string userID = user.getUserID();

        for(auto regUser : Application::users)
        {
            if(userID == regUser.getUserID())
                return true;
        }
        return false;
    }

};

#endif // APPLICATION_H
