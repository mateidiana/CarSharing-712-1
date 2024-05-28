#include <iostream>
#include <string>
#include <vector>
#include "controller.cpp"
#include <algorithm>
using namespace std;

class EmployeeRepository {
private:
    EmployeeController controller;
public:
    void addEmployee(const Employee &employee) {
        controller.addEmployee(employee);
    }

    void deleteEmployee(const std::string &firstName, const std::string &lastName) {
        controller.deleteEmployee(firstName, lastName);
    }

    void sortByFirstName() {
        controller.sortByFirstName();
    }

    void sortByLastName() {
        controller.sortByLastName();
    }

    std::vector<Employee> get_employees() const {
        return controller.get_employees();
    }
};