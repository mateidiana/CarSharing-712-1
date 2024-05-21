//
// Created by zaxx4 on 03.05.2024.
//

#ifndef CARSHARING_712_1_EMPLOYEEREPOSITORY_H
#define CARSHARING_712_1_EMPLOYEEREPOSITORY_H
#include <vector>
#include <stdexcept>
#include "../Domain-Employee/Employee.h"
#include "../Domain-Admin/Admin.h"

class EmployeeRepository{

private:

    vector<Employee> employees_;
    vector<Admin> admins_;

public:

    EmployeeRepository(const vector<Employee> &employees_, const vector<Admin> &admins_) : employees_(employees_), admins_(admins_) {};
    void viewSalary(Employee &employee);
    void adjustSalary(Employee &employee, double newSalary);
    void assignAdminRights(Employee &employee);
    void resetPassword(Employee &employee, string newPassword);
    void removeAdminRights(Admin &admin);
    void addAdmin(Admin &admin);
    void addEmployee(Employee &employee);
    void removeEmployee(const string &email);
    void removeAdmin(const string &email);

    //Functii noi adaugate

    vector<Employee> getAllEmployees() const;
    vector<Employee> searchEmployeesByNameAndLastName(const string &name, const string &lastName) const;
    vector<Employee> searchEmployeesByBirthDateRange(const string &startDate, const string &endDate) const;
};

    //Matei Dana-Maria
    void setupUnitTests();
    //Matei Dana-Maria
    void startData();
    //Matei Dana-Maria
    Employee* searchEmployeeByAbbreviation(const std::string &abbreviation);
    //Matei Dana-Maria
    Employee* searchEmployeeByEmail(const std::string &email);
};

#endif //CARSHARING_712_1_EMPLOYEEREPOSITORY_H
