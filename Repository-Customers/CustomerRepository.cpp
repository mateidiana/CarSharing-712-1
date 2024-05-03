//
// Created by Vanessa on 02.05.2024.
//

#include "CustomerRepository.h"

CustomerRepository::CustomerRepository() {
    startData();
}

void CustomerRepository::createCustomer(const Customer& customer, bool isEmployee) {
    if (!isEmployee) {
        throw invalid_argument("Only employees are allowed to create customers.");
    }
    customers_.push_back(customer);
}

void CustomerRepository::modifyCustomer(const Customer& customer, bool isEmployee) {
    if (!isEmployee) {
        throw invalid_argument("Only employees are allowed to modify customers.");
    }
    for (int i = 0; i < customers_.size(); i++) {
        if (customers_[i].getName() == customer.getName()) {
            customers_[i] = customer;
            return;
        }
    }
    throw invalid_argument("Customer not found");
}

void CustomerRepository::deleteCustomer(const Customer& customer, bool isEmployee) {
    if (!isEmployee) {
        throw invalid_argument("Only employees are allowed to delete customers.");
    }
    for (int i = 0; i < customers_.size(); i++) {
        if (customers_[i].getName() == customer.getName()) {
            customers_.erase(customers_.begin() + i);
            return;
        }
    }
    throw invalid_argument("Customer not found");
}

void CustomerRepository::anonymizeCustomer(const Customer& customer, bool isEmployee) {
    if (!isEmployee) {
        throw invalid_argument("Only employees are allowed to anonymize customers.");
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

vector<Customer> CustomerRepository::getAll() {
    return customers_;
}

void CustomerRepository::startData() {
    customers_.push_back(Customer("1","Popescu","Bob","bob1@yahoo.com","1234567892","Plopilor 1","", false));
    customers_.push_back(Customer("2","Georgescu","Zob","zob@yahoo.com","2341567345","Moldoveanu 15","", false));
    customers_.push_back(Customer("3","Florescu","Dob","dob25@yahoo.com","5678345123","Ariesului 112","", false));
    customers_.push_back(Customer("4","Grigorescu","Cob","ciob15@yahoo.com","4567123234","Bucium 20","", false));
    customers_.push_back(Customer("5","Vladescu","Ana","anavld@yahoo.com","2345123897","Cisnadiei 2","", false));
    customers_.push_back(Customer("6","Andrei","Maria","andreimaria5@yahoo.com","5678456098","Baciului 4","", false));
    customers_.push_back(Customer("7","George","Mihai","mihaig@yahoo.com","4567345234","Negoi 12","", false));
    customers_.push_back(Customer("8","Mihaelescu","Laura","lauram@yahoo.com","5678456345","Florilor 15","", false));
    customers_.push_back(Customer("9","Neamtu","Andreea","neamtuandreea@yahoo.com","4567234123","Farului 1","", false));
    customers_.push_back(Customer("10","Fader","Bianca","biancafad@yahoo.com","6789467125","Gradinii 45","", false));
}