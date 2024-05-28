//
// Created by Diana on 03-May-2024.
//

#ifndef CARSHARING_712_1_CUSTOMERCONTROLLER_H
#define CARSHARING_712_1_CUSTOMERCONTROLLER_H

#include "../Repository-Customers/CustomerRepository.h"
#include "../Domain-User/User.h"

class CustomerController {

private:

    CustomerRepository customerRepo;

public:

    CustomerController(CustomerRepository customerRepo);

   void addCustomer(const std::string &id, const std::string &name, const std::string &lastName,
                    const std::string &email, const std::string &password,
                    const std::string &phoneNumber,
                    const std::string &address, const std::string &remarks, bool gdprDeleted,
                    bool isEmployee);

    void deleteCustomer(const string &deleteName, bool isEmployee);

    void setCustomerOrder(const string &name, const string &car, Date date, bool isEmployee);

    void changePassword(string &email, const std::string &newpassword, const std::string &password);

    void changeRemarks(string &email, const std::string &newRemarks, const std::string &password);



    vector<Customer> getAll();

    Customer findByEmail(string &email);

    vector<Customer> findByPhone(string &phoneNumber);

    vector<Customer> findByName(const string &name);

    vector<Customer> findByOrderedCar(string &orderedCar);

    static bool compareCarOrderDate(const Customer &customer1, const Customer &customer2);

    bool isEmailTaken(const string& email);

    bool isEmailFormaValid(const string& email);

    bool isPhoneNumberValid(const string& phoneNumber);

   void addToFavourites(std::string &email, const Car &car, const std::string &password);
};


#endif //CARSHARING_712_1_CUSTOMERCONTROLLER_H
