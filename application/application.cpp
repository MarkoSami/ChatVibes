
#include "application/application.h"
#include "logic/user.h"
#include "logic/contact.h"
#include "logic/story.h"

std::list<User*> Application::users = {};
std::map<std::string, std::list<Story*>> Application::stories = {
    {"Marko", {new Story("this is a story", ":/imgs/logo.png", new Contact("mina", ":/imgs/logo.png", "mina"))}}
};

User* Application::loggedUser = nullptr;
Conversation *Application::currentConversation;

Application::Application()
{

}






// User("starterUser","starterUser","starterUser","fdsfs","dsfsdf","dsff",true)
