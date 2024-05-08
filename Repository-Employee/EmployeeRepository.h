//
// Created by zaxx4 on 03.05.2024.
//

#ifndef CARSHARING_712_1_EMPLOYEEREPOSITORY_H
#define CARSHARING_712_1_EMPLOYEEREPOSITORY_H

#include <vector>
#include <stdexcept>
#include "../Domain-Employee/Employee.h"
#include "../Domain-Admin/Admin.h"

class EmployeeRepository {

private:
    vector<Employee> employees_;

    void startData();

public:
    explicit EmployeeRepository(const vector<Employee> &employees);

    void viewSalary(Employee &employee, bool isAdmin);

    void adjustSalary(Employee &employee, double newSalary, bool isAdmin);

    void assignAdminRights(Employee &employee, bool isAdmin);

    void resetPassword(Employee &employee, string newPassword, bool isAdmin);

    void removeAdminRights(Employee &employee, bool isAdmin);
};


#endif //CARSHARING_712_1_EMPLOYEEREPOSITORY_H
