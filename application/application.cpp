
#include "application.h"
#include"logic/user.h"
#include "logic/contact.h"


 User newuser("14442422", "sadfaf", "marko", "sami", "2234pass", "/dsfsd/",true);
Application::Application()
{
    Contact contact("232342");
    newuser.addContact(contact);
}




   std::list<User> Application::users = {};

