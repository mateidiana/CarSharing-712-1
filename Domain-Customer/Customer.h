//
// Created by Vanessa on 02.05.2024.
//

#ifndef CARSHARING_712_1_CUSTOMER_H
#define CARSHARING_712_1_CUSTOMER_H

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

struct Date {
    int day, month, year;
};

class Customer {
private:
    string id_;
    string name_;
    string lastName_;
    string email_;
    string phoneNumber_;
    string address_;
    string remarks_;
    string password_;
    bool gdprDeleted_;

    string orderedCar_;
    Date orderedDate_;
    bool hasOrderedCar_= false;

public:
    Customer(string id, string name, string lastName, string email, string password,
             string phoneNumber, string address, string remarks, bool gdprDeleted);

    string getId() const;
    string getName() const;
    string getlastName() const;
    string getEmail() const;
    string getPhoneNumber() const;
    string getAddress() const;
    string getRemarks() const;
    bool getGdprDeleted() const;
    bool hasOrderedCar() const;
    void setName(const string& name);
    void setlastName(const string& lastName);
    void setEmail(const string& email);
    void setPassword(const string& password);
    void setPhoneNumber(const string& phoneNumber);
    void setAddress(const string& address);
    void setRemarks(const string& remarks);
    void setGdprDeleted(bool gdprDeleted);


    string getOrderedCar() const;
    Date getOrderDate() const;
    bool getHasOrderedCar() const;
    void setOrderedCar(const string &orderedCar);
    void setOrderedDate(Date date);
    void setHasOrderedCar(bool hasOrderedCar);

private:
    void setId(const string& id);
};





#endif //CARSHARING_712_1_CUSTOMER_H
