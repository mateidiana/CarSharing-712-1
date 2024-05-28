
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

void EmployeeUI::printOrders(const std::vector<Order>& orders) const {
    for (const auto& order : orders) {
        order.printDetails();
    }
}

void EmployeeUI::listAllOrders() const {
    controller_.listAllOrders();
}

void EmployeeUI::placeOrder(const Employee& employee) const {
    // Gather order details
    std::string orderNumber, carModel, customerEmail, remarks;
    int totalSum;
    Date orderDate, begin, end;

    std::cout << "Enter order number: ";
    std::cin >> orderNumber;
    std::cout << "Enter car model: ";
    std::cin >> carModel;
    std::cout << "Enter order date (day month year): ";
    std::cin >> orderDate.day >> orderDate.month >> orderDate.year;
    std::cout << "Enter begin date (day month year): ";
    std::cin >> begin.day >> begin.month >> begin.year;
    std::cout << "Enter end date (day month year): ";
    std::cin >> end.day >> end.month >> end.year;
    std::cout << "Enter customer email: ";
    std::cin >> customerEmail;
    std::cout << "Enter total sum: ";
    std::cin >> totalSum;
    std::cout << "Enter remarks: ";
    std::cin >> remarks;

    // Create objects
    Car orderedCar(carModel);
    Customer customer(customerEmail, "", "", "", "", "", "", "", "", 0, "");
    Order order(orderNumber, orderDate, Status::Order, orderedCar, begin, end, customer, employee, totalSum, remarks);

    // Place the order
    controller_.placeOrder(order, employee);
    std::cout << "Order placed successfully." << std::endl;
}

void EmployeeUI::deleteReservation(const User& user) const {
    std::string orderNumber;
    std::cout << "Enter order number to delete: ";
    std::cin >> orderNumber;
    controller_.deleteReservation(orderNumber, user);
}