//
// Created by Vanessa on 02.05.2024.
//

#include "Customer.h"




string Customer::getId() const {
    return id_;
}

string Customer::getName() const {
    return name_;
}

string Customer::getlastName() const {
    return lastName_;
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



void Customer::setName(const string& name) {
    name_ = name;
}

void Customer::setlastName(const string& lastName) {
    lastName_ = lastName;
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


void Customer::setId(const string& id) {
    id_ = id;
}

void Customer::setGdprDeleted(bool gdprDeleted) {
    gdprDeleted_ = gdprDeleted;
}

string Customer::getOrderedCar() const {
    return orderedCar_;
}

Date Customer::getOrderDate() const {
    return orderedDate_;
}

bool Customer::getHasOrderedCar() const {
    return hasOrderedCar_;
}

void Customer::setOrderedCar(const string &orderedCar) {
    orderedCar_=orderedCar;
}

void Customer::setOrderedDate(Date date) {
    orderedDate_=date;
}

void Customer::setHasOrderedCar(bool hasOrderedCar) {
    hasOrderedCar_=hasOrderedCar;
}

void Customer::setLoginStatus(const bool &loggedin) {
    loggedin_=loggedin;
}
bool Customer::getLoginStatus() const{
    return loggedin_;
}
void Customer::addToFavourites(const Car car) {
    favourites_.push_back(car);
}
vector<Car> Customer::seeFavourites() const{
    return favourites_;
};