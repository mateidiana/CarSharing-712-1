
#ifndef CARSHARING_712_1_EMPLOYEEUI_H
#define CARSHARING_712_1_EMPLOYEEUI_H
#include "../Controller/EmployeeController.h"
#include "../Domain-Employee/Employee.h"
#include "../Repository-Employee/EmployeeRepository.h"
#include <iostream>
#include <functional>


class EmployeeUI {
private:
    EmployeeController& controller_;

    void printEmployees(const vector<Employee>& employees) const;

public:
    EmployeeUI(EmployeeController& controller) : controller_(controller) {}

    void listAllEmployees() const;
    void searchEmployeeByNameAndLastName() const;
    void searchEmployeeByBirthDateRange() const;
};

#endif //CARSHARING_712_1_EMPLOYEEUI_H
