
#include "application/application.h"
#include "logic/user.h"
#include "logic/contact.h"
#include "logic/story.h"

std::list<User*> Application::users = {};
std::list<Story*> Application::stories = {(new Story("this is a story",":/imgs/logo.png",new Contact("mina",":/imgs/logo.png","mina"))),(new Story("this is a story",":/imgs/logo.png",new Contact("marko",":/imgs/logo.png","Marko"))),(new Story("this is a story",":/imgs/logo.png",new Contact("marko",":/imgs/logo.png","Marko"))),(new Story("this is a story",":/imgs/logo.png",new Contact("marko",":/imgs/logo.png","Marko"))),(new Story("this is a story",":/imgs/logo.png",new Contact("marko",":/imgs/logo.png","Marko"))),(new Story("this is a story",":/imgs/logo.png",new Contact("marko",":/imgs/logo.png","Marko"))),(new Story("this is a story",":/imgs/logo.png",new Contact("marko",":/imgs/logo.png","Marko"))),(new Story("this is a story",":/imgs/logo.png",new Contact("marko",":/imgs/logo.png","Marko"))),(new Story("this is a story",":/imgs/logo.png",new Contact("marko",":/imgs/logo.png","Marko"))),(new Story("this is a story",":/imgs/logo.png",new Contact("marko",":/imgs/logo.png","Marko"))),(new Story("this is a story",":/imgs/logo.png",new Contact("marko",":/imgs/logo.png","Marko"))),(new Story("this is a story",":/imgs/logo.png",new Contact("marko",":/imgs/logo.png","Marko")))};

User* Application::loggedUser = nullptr;
Conversation *Application::currentConversation;

Application::Application()
{

}





// User("starterUser","starterUser","starterUser","fdsfs","dsfsdf","dsff",true)
