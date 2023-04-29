
#include "application/application.h"
#include"logic/user.h"
#include "logic/contact.h"


std::list<User*> Application::users = {};
User* Application::loggedUser = nullptr;
Conversation *Application::currentConversation;

Application::Application()
{

}





// User("starterUser","starterUser","starterUser","fdsfs","dsfsdf","dsff",true)
