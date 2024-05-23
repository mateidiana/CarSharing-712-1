//
// Created by zaxx4 on 18.05.2024.
//
#include <iostream>
#include <string>
using namespace std;
#ifndef CARSHARING_USER_H
#define CARSHARING_USER_H

class User{

protected:
    string email_;
    string password_;

public:
    explicit User(const string &email, const string &password);

    const string &getEmail() const;

    void setEmail(const string &email);

    const string &getPassword() const;

    void setPassword(const string &password);

    bool authenticate(const string &email, const string &password);

};
#endif //CARSHARING_USER_H
