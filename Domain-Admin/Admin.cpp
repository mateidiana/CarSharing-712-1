//
// Created by zaxx4 on 03.05.2024.
//

#include "Admin.h"

Admin::Admin(const string &name, const string &lastName, const string &email, const string &position,
             const string &abbreviation, const string &phoneNumber, const string &address, const string &remarks,
             double salary, const string &password) : Employee(name, lastName, email, position, abbreviation, phoneNumber, address, remarks,
                                    salary, password) {}


void Admin::adjustSalary(Employee &employee, double newSalary) {
    employee.setSalary(newSalary);
}

void Admin::removeAdminRights(Admin &admin) {
    Employee newEmployee(admin.getName(), admin.getLastName(), admin.getEmail(),
                         admin.getPosition(), admin.getAbbreviation(),
                         admin.getPhoneNumber(), admin.getAddress(), admin.getRemarks(), admin.getSalary(), admin.getPassword());
    delete &admin;
}

void Admin::assignAdminRights(Employee &employee) {
    Admin newAdmin(employee.getName(), employee.getLastName(), employee.getEmail(),
                   employee.getPosition(), employee.getAbbreviation(),
                   employee.getPhoneNumber(), employee.getAddress(),
                   employee.getRemarks(), employee.getSalary(), employee.getPassword());
    delete &employee;
}

void Admin::viewSalary(Employee &employee) {
    cout<<"Salary of "<<employee.getName()<<" "<<employee.getLastName()<<" is: "<<employee.getSalary();
}

void Admin::resetPassword(Employee &employee, string newPassword) {
    employee.setPassword(newPassword);
}
