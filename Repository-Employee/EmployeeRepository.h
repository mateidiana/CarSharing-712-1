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
    std::vector<Employee> employees_;
    std::vector<Admin> admins_;

public:
    EmployeeRepository(const std::vector<Employee> &employees_, const std::vector<Admin> &admins_) : employees_(employees_), admins_(admins_) {};

    void viewSalary(Employee &employee);
    void adjustSalary(Employee &employee, double newSalary);
    void assignAdminRights(Employee &employee);
    void resetPassword(Employee &employee, std::string newPassword);
    void removeAdminRights(Admin &admin);

    void addAdmin(Admin &admin);
    void addEmployee(Employee &employee);
    void removeEmployee(const std::string &email);
    void removeAdmin(const std::string &email);

    std::vector<Employee> searchEmployeesByBirthDateRange(const std::string &startDate, const std::string &endDate) const;
    std::vector<Employee> searchEmployeesByNameAndLastName(const std::string &name, const std::string &lastName) const;
    std::vector<Employee> getAllEmployees() const;
    //vector<Employee> searchEmployeesByNameAndLastName(const string &name, const string &lastName) const;

    vector<Employee> getAllEmployees() const;

    void setupUnitTests();

    //Matei Dana-Maria -> M4.2
    Employee* searchEmployeeByAbbreviation(const std::string &abbreviation);
    //Matei Dana-Maria
    void startData();
    //Matei Dana-Maria -> M4.3
    Employee* searchEmployeeByEmail(const std::string &email);
};

#endif //CARSHARING_712_1_EMPLOYEEREPOSITORY_H
