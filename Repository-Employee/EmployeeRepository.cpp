//
// Created by zaxx4 on 03.05.2024.
//

#include "EmployeeRepository.h"
#include <algorithm>

void EmployeeRepository::adjustSalary(Employee &employee, double newSalary) {
    for (int i = 0; i < employees_.size(); i++)
        if (employee.getEmail() == employees_[i].getEmail()) {
            employee.setSalary(newSalary);
            std::cout << "Salary adjusted for " << employee.getName() << std::endl;
        }
}

void EmployeeRepository::addAdmin(Admin &admin) {
    admins_.push_back(admin);
}

void EmployeeRepository::removeAdmin(const string &email) {

}

void EmployeeRepository::addEmployee(Employee &employee) {
    employees_.push_back(employee);
}

void EmployeeRepository::removeEmployee(const string &email) {

}

void EmployeeRepository::removeAdminRights(Admin &admin) {
    Employee employee(admin.getEmail(), admin.getPassword(), admin.getName(),
                      admin.getLastName(), admin.getPosition(), admin.getAbbreviation(),
                      admin.getPhoneNumber(), admin.getAddress(), admin.getRemarks(),
                      admin.getSalary()); //intrebare aici
}

void EmployeeRepository::assignAdminRights(Employee &employee) {
    Admin admin(employee.getEmail(), employee.getPassword(), employee.getName(),
                employee.getLastName(), employee.getPosition(), employee.getAbbreviation(),
                employee.getPhoneNumber(), employee.getAddress(), employee.getRemarks(),
                employee.getSalary(), *this); //intrebare aici
    addAdmin(admin);
    removeEmployee(employee.getEmail());
}

void EmployeeRepository::viewSalary(Employee &employee){
    std::cout << "Salary of " << employee.getName() << ": $" << employee.getSalary() << std::endl;
}

void EmployeeRepository::resetPassword(Employee &employee, string newPassword) {
    employee.setPassword(newPassword);
    std::cout << "Password reset for " << employee.getName() << std::endl;
}

void EmployeeRepository::startData() {

}