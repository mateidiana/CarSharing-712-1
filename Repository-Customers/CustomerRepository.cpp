//
// Created by Vanessa on 02.05.2024.
//

#include "CustomerRepository.h"
#include "../Controller-Customers/CustomerController.h"
#include "../Domain-Customer/Customer.h"

CustomerRepository::CustomerRepository(const std::vector<Customer>) {
    startData();
}

void CustomerRepository::createCustomer(const Customer& customer) {
    customers_.push_back(customer);
}

void CustomerRepository::modifyCustomer(Customer& customer) {
    if (!customer.authenticate(customer.getEmail(), customer.getPassword())) {
        throw invalid_argument("Customer not found");
    }
    for (int i = 0; i < customers_.size(); i++) {
        if (customers_[i].getId() == customer.getId()) {
            customers_[i] = customer;
            return;
        }
    }
    throw invalid_argument("Customer not found");
}

void CustomerRepository::deleteCustomer(Customer& customer) {
    if (!customer.authenticate(customer.getEmail(), customer.getPassword())) {
        throw invalid_argument("Customer not found");
    }
    for (int i = 0; i < customers_.size(); i++) {
        if (customers_[i].getName() == customer.getName()) {
            customers_.erase(customers_.begin() + i);
            return;
        }
    }
    throw invalid_argument("Customer not found");
}

void CustomerRepository::anonymizeCustomer(Customer& customer) {
    if (!customer.authenticate(customer.getEmail(), customer.getPassword())) {
        throw invalid_argument("Customer not found");
    }
    for (int i = 0; i < customers_.size(); i++) {
        if (customers_[i].getId() == customer.getId()) {
            customers_[i].setName("Customer-" + customers_[i].getId());
            customers_[i].setlastName("Unknown");
            customers_[i].setEmail("");
            customers_[i].setPhoneNumber("");
            customers_[i].setAddress("");
            customers_[i].setRemarks("");
            customers_[i].setGdprDeleted(true);
            return;
        }
    }
    throw invalid_argument("Customer not found");
}

void CustomerRepository::setOrder( Customer &customer, const string car, Date date) {
    if (!customer.authenticate(customer.getEmail(), customer.getPassword())) {
        throw invalid_argument("Customer not found");
    }
    for (int i=0;i<customers_.size();i++)
    {
        if (customers_[i].getId()==customer.getId())
        {
            customers_[i].setOrderedCar(car);
            customers_[i].setOrderedDate(date);
            customers_[i].setHasOrderedCar(true);
        }
    }
    throw invalid_argument("Customer not found");
}

vector<Customer> CustomerRepository::getAll() {
    return customers_;
}

void CustomerRepository::startData() {
    //customers_.push_back(Customer("1","Bob","Popescu","bob1@yahoo.com","1234567892","Plopilor 1","", false,"hdeuy7e"));
    //customers_.push_back(Customer("2","Zob","Georgescu","zob@yahoo.com","2341567345","Moldoveanu 15","", false,"jdus8duc"));
    //customers_.push_back(Customer("3","Dob","Florescu","dob25@yahoo.com","5678345123","Ariesului 112","", false,"nduhdu8hcn"));
    //customers_.push_back(Customer("4","Cob","Grigorescu","ciob15@yahoo.com","4567123234","Bucium 20","", false,"jcidjc9djc"));
    //customers_.push_back(Customer("5","Ana","Vladescu","anavld@yahoo.com","2345123897","Cisnadiei 2","", false,"kidj8jdicj"));
    //customers_.push_back(Customer("6","Maria","Andrei","andreimaria5@yahoo.com","5678456098","Baciului 4","", false,"dciudhcdn"));
    //customers_.push_back(Customer("7","Mihai","George","mihaig@yahoo.com","4567345234","Negoi 12","", false,"diucnudh"));
    //customers_.push_back(Customer("8","Laura","Mihaelescu","lauram@yahoo.com","5678456345","Florilor 15","", false,"dncudh8"));
    //customers_.push_back(Customer("9","Andreea","Neamtu","neamtuandreea@yahoo.com","4567234123","Farului 1","", false,"nhr894"));
    //customers_.push_back(Customer("10","Bianca","Fader","biancafad@yahoo.com","6789467125","Gradinii 45","", false,"mjdifj8"));
    customers_.push_back(Customer("11","Bob","DOb","ceva@gmail.com","parola","075836788","Strada X","ceva remarks",false));


}

void CustomerRepository::modifyPassword(const Customer& customer) {

    for (int i = 0; i < customers_.size(); i++) {
        if (customers_[i].getId() == customer.getId()) {
            customers_[i].setPassword(customer.getPassword());
            return;
        }
    }
    throw std::invalid_argument("Customer not found");
}

void CustomerRepository::modifyRemark(const Customer& customer) {

    for (int i = 0; i < customers_.size(); i++) {
        if (customers_[i].getId() == customer.getId()) {
            customers_[i].setRemarks(customer.getRemarks());
            return;
        }
    }
    throw std::invalid_argument("Customer not found");
}