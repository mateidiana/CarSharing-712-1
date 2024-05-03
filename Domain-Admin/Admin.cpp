//
// Created by zaxx4 on 03.05.2024.
//

#include "Admin.h"

Admin::Admin(const string &name, const string &lastName, const string &email, const string &position,
             const string &abbreviation, const string &phoneNumber, const string &address, const string &remarks,
             double salary, const string &password, EmployeeRepository employeeRepository) : Employee(name, lastName, email, position, abbreviation, phoneNumber, address, remarks,
                                    salary, password), employeeRepository(employeeRepository) {

}

void Admin::viewEmployeeSalary(Employee &employee) {
    employeeRepository.viewSalary(employee, isAdmin);
}

void Admin::adjustEmployeeSalary(Employee &employee, double newSalary) {
    employeeRepository.adjustSalary(employee, newSalary, isAdmin);
}

void Admin::assignEmployeeAdminRights(Employee &employee) {
    employeeRepository.assignAdminRights(employee, isAdmin);
}

void Admin::removeEmployeeAdminRights(Employee &employee) {
    employeeRepository.removeAdminRights(employee, isAdmin);
}

void Admin::resetEmployeePassword(Employee &employee, string newPassword) {
    employeeRepository.resetPassword(employee, newPassword, isAdmin);
}


