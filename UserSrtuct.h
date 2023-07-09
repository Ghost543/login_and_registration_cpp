//
// Created by ghost on 7/1/23.
//
#include <iostream>
#include <fstream>
#include <filesystem>

#ifndef LOGIN_REGISTER_SYSTEM_USERSRTUCT_H
#define LOGIN_REGISTER_SYSTEM_USERSRTUCT_H

using namespace std;

struct User {
    string user_name;
    long token{};
    string password;
    bool operator ==(const User& other) const{
        return (
                (user_name == other.user_name && token == other.token) ||
                (user_name == other.user_name)
        );
    };
};

ostream& operator << (ostream& stream, const User& user);

istream& operator >> (istream& stream, User& user);

ofstream& operator << (ofstream& file, const User& user);


#endif //LOGIN_REGISTER_SYSTEM_USERSRTUCT_H
