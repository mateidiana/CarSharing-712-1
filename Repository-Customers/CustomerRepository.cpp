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

void CustomerRepository::setOrder(const Customer &customer, const string car, Date date, bool isEmployee) {
    if (!isEmployee) {
        throw invalid_argument("Only employees are allowed to set orders.");
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
    customers_.push_back(Customer("1","Bob","Popescu","bob1@yahoo.com","1234","1234567892","Plopilor 1","", false));
    customers_.push_back(Customer("2","Zob","Georgescu","zob@yahoo.com","abcd","2341567345","Moldoveanu 15","", false));
    customers_.push_back(Customer("3","Dob","Florescu","dob25@yahoo.com","qwert","5678345123","Ariesului 112","", false));
    customers_.push_back(Customer("4","Cob","Grigorescu","ciob15@yahoo.com","asdf","4567123234","Bucium 20","", false));
    customers_.push_back(Customer("5","Ana","Vladescu","anavld@yahoo.com","tyuio","2345123897","Cisnadiei 2","", false));
    customers_.push_back(Customer("6","Maria","Andrei","andreimaria5@yahoo.com","qawsed","5678456098","Baciului 4","", false));
    customers_.push_back(Customer("7","Mihai","George","mihaig@yahoo.com","12345","4567345234","Negoi 12","", false));
    customers_.push_back(Customer("8","Laura","Mihaelescu","lauram@yahoo.com","1a2s3d","5678456345","Florilor 15","", false));
    customers_.push_back(Customer("9","Andreea","Neamtu","neamtuandreea@yahoo.com","4f5g6h","4567234123","Farului 1","", false));
    customers_.push_back(Customer("10","Bianca","Fader","biancafad@yahoo.com","r4t5y6","6789467125","Gradinii 45","", false));
}