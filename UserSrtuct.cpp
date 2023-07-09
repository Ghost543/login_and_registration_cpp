//
// Created by ghost on 7/1/23.
//

#include <iostream>
#include <fstream>
#include <filesystem>

#include "UserSrtuct.h"

using namespace std;

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
    hash<string> stringHash;
    long token = stringHash(user_name + password);
    user.user_name = user_name;
    user.token = token;
    user.password = password;

    return stream;
}

ofstream& operator << (ofstream& file, const User& user) {
    file << "/" << user.user_name << "/" << user.token << "/" << user.password << "/#" << endl;
    return file;
}
