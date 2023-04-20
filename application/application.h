
#ifndef APPLICATION_H
#define APPLICATION_H
#include "logic/user.h"



class Application
{
public:
    Application();
    bool registerUser(User& user);
    bool logUserIn(User& user);
};

#endif // APPLICATION_H
