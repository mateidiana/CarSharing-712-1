//
// Created by zaxx4 on 03.05.2024.
//

#include "EmployeeRepository.h"

EmployeeRepository::EmployeeRepository(const vector<Employee> &employees) : employees_(employees) {
    startData();
}

void EmployeeRepository::adjustSalary(Employee &employee, double newSalary, bool isAdmin) {
    if (isAdmin)
        employee.setSalary(newSalary);
    else throw invalid_argument("Only administrators are allowed to modify salaries.");
}

void EmployeeRepository::removeAdminRights(Employee &employee, bool isAdmin) {
    if (isAdmin) {
        //adaugam bool-urile alea la clase? ca sa pot da drepturi de admin unui angajat
    } else throw invalid_argument("Only administrators are allowed to remove administrator rights.");
}

void EmployeeRepository::assignAdminRights(Employee &employee, bool isAdmin) {
    if (isAdmin) {
        //adaugam bool-urile alea la clase? ca sa pot da drepturi de admin unui angajat
    } else throw invalid_argument("Only administrators are allowed to assign administrator rights.");
}

void EmployeeRepository::viewSalary(Employee &employee, bool isAdmin) {
    if (isAdmin)
        cout << "Salary of " << employee.getName() << " " << employee.getLastName() << " is: " << employee.getSalary();
    else throw invalid_argument("Only administrators are allowed to view employee salaries.");
}

void EmployeeRepository::resetPassword(Employee &employee, string newPassword, bool isAdmin) {
    if (isAdmin)
        employee.setPassword(newPassword);
    else throw invalid_argument("Only administrators are allowed reset employee passwords.");
}

void EmployeeRepository::startData() {
    employees_.push_back(Employee("John", "Doe", "john@example.com", "Manager", "JD", "123456789", "123 Main St",
                                  "Good employee", 50000.0, "password1"));
    employees_.push_back(Employee("Alice", "Smith", "alice@example.com", "Developer", "AS", "987654321", "456 Elm St",
                                  "Hardworking", 60000.0, "password2"));
    employees_.push_back(Employee("Robert", "Johnson", "bob@example.com", "Designer", "RJ", "555555555", "789 Oak St",
                                  "Experienced", 55000.0, "password3"));
    employees_.push_back(Employee("Jane", "Doe", "john@example.com", "Manager", "JD", "123456777", "120 Main St",
                                  "Good employee", 70000.0, "password4"));
}