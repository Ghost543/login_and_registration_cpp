//
// Created by ghost on 5/1/23.
//

#ifndef LOGIN_REGISTER_SYSTEM_LOGINEXCEPTION_H
#define LOGIN_REGISTER_SYSTEM_LOGINEXCEPTION_H

#include <stdexcept>

using namespace std;
class LoginException : public exception{
public:
    const char* what() const noexcept override {
        return "Wrong Credentials";
    }
};


#endif //LOGIN_REGISTER_SYSTEM_LOGINEXCEPTION_H
