
#ifndef CARSHARING_712_1_CONTROLLER_H
#define CARSHARING_712_1_CONTROLLER_H
#include <iostream>
#include "../Domain-Employee/Employee.h"
#include "../Domain-Order/Order.h"

class Controller {
public:
    void idk() {std::cout<<"ceau";}
    void placeOrder(const Order& order, const Employee& employee);
    void deleteReservation(const std::string& orderNumber, const User& user);
    void listAllOrders() const;
};


#endif //CARSHARING_712_1_CONTROLLER_H
