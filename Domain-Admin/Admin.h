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
    EmployeeRepository &employeeRepository;

public:
    Admin(const std::string& email, const std::string& password, const std::string& name, const std::string& lastName,
          const std::string& position, const std::string& abbreviation, const std::string& phoneNumber,
          const std::string& address, const std::string& remarks, double salary, EmployeeRepository& employeeRepo)
            : Employee(email, password, name, lastName, position, abbreviation, phoneNumber, address, remarks, salary),
              employeeRepository(employeeRepo) {}

    void viewEmployeeSalary(Employee &employee);

    void adjustEmployeeSalary(Employee &employee, double newSalary);

    void assignEmployeeAdminRights(Employee &employee);

    void removeEmployeeAdminRights(Admin &admin);

    void resetEmployeePassword(Employee &employee, string newPassword);

};

#endif //CARSHARING_712_1_ADMIN_H
