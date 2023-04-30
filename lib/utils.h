
#ifndef UTILS_H
#define UTILS_H
#include <iostream>
#include<sstream>





class utils
{
public:
    utils();

    static std::string convertAddressToString(void* address){
        std::stringstream ss ;
        ss << address;
        std::string stringAddress = ss.str();
        return stringAddress;
    }
};

#endif // UTILS_H
