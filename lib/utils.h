
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

    static void* convertStringToaddress(std::string str){
        std::stringstream ss(str);
        void* address;
        ss >> address;// Read the address from the stringstream.
        return address;
    }
};

#endif // UTILS_H
