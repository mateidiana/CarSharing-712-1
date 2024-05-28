//
// Created by so17 on 5/26/24.
//

#ifndef CARSHARING_712_1_CUSTOMERUI_H
#define CARSHARING_712_1_CUSTOMERUI_H
#include "../Controller-Customers/CustomerController.h"

class CustomerUI{

private:
    CustomerController& controller;

public:
    CustomerUI(CustomerController& controller);
    void showMenu();
    void login();
    void addCustomer();
    void addToFavourites();
    void seeFavouriteList();


};













#endif //CARSHARING_712_1_CUSTOMERUI_H
