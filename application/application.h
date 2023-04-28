
#ifndef APPLICATION_H
#define APPLICATION_H
#include <list>
#include <stack>
#include "logic/user.h"
#include"logic/user.h"
 class Application
{
public:

    Application();

    static std::list<User> users ;
    static User* loggedUser;
    static bool logUserIn(User& user);
    static Conversation *currentConversation ;

    static User* getLogInUser() {
        for (auto &user : Application::users)
        {
            if (user.isLoggedIn()) {
                return &user ;
            }
        }
        return nullptr;
    }


    static User* searchForurUser(std::string userId) {

        for(auto &user : Application::users)
        {
            if(userId == user.getUserID()) {
                return &user;
            }
        }
        return nullptr;
    }

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


    static bool loginUser(std::string id , std::string password)
    {
        if (id.empty() || password.empty()) {
            return false ;
        }

        User *targetUser = Application::searchForurUser(id);

        if(targetUser == nullptr || Application::isAlreadyLoggedIn(*targetUser) || password != targetUser->getUserPassword()){
            return false;
        }

        targetUser->setLoggedIn(true);
        return true;
    }

    static bool isAlreadyLoggedIn(User& user)
    {

        if ((&user) == nullptr || !user.isLoggedIn()) {
            return false;
        }

        return true ;
    }
};

#endif // APPLICATION_H
