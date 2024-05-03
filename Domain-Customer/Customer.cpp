//
// Created by Vanessa on 02.05.2024.
//

#include "Customer.h"

Customer::Customer(string id, string name, string lastName, string email,
                   string phoneNumber,string address,string remarks, bool gdprDeleted)
        : id_(id), name_(name), lastName_(lastName), email_(email), phoneNumber_(phoneNumber),
          address_(address), remarks_(remarks), gdprDeleted_(gdprDeleted) {}

string Customer::getId() const {
    return id_;
}

string Customer::getName() const {
    return name_;
}

string Customer::getlastName() const {
    return lastName_;
}

string Customer::getEmail() const {
    return email_;
}

string Customer::getPhoneNumber() const {
    return phoneNumber_;
}

string Customer::getAddress() const {
    return address_;
}

string Customer::getRemarks() const {
    return remarks_;
}

bool Customer::getGdprDeleted() const {
    return gdprDeleted_;
}

bool Customer::hasOrderedCar() const {
    // aici mai trebuie completat
    return false;
}

void Customer::setName(const string& name) {
    name_ = name;
}

void Customer::setlastName(const string& lastName) {
    lastName_ = lastName;
}

void Customer::setEmail(const string& email) {
    email_ = email;
}

void Customer::setPhoneNumber(const string& phoneNumber) {
    phoneNumber_ = phoneNumber;
}

void Customer::setAddress(const string& address) {
    address_ = address;
}

void Customer::setRemarks(const string& remarks) {
    remarks_ = remarks;
}

void Customer::setGdprDeleted(bool gdprDeleted) {
    gdprDeleted_ = gdprDeleted;
}

void Customer::setId(const string& id) {
    id_ = id;
}