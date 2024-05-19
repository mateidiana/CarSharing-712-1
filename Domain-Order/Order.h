//
// Created by Gia Maier on 19.05.2024.
//

#ifndef CARSHARING_712_1_ORDER_H
#define CARSHARING_712_1_ORDER_H

#include <iostream>
#include "string";
#include "../Domain-Customer/Customer.h"
#include "../Domain-Employee/Employee.h"

using namespace std;


enum class Status {
    Reservation,
    Order,
    Completed
};

class Order {
private:
    string orderNumber;
    Date orderDate;
    Status status;
    string orderedCar;
    Date begin;
    Date end;
    Customer customer;
    Employee employee;
    int totalSum;
    string remarks;


public:
    Order(const string &orderNumber, const Date &orderDate, Status status, const string &orderedCar,
          const Date &begin, const Date &end, const Customer &customer, const Employee &employee,
          int totalSum, const string &remarks)
            : orderNumber(orderNumber), orderDate(orderDate), status(status), orderedCar(orderedCar),
              begin(begin), end(end), customer(customer), employee(employee), totalSum(totalSum), remarks(remarks) {}

    string getOrderNumber() const { return orderNumber; }

    void setOrderNumber(const string &orderNumber) { this->orderNumber = orderNumber; }

    Date getOrderDate() const { return orderDate; }

    void setOrderDate(const Date &orderDate) { this->orderDate = orderDate; }

    Status getStatus() const { return status; }

    void setStatus(Status status) { this->status = status; }

    string getOrderedCar() const { return orderedCar; }

    void setOrderedCar(const string &orderedCar) { this->orderedCar = orderedCar; }

    Date getBegin() const { return begin; }

    void setBegin(const Date &begin) { this->begin = begin; }

    Date getEnd() const { return end; }

    void setEnd(const Date &end) { this->end = end; }

    Customer getCustomer() const { return customer; }

    void setCustomer(const Customer &customer) { this->customer = customer; }

    Employee getEmployee() const { return employee; }

    void setEmployee(const Employee &employee) { this->employee = employee; }

    int getTotalSum() const { return totalSum; }

    void setTotalSum(int totalSum) { this->totalSum = totalSum; }

    string getRemarks() const { return remarks; }

    void setRemarks(const string &remarks) { this->remarks = remarks; }

    static string statusToString(Status stat) {
        switch (stat) {
            case Status::Reservation:
                return "Reservation";
            case Status::Order:
                return "Order";
            case Status::Completed:
                return "Completed";
            default:
                return "Unknown";
        }
    }

    void printDetails() const {
        cout << "Number of the order: " << orderNumber << endl;
        cout << "Date of the order: " << orderDate.day << "." << orderDate.month << "." << orderDate.year << endl;
        cout << "Status: " << statusToString(status) << endl;
        cout << "Car: " << orderedCar << endl;
        cout << "Start-date: " << begin.day << "." << begin.month << "." << begin.year << endl;
        cout << "End-date: " << end.day << "." << end.month << "." << end.year << endl;
        cout << "Customer: " << customer.getName() << endl;
        cout << "Employee: " << employee.getName() << endl;
        cout << "Total Cost: " << totalSum << endl;
        cout << "Remarks: " << remarks << endl;
    }
};




#endif //CARSHARING_712_1_ORDER_H
