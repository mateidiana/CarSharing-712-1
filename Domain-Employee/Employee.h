//
// Created by zaxx4 on 03.05.2024.
//

#ifndef CARSHARING_712_1_EMPLOYEE_H
#define CARSHARING_712_1_EMPLOYEE_H
#include <iostream>
#include <string>
#include <stdexcept>
#include "../Domain-User/User.h"

using namespace std;

class Employee : public User {

private:

    string name_;
    string lastName_;
    string position_;
    string abbreviation_;
    string phoneNumber_;
    string address_;
    string remarks_;
    double salary_;


public:

    Employee(const string& email, const string& password,
             const string& name, const string& lastName,
             const string& position, const string& abbreviation,
             const string& phoneNumber, const string& address,
             const string& remarks, double salary)
            : User(email, password), name_(name), lastName_(lastName), position_(position),
              abbreviation_(abbreviation), phoneNumber_(phoneNumber), address_(address),
              remarks_(remarks), salary_(salary) {}

    const string &getRemarks() const;

    void setRemarks(const string &remarks);

    const string &getAddress() const;

    void setAddress(const string &address);

    const string &getPhoneNumber() const;

    void setPhoneNumber(const string &phoneNumber);

    const string &getAbbreviation() const;

    void setAbbreviation(const string &abbreviation);

    const string &getPosition() const;

    void setPosition(const string &position);

    void setName(const string &name);

    const string &getName() const;

    const string &getLastName() const;

    void setLastName(const string &lastName);

    double getSalary() const;

    void setSalary(double salary);

};

#endif //CARSHARING_712_1_EMPLOYEE_H
