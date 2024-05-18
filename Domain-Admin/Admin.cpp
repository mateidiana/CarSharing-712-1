//
// Created by zaxx4 on 03.05.2024.
//

#include "Admin.h"


void Admin::viewEmployeeSalary(Employee &employee) {
    employeeRepository.viewSalary(employee);
}

void Admin::adjustEmployeeSalary(Employee &employee, double newSalary) {
    employeeRepository.adjustSalary(employee, newSalary);
}

void Admin::assignEmployeeAdminRights(Employee &employee) {
    employeeRepository.assignAdminRights(employee);
}

void Admin::removeEmployeeAdminRights(Admin &admin) {
    employeeRepository.removeAdminRights(admin);
}

void Admin::resetEmployeePassword(Employee &employee, string newPassword) {
    employeeRepository.resetPassword(employee, newPassword);
}



