//
// Created by zaxx4 on 03.05.2024.
//

#include "Employee.h"

void Employee::validate() const {
    if (getEmail().empty()) throw std::invalid_argument("Email is required");
    if (getName().empty()) throw std::invalid_argument("Name is required");
    if (getLastName().empty()) throw std::invalid_argument("Last name is required");
    if (getAbbreviation().empty()) throw std::invalid_argument("Abbreviation is required");
    if (getPhoneNumber().empty()) throw std::invalid_argument("Phone number is required");
    if (getAddress().empty()) throw std::invalid_argument("Address is required");
    if (getBirthDate().empty()) throw std::invalid_argument("Birth date is required");
    if (getSalary() < 100) throw std::invalid_argument("Salary must be at least 100 EUR");
    int age = calculateAge("2024-05-28"); // Use the current date
    if (age < 0 || age > 80) throw std::invalid_argument("Age must be between 0 and 80");
}


const string &Employee::getRemarks() const {
    return remarks_;
}

void Employee::setRemarks(const string &remarks) {
    remarks_ = remarks;
}

const string &Employee::getAddress() const {
    return address_;
}

void Employee::setAddress(const string &address) {
    address_ = address;
}

const string &Employee::getPhoneNumber() const {
    return phoneNumber_;
}

void Employee::setPhoneNumber(const string &phoneNumber) {
    phoneNumber_ = phoneNumber;
}

const string &Employee::getAbbreviation() const {
    return abbreviation_;
}

void Employee::setAbbreviation(const string &abbreviation) {
    abbreviation_ = abbreviation;
}

const string &Employee::getPosition() const {
    return position_;
}

void Employee::setPosition(const string &position) {
    position_ = position;
}

void Employee::setName(const string &name) {
    name_ = name;
}

const string &Employee::getName() const {
    return name_;
}

const string &Employee::getLastName() const {
    return lastName_;
}

void Employee::setLastName(const string &lastName) {
    lastName_ = lastName;
}

double Employee::getSalary() const {
    return salary_;
}

void Employee::setSalary(double salary) {
    salary_ = salary;
}

const string &Employee::getBirthDate() const {
    return birthDate_;
}

void Employee::setBirthDate(const string &birthDate) {
    birthDate_ = birthDate;
}

//Helper function to parse date string
void Employee::parseDate(const string &date, int &year, int &month, int &day) const {
    if (sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3) {
        throw invalid_argument("Invalid date format");
    }
}

//Add age validation method
int Employee::calculateAge(const string &currentDate) const {
    int birthYear, birthMonth, birthDay;
    parseDate(birthDate_, birthYear, birthMonth, birthDay);

    int currentYear, currentMonth, currentDay;
    parseDate(currentDate, currentYear, currentMonth, currentDay);

    int age = currentYear - birthYear;
    if (currentMonth < birthMonth || (currentMonth == birthMonth && currentDay < birthDay)) {
        age--;
    }
    return age;
}

void Employee::placeOrder(Order& order) {
    // Logic for placing an order
    order.placeOrder(*this); // Pass the current employee to placeOrder method of the order
}

void Employee::deleteReservation(Order& order) {
    if (order.canDeleteReservation(*this)) {
        order.deleteReservation();
    } else {
        cout << "Error: Only reservations can be deleted." << endl;
    }
}