//
// Created by zaxx4 on 03.05.2024.
//

#ifndef CARSHARING_712_1_ADMIN_H
#define CARSHARING_712_1_ADMIN_H

#include <iostream>
#include <string>
#include <stdexcept>
#include "../Domain-Employee/Employee.h"
#include "../Repository-Employee/EmployeeRepository.h"

using namespace std;

class Admin : public Employee {

private:
    EmployeeRepository employeeRepository;
    bool isAdmin = true;
    bool isCustomer = false;
    bool isEmployee = false;

public:
    Admin(const string &name, const string &lastName, const string &email, const string &position,
          const string &abbreviation, const string &phoneNumber, const string &address, const string &remarks,
          double salary, const string &password, EmployeeRepository employeeRepository);

    void viewEmployeeSalary(Employee &employee);

    void adjustEmployeeSalary(Employee &employee, double newSalary);

    void assignEmployeeAdminRights(Employee &employee);

    void removeEmployeeAdminRights(Admin &admin);

    void resetEmployeePassword(Employee &employee, string newPassword);

    void removeEmployeeAdminRights(Employee &employee);
};

#endif //CARSHARING_712_1_ADMIN_H
