
#include "user.h"

#include "user.h"

User::User(std::string _ID, std::string _user_name, std::string _first_name, std::string _last_name, std::string _password, std::string _imgPath, bool _loggedIn)
    : ID(_ID), user_name(_user_name),first_name(_first_name),last_name(_last_name), password(_password), contacts(), messages(), FavouriteMessages(), imgPath(_imgPath), loggedIn(_loggedIn)
{

}


