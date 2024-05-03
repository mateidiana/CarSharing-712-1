//
// Created by zaxx4 on 03.05.2024.
//

#ifndef CARSHARING_712_1_ADMIN_H
#define CARSHARING_712_1_ADMIN_H
#include <iostream>
#include <string>
#include <stdexcept>
#include "../Domain-Employee/Employee.h"

using namespace std;

class Admin : private Employee{

public:
    Admin(const string &name, const string &lastName, const string &email, const string &position,
          const string &abbreviation, const string &phoneNumber, const string &address, const string &remarks,
          double salary, const string &password);

    void viewSalary(Employee &employee);
    void adjustSalary(Employee &employee, double newSalary);
    void assignAdminRights(Employee &employee);
    void removeAdminRights(Admin &admin);
    void resetPassword(Employee &employee, string newPassword);

};

#endif //CARSHARING_712_1_ADMIN_H
