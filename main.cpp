#include <iostream>
#include <vector>


#include "LoginException.h"
#include "UserSrtuct.h"
#include "UserData.h"
//#include <range>

using namespace std;

filesystem::path cwd = filesystem::current_path().parent_path();



// read from file

//ifstream& operator >> (ifstream stream, User& user){
//
//}

void read_users_from_file() {
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

        cout << user;

        cout << "\n" << endl;
    }
    file.close();
}
// save into a file


void save_user_to_file(const User& user) {
    ofstream file(cwd.append("data").append("user.data").string(), ios::app);
    if (file.is_open()){
        file << user;
        file.close();
    }

}

// login
User login(const string& user_name, const string& password, vector<User>& users) {
    User user ;
    vector<User>::iterator user_iter;
    for(user_iter = users.begin(); user_iter != users.end(); ++user_iter){
        if (user_iter->user_name == user_name) {
            user = *user_iter;
            break;

        } else {
            throw LoginException{};
        }
    }

    if (user.password != password) {
        throw LoginException{};
    }
    return user;
}
// register
void register_user (User& user, vector<User>& users) {
    vector<User>::iterator user_iter;
    user_iter = std::find(users.begin(), users.end(), user);
    if (user_iter != users.end())
        cout << "This user is already in the registered" << endl;
    else
        users.push_back(user);
}

void print_users (vector<User>& users) {
    vector<User>::iterator user_iter;
    for(user_iter = users.begin(); user_iter != users.end(); ++ user_iter) {
        cout << *user_iter << endl;
    }

}


int main() {
    cout << "Register and Login system" << endl;

    auto userData = UserData();


    // login test
    cout << "!! Login Test !!"<<endl;
    User user_login;
    cin >> user_login;
    userData.login_user(user_login.user_name, user_login.password);
    cout << "*!! End Login Test !!*"<<endl;


    // register test
//    cout << "!! Register Test !!" << endl;
//    User user_register;
//    cin >> user_register;
//    userData.register_user(user_register);
//    cout << "*!! End Register Test !!*" << endl;

    // display all users




//    vector<User> users;
//    users = { { .user_name =  "Mathew", .token =  6921774253641605605, .password =  "lim" } };
//
//    // login
//    cout << "Login" << endl;
//
//    try {
//        User logedin_user = login("Mathew", "lim",users);
//        cout << logedin_user << endl;
//    } catch (const exception& ex) {
//        cout << ex.what() << endl;
//    }
//
//    cout << "Register" << endl;
//    User user;
//    cin >> user;
//    cout << user << endl;
//    save_user_to_file(user);
//
//    register_user(user, users);
//    cout << "Iterator" << endl;
//    print_users(users);
//
//
//    read_users_from_file();
    return 0;
}
