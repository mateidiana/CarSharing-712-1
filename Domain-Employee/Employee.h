//
// Created by zaxx4 on 03.05.2024.
//

#ifndef CARSHARING_712_1_EMPLOYEE_H
#define CARSHARING_712_1_EMPLOYEE_H

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Employee {

private:

    string name_;
    string lastName_;
    string email_;
    string position_;
    string abbreviation_;
    string phoneNumber_;
    string address_;
    string remarks_;
    double salary_;
    string password_;


public:
    Employee(string name, string lastName, string email, string position, string abbreviation, string phoneNumber,
             string address, string remarks, double salary, string password);

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

    const string &getEmail() const;

    void setEmail(const string &email);

    const string &getLastName() const;

    void setLastName(const string &lastName);

    double getSalary() const;

    void setSalary(double salary);

    const string &getPassword() const;

    void setPassword(const string &password);


};

#endif //CARSHARING_712_1_EMPLOYEE_H
