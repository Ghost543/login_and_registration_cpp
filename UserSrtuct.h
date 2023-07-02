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

ostream& operator << (ostream& stream, const User& user) {
    stream << "User name: " << user.user_name << "\n" << "Token: " << user.token;
    return stream;
}

istream& operator >> (istream& stream, User& user) {
    string user_name;
    string password;
    cout << "User Name: ";
    stream >> user_name;
    cout << "Set Password: ";
    stream >> password;
    hash<string> string_hash;
    long token = string_hash(user_name + password);
    user.user_name = user_name;
    user.token = token;
    user.password = password;

    return stream;
}

ofstream& operator << (ofstream& file, const User& user) {
    file << "/" << user.user_name << "/" << user.token << "/" << user.password << "/#" << endl;
    return file;
}


#endif //LOGIN_REGISTER_SYSTEM_USERSRTUCT_H
