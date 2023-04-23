
#include "application.h"
#include"logic/user.h"

Application::Application()
{

}

   User newuser("14442422", "sadfaf", "marko", "sami", "2234pass", "/dsfsd/",true);


   std::list<User> Application::users = {newuser,User("1234","minsf","mina","melad","2234pass","/dsfsd/"),User("4321","marko","marko","sami","2234pass","/dsfsd/")};

