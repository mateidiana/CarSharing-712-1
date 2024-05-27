
#include "EmployeeUI.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void EmployeeUI::printEmployees(const vector<Employee>& employees) const {
    for (const auto& employee : employees) {
        cout << employee.getName() << " " << employee.getLastName() << ", " << employee.getEmail() << endl;
    }
}

void EmployeeUI::listAllEmployees() const {
    auto employees = controller_.getAllEmployees();
    printEmployees(employees);
}

void EmployeeUI::searchEmployeeByNameAndLastName() const {
    string name, lastName;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter last name: ";
    cin >> lastName;
    auto employees = controller_.searchEmployeesByNameAndLastName(name, lastName);
    printEmployees(employees);
}

void EmployeeUI::searchEmployeeByBirthDateRange() const {
    string startDate, endDate;
    cout << "Enter start date (YYYY-MM-DD): ";
    cin >> startDate;
    cout << "Enter end date (YYYY-MM-DD): ";
    cin >> endDate;
    auto employees = controller_.searchEmployeesByBirthDateRange(startDate, endDate);
    printEmployees(employees);
}

//m5
void login(EmployeeController &controller) {
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    if (controller.login(username, password)) {
        std::cout << "Login successful!" << std::endl;
    } else {
        std::cout << "Login failed. Please check your username and password." << std::endl;
    }
}

void resetPassword(auto EmployeeController &controller) {
    int employeeId;
    std::string newPassword;
    std::cout << "Enter employee ID: ";
    std::cin >> employeeId;
    std::cout << "Enter new password: ";
    std::cin >> newPassword;

    if (controller.changePassword(employeeId, newPassword)) {
        std::cout << "Password changed successfully!" << std::endl;
    } else {
        std::cout << "Failed to change password. Please check the employee ID." << std::endl;
    }
}

void updateRemarks(EmployeeController &controller) {
    int employeeId;
    std::string newRemarks;
    std::cout << "Enter employee ID: ";
    std::cin >> employeeId;
    std::cout << "Enter new remarks: ";
    std::cin.ignore(); // To ignore the newline character left in the buffer
    std::getline(std::cin, newRemarks);

    if (controller.updateRemarks(employeeId, newRemarks)) {
        std::cout << "Remarks updated successfully!" << std::endl;
    } else {
        std::cout << "Failed to update remarks. Please check the employee ID." << std::endl;
    }
}
