//
// Created by ghost on 7/1/23.
//

#include <map>

#include "UserSrtuct.h"

#ifndef LOGIN_REGISTER_SYSTEM_USERDATA_H
#define LOGIN_REGISTER_SYSTEM_USERDATA_H

using namespace std;
class UserData {
private:
    map<int, User> users;
    bool is_user_regi(string name);
    static void save_user_file(const User& user);
public:
    UserData();
    void register_user(const User& user);
    long login_user (const string& name, const string& password);
    map<int, User> all_users();
    User find_user(string name);
};


#endif //LOGIN_REGISTER_SYSTEM_USERDATA_H
