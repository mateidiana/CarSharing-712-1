#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "repository.cpp"
using namespace std;

class EmployeeController {
private:
    std::vector<Employee> employees;
public:
    void addEmployee(const Employee &employee) {
        auto it = std::find_if(employees.begin(), employees.end(), [&](const Employee &e) {
            return e.get_firstName() == employee.get_firstName() && e.get_lastName() == employee.get_lastName();
        });
        if (it != employees.end()) {
            employees.push_back(employee);
        }
    }

    void deleteEmployee(const std::string &firstName, const std::string &lastName) {
        auto it = std::remove_if(employees.begin(), employees.end(), [&](const Employee &e) {
            return e.get_firstName() == firstName && e.get_lastName() == lastName;
        });
        employees.erase(it, employees.end());
    }

    void sortByFirstName() {
        std::sort(employees.begin(), employees.end(), [](const Employee& e1, const Employee& e2) {
            return e1.get_firstName() < e2.get_firstName();
        });
    }

    void sortByLastName() {
        std::sort(employees.begin(), employees.end(), [](const Employee& e1, const Employee& e2) {
            return e1.get_lastName() < e2.get_lastName();
        });
    }

    std::vector<Employee> get_employees() const {
        return employees;
    }
};