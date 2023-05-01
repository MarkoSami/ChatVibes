
#include "application/application.h"
#include "logic/user.h"
#include "logic/contact.h"
#include "logic/story.h"

std::list<User*> Application::users = {};

std::map<std::string, std::list<Story*>> Application::stories = {
    {"mina", {new Story("this is a story1", "image: url(:/imgs/story1.png);", new Contact("mina", ":/imgs/logo.png", "mina")),
              new Story("this is a story2", "image: url(:/imgs/story2.jpg);", new Contact("mina", ":/imgs/logo.png", "mina")),
              new Story("this is a story3", "image: url(:/imgs/story3.jpg);", new Contact("mina", ":/imgs/logo.png", "mina")),
            }},
    {"john", {new Story("this is a story1", "", new Contact("john", ":/imgs/logo.png", "john")), // there's no pic ....
            }}
    // add more contacts and stories here...
};


User* Application::loggedUser = nullptr;
Story* Application::currentStory = nullptr ;
std::list<Story*> Application::currentStoryList ;
Conversation *Application::currentConversation;

Application::Application()
{

}






// User("starterUser","starterUser","starterUser","fdsfs","dsfsdf","dsff",true)
