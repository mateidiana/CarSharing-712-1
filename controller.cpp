#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "domain.cpp"
using namespace std;

class EmployeeController {
private:
    std::vector<Employee> employees;
public:
    void addEmployee(const Employee& employee) {
        auto it = std::find_if(employees.begin(), employees.end(), [&](const Employee& e) {
            return e.getName() == employee.getName() && e.getLastName() == employee.getLastName();
        });
        if(it != employees.end()) {
            employees.push_back(employee);
        }
    }

    void deleteEmployee(const std::string &firstName, const std::string &lastName) {
        auto it = std::remove_if(employees.begin(), employees.end(), [&](const Employee &e) {
            return e.getName() == firstName && e.getLastName() == lastName;
        });
        employees.erase(it, employees.end());
    }

    void sortByFirstName() {
        std::sort(employees.begin(), employees.end(), [](const Employee& e1, const Employee& e2) {
            return e1.getName() < e2.getName();
        });
    }

    void sortByLastName() {
        std::sort(employees.begin(), employees.end(), [](const Employee& e1, const Employee& e2) {
            return e1.getLastName() < e2.getLastName();
        });
    }

    std::vector<Employee> getAll() const {
        return employees;
    }
};
