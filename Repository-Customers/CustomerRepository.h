//
// Created by Vanessa on 02.05.2024.
//

#ifndef CARSHARING_712_1_CUSTOMERREPOSITORY_H
#define CARSHARING_712_1_CUSTOMERREPOSITORY_H

#include <vector>
#include <stdexcept>
#include "../Domain-Customer/Customer.h"
#include "../Repository-Employee/EmployeeRepository.h"

using namespace std;

class CustomerRepository {
private:
    vector<Customer> customers_;

    void startData();

public:
    CustomerRepository(const std::vector<Customer>);
    void createCustomer(const Customer& customer);
    void modifyCustomer(Customer& customer);
    void deleteCustomer(Customer& customer);
    void anonymizeCustomer( Customer& customer);
    void modifyRemark(const Customer& customer);
    void modifyPassword(const Customer& customer);
    void setOrder(Customer& customer, const string car, Date date);
    vector<Customer> getAll();



};


#endif //CARSHARING_712_1_CUSTOMERREPOSITORY_H
