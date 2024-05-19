//
// Created by Diana on 03-May-2024.
//

#include "CustomerController.h"
#include <stdexcept>
#include <utility>
#include <algorithm>
#include <cstring>

using namespace std;

CustomerController::CustomerController(CustomerRepository customerRepo) : customerRepo(std::move(customerRepo)) {}

void CustomerController::addCustomer(const std::string &id, const std::string &name, const std::string &lastName,
                                     const std::string &email, const std::string &password,
                                     const std::string &phoneNumber,
                                     const std::string &address, const std::string &remarks, bool gdprDeleted,
                                     bool isEmployee) {
    if (!gdprDeleted) {
        if (id == "" || name == "" || lastName == "" || phoneNumber == "" || email == "" || password == "" ||
            address == "") {
            throw runtime_error(
                    "The gdpr is false. Please complete all the requested fields (id, name, lastName, phoneNumber, email, password. address).");
        }
    } else {
        if (name == "" || lastName == "") {
            throw runtime_error("The name and the lastName are mandatory.");
        }
    }


    Customer addedCustomer(id, name, lastName, email, password, phoneNumber, address, remarks, gdprDeleted);
    customerRepo.createCustomer(addedCustomer, isEmployee);

}

void CustomerController::deleteCustomer(const std::string &deleteName, bool isEmployee) {
    vector<Customer> matchingCustomer = findByName(deleteName);
    if (!matchingCustomer.empty())
        for (const Customer &customer: matchingCustomer) {
            if (deleteName == customer.getName() || deleteName == customer.getlastName())
                customerRepo.deleteCustomer(customer, isEmployee);
        }

}

void CustomerController::setCustomerOrder(const std::string &name, const std::string &car, Date date, bool isEmployee) {
    vector<Customer> matchingCustomer = findByName(name);
    if (!matchingCustomer.empty())
        for (const Customer &customer: matchingCustomer) {
            if (customer.getName() == name || customer.getlastName() == name)
                customerRepo.setOrder(customer, car, date, isEmployee);
        }
}

vector<Customer> CustomerController::getAll() {
    vector<Customer> allCustomers;
    allCustomers = customerRepo.getAll();
    sort(allCustomers.begin(), allCustomers.end(),
         [](const Customer &customer1, const Customer &customer2) {
             return customer1.getlastName() < customer2.getlastName();
         });
    return allCustomers;
}

vector<Customer> CustomerController::findByEmail(std::string &email) {
    vector<Customer> foundCustomers;
    for (const Customer &customer: customerRepo.getAll()) {

        if (customer.getEmail() == email)
            foundCustomers.push_back(customer);
    }
    return foundCustomers;
}

vector<Customer> CustomerController::findByPhone(std::string &phoneNumber) {
    vector<Customer> foundCustomers;
    for (const Customer &customer: customerRepo.getAll()) {

        if (customer.getPhoneNumber() == phoneNumber)
            foundCustomers.push_back(customer);
    }
    return foundCustomers;
}

vector<Customer> CustomerController::findByName(const std::string &name) {
    vector<Customer> foundCustomers;
    for (const Customer &customer: customerRepo.getAll()) {

        if (customer.getName() == name || customer.getlastName() == name)
            foundCustomers.push_back(customer);
    }
    return foundCustomers;
}

bool CustomerController::compareCarOrderDate(const Customer &customer1, const Customer &customer2) {
    if (customer1.getOrderDate().year != customer2.getOrderDate().year)
        return customer1.getOrderDate().year < customer2.getOrderDate().year;

    if (customer1.getOrderDate().month != customer2.getOrderDate().month)
        return customer1.getOrderDate().month < customer2.getOrderDate().month;

    return customer1.getOrderDate().day < customer2.getOrderDate().day;
}

vector<Customer> CustomerController::findByOrderedCar(std::string &orderedCar) {
    vector<Customer> foundCustomers;
    for (const Customer &customer: customerRepo.getAll()) {

        if (customer.getHasOrderedCar() && customer.getOrderedCar() == orderedCar)
            foundCustomers.push_back(customer);
    }

    sort(foundCustomers.begin(), foundCustomers.end(), compareCarOrderDate);
    return foundCustomers;
}


void
CustomerController::changePassword(std::string &email, const std::string &newpassword, bool isEmployee, bool isAdmin) {
    //find customers by email
    vector<Customer> customers = this->findByEmail(email);

    //check if any customers with the given email were found
    if (customers.empty()) {
        throw runtime_error("Customer not found");
    }

    if (isEmployee || isAdmin) {
        throw runtime_error("Unauthorized access");
    }

    //if there is only one customer with the given email, change its password
    if (customers.size() == 1) {
        Customer &customerToUpdate = customers[0];
        customerToUpdate.setPassword(newpassword);
        customerRepo.modifyCustomer(customerToUpdate, isEmployee);
        return;


    }

}

void
CustomerController::changeRemarks(std::string &email, const std::string &newRemarks, bool isEmployee, bool isAdmin) {
    // Find customers by email
    vector<Customer> customers = this->findByEmail(email);

    // Check if any customers with the given email were found
    if (customers.empty()) {
        throw runtime_error("Customer not found");
    }


    if (isEmployee || isAdmin) {
        throw runtime_error("Unauthorized access");
    }


    // If there's only one customer with the email, update its remarks directly
    if (customers.size() == 1) {
        Customer &customerToUpdate = customers[0];
        customerToUpdate.setRemarks(newRemarks);
        // Update the customer in the repository
        customerRepo.modifyCustomer(customerToUpdate, isEmployee);
        return;
    }
}

//Georgiana

bool CustomerController::isEmailTaken(const string &email) {
    for (const Customer &customer: customerRepo.getAll()) {
        if (customer.getEmail() == email)
            return false;
    }
    return true;
}

bool CustomerController::isPhoneNumberValid(const string &phoneNumber) {
    bool hasPlusAtStart = false;

    if (!phoneNumber.empty() && phoneNumber[0] == '+') {
        hasPlusAtStart = true;
    }

    for (char c: phoneNumber) {
        if (!isdigit(c) && c != ' ') {
            return false;
        }
    }

    return (hasPlusAtStart && phoneNumber.length() > 1) || !hasPlusAtStart;
}


bool CustomerController::isEmailFormatValid(const string &email) {
    bool hasAtSymbol = false;
    bool hasDot = false;

    for (char c: email) {
        if (c == '@') {
            hasAtSymbol = true;
        } else if (c == '.') {
            hasDot = true;
        }
    }

    return hasAtSymbol && hasDot;
}
