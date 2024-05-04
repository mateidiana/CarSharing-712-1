//
// Created by zaxx4 on 03.05.2024.
//

#include "Employee.h"

Employee::Employee(string name, string lastName, string email, string position, string abbreviation,
                   string phoneNumber, string address, string remarks, double salary, string password): name_(name),
                   lastName_(lastName), email_(email), position_(position), abbreviation_(abbreviation),
                   phoneNumber_(phoneNumber), address_(address), remarks_(remarks), salary_(salary), password_(password) {

}

const string &Employee::getName() const {
    return name_;
}

void Employee::setName(const string &name) {
    name_ = name;
}

const string &Employee::getEmail() const {
    return email_;
}

void Employee::setEmail(const string &email) {
    email_ = email;
}

const string &Employee::getLastName() const {
    return lastName_;
}

void Employee::setLastName(const string &lastName) {
    lastName_ = lastName;
}

const string &Employee::getPosition() const {
    return position_;
}

void Employee::setPosition(const string &position) {
    position_ = position;
}

const string &Employee::getAbbreviation() const {
    return abbreviation_;
}

void Employee::setAbbreviation(const string &abbreviation) {
    abbreviation_ = abbreviation;
}

const string &Employee::getPhoneNumber() const {
    return phoneNumber_;
}

void Employee::setPhoneNumber(const string &phoneNumber) {
    phoneNumber_ = phoneNumber;
}

const string &Employee::getAddress() const {
    return address_;
}

void Employee::setAddress(const string &address) {
    address_ = address;
}

const string &Employee::getRemarks() const {
    return remarks_;
}

void Employee::setRemarks(const string &remarks) {
    remarks_ = remarks;
}

double Employee::getSalary() const {
    return salary_;
}

void Employee::setSalary(double salary) {
    salary_ = salary;
}

const string &Employee::getPassword() const {
    return password_;
}

void Employee::setPassword(const string &password) {
    password_ = password;
}


