#include <iostream>
#include "Controller/Controller.h"
int main() {
    std::cout << "salut !" << std::endl;
    Controller c;
    Controller controller;
    EmployeeUI employeeUI(controller);

    Employee employee("emp@example.com", "password", "John", "Doe", "Manager", "JD", "1234567890", "123 Street", "", 5000, "1990-01-01");
    Customer customer("cust@example.com", "password", "Jane", "Smith", "1234567890", "456 Avenue", "", 1000, "1995-05-05");

    int choice;
    do {
        std::cout << "1. List all orders\n2. Place an order\n3. Delete a reservation\n4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                employeeUI.listAllOrders();
                break;
            case 2:
                employeeUI.placeOrder(employee);
                break;
            case 3:
                employeeUI.deleteReservation(employee); // or customer
                break;
            case 4:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
    c.idk();
    std::cout<<"Test";
    return 0;
}
