//
// Created by josef on 30.04.2024.
//

#include "Controller.h"

void Controller::placeOrder(const Order& order, const Employee& employee) {
    employee.placeOrder(order);
    orderRepository.addOrder(order);
}

void Controller::deleteReservation(const std::string& orderNumber, const User& user) {
    Order* order = orderRepository.searchOrderByNumber(orderNumber);
    if (order) {
        if (typeid(user) == typeid(Employee) || (typeid(user) == typeid(Customer) && order->getCustomer().getEmail() == user.getEmail())) {
            orderRepository.removeOrder(orderNumber);
            std::cout << "Reservation deleted." << std::endl;
        } else {
            std::cout << "You don't have permission to delete this reservation." << std::endl;
        }
    } else {
        std::cout << "Reservation not found." << std::endl;
    }
}

void Controller::listAllOrders() const {
    std::vector<Order> orders = orderRepository.getAllOrders();
    for (const auto& order : orders) {
        order.printDetails();
    }
}