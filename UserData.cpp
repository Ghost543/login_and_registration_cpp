//
// Created by ghost on 7/1/23.
//

#include <iostream>
#include <fstream>
#include <filesystem>

#include "UserData.h"

using namespace std;

filesystem::path cwd = filesystem::current_path().parent_path();

User UserData::find_user(string name) {
    map<int, User>::iterator users_iter;
    users_iter = std::find_if(this->users.begin(), this->users.end(), [&](const pair<int,User>&item)->bool {
        return item.second.user_name == name;
    });
    if (users_iter != users.end()){
        return users_iter->second;
    }else{
        throw "No such User";
    };

}

bool  UserData::is_user_regi(std::string name) {
    map<int, User>::iterator users_iter;
    users_iter = std::find_if(this->users.begin(), this->users.end(), [&](const pair<int,User>&item)->bool {
        return item.second.user_name == name;
    });
    if (users_iter != users.end()){
        return true;
    }
    return false;
}

UserData::UserData() {
    ifstream file(filesystem::current_path().parent_path().append("data").append("user.data").string(), ios::in);
    if (!file.is_open()){

        throw "Something is wrong";
    }

    string stream_buffer;
    while (file >> stream_buffer) {
        cout << stream_buffer << endl;
        string::iterator stream_iter;
        User user;
        string temp[3];
        int count = 0;
        for (stream_iter = ++stream_buffer.begin(); stream_iter != stream_buffer.end(); ++stream_iter) {
            if (*stream_iter == '#')
                continue;
            if (*stream_iter == '/') {
                count ++;
                continue;
            }
            string tem = temp[count];
            temp[count] = tem + *stream_iter;
        }

        user.user_name = temp[0];
        user.token = stol(temp[1]);
        user.password = temp[2];
        users.insert(make_pair(count, user));
        cout << user;

        cout << "\n" << endl;
    }
    file.close();
}

void UserData::register_user(const User& user) {
    if (!this->is_user_regi(user.user_name)) {
        cout << "User: " << user.user_name << "already exists."<< endl;
        abort();
    }
    int len = int(this->users.size());
    this->users.insert(make_pair(len, user));
    UserData::save_user_file(user);
}

void UserData::save_user_file(const User& user) {
    ofstream file(cwd.append("data").append("user.data").string(), ios::app);
    if (file.is_open()){
        file << user;
        file.close();
    }
}

long UserData::login_user(const string& name, const string& password) {
    if (this->is_user_regi(name)) {
        User user = this->find_user(name);
        if (user.password != password) {
            cout << "Invalid login credentials" << endl;
            abort();
        }
        cout << user.user_name << " is logged in!" << endl;
        return user.token;
    }
    cout << "Invalid login credentials" << endl;
    abort();
}

map<int, User> UserData::all_users() {

    return this->users;
}
