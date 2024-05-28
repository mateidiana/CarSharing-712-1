#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    std::string firstName;
    std::string lastName;
    std::string emailAddress;
    std::string occupation;
    std::string car;
    std::string model;
public:
    Employee(std::string firstName, std::string lastName, std::string emailAddress, std::string occupation, std::string car, std::string model):
    firstName(firstName), lastName(lastName), emailAddress(emailAddress), occupation(occupation), car(car), model(model) {}

    std::string get_firstName() const {
        return firstName;
    }

    void set_firstName(const string& firstName) {
        this -> firstName = firstName;
    }

    std::string get_lastName() const {
        return lastName;
    }

    void set_lastName(const string& lastName) {
        this -> lastName = lastName;
    }

    std::string get_emailAddress() const {
        return emailAddress;
    }

    void set_emailAddress(const string& emailAddress) {
        this -> emailAddress = emailAddress;
    }

    std::string get_occupation() const {
        return occupation;
    }

    void set_occupation(const string& occupation) {
        this -> occupation = occupation;
    }

    std::string get_car() const {
        return car;
    }

    void set_car(const string& car) {
        this -> car = car;
    }

    std::string get_model() const {
        return model;
    }

    void set_model(const string& model) {
        this -> model = model;
    }
};