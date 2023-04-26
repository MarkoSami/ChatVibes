
#include "application/application.h"
#include"logic/user.h"
#include "logic/contact.h"


std::list<User> Application::users = {};
std::stack<Conversation> Application::conversations ;
User* Application::loggedUser = nullptr;

Application::Application()
{

}





// User("starterUser","starterUser","starterUser","fdsfs","dsfsdf","dsff",true)
