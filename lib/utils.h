
#ifndef UTILS_H
#define UTILS_H
#include <iostream>
#include<sstream>
#include<QString>





class utils
{
public:
    utils();

    static QString convertAddressToString(void* address){
        std::stringstream ss ;
        ss << address;
        std::string stringAddress = ss.str();
        return stringAddress.c_str();
    }

    static void* convertStringToaddress(QString str){
        std::stringstream ss(str.toStdString());
        void* address;
        ss >> address;// Read the address from the stringstream.
        return address;
    }
};

#endif // UTILS_H
