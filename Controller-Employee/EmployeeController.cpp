//
// Created by Dell on 5/20/2024.
//

#include "../Controller-Employee/EmployeeController.h"
#include <iostream>

EmployeeController::EmployeeController(EmployeeRepository &repository) : repository_(repository){}
//m5
bool EmployeeController::resetPassword(int employeeId, const std::string &newPassword) {
    Employee employee = repository_.findById(employeeId);
    if (employee.getId() == -1) {
        return false; // angajat negasit
    }
    employee.setPassword(newPassword);
    return repository_.updateEmployee(employee);
}

bool EmployeeController::updateRemarks(int employeeId, const std::string &newRemarks) {
    Employee employee = repository_.findById(employeeId);
    if (employee.getId() == -1) {
        return false; // angajat negasit
    }
    employee.setRemarks(newRemarks);
    return repository_.updateEmployee(employee);
}
bool EmployeeController::login(const std::string &username, const std::string &password) {
    for (const auto &employee : repository_.getAllEmployees()) { // Assuming getAllEmployees() exists
        if (employee.getUsername() == username && employee.getPassword() == password) {
            return true; // Login successful
        }
    }
    return false; // Login failed
}