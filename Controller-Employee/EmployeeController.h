//
// Created by Dell on 5/20/2024.
//

#ifndef CARSHARING_712_1_EMPLOYEECONTROLLER_H
#define CARSHARING_712_1_EMPLOYEECONTROLLER_H

#include "../Repository-Employee/EmployeeRepository.h"
#include "../Domain-Employee/Employee.h"

class EmployeeController{

private:
    EmployeeRepository repository_;

public:

    EmployeeController(EmployeeRepository &repository);

//M5
    //bool changePassword(int employeeId, const std::string &newPassword);
    bool updateRemarks(int employeeId, const std::string &newRemarks);
    bool login(const std::string &username, const std::string &password)


    void adjustSalary(Employee &employee, double newSalary) {
        repository_.adjustSalary(employee, newSalary);
    }

    void addAdmin(Admin &admin) {
        repository_.addAdmin(admin);
    }

    void removeAdmin(const std::string &email) {
        repository_.removeAdmin(email);
    }

    void addEmployee(Employee &employee) {
        repository_.addEmployee(employee);
    }

    void removeEmployee(const std::string &email) {
        repository_.removeEmployee(email);
    }

    void removeAdminRights(Admin &admin) {
        repository_.removeAdminRights(admin);
    }

    void assignAdminRights(Employee &employee) {
        repository_.assignAdminRights(employee);
    }

    void viewSalary(Employee &employee) {
        repository_.viewSalary(employee);
    }

    //m5
    void resetPassword(Employee &employeeId, std::string newPassword) {
        repository_.resetPassword(employeeId, newPassword);
    }



    Employee* searchEmployeeByAbbreviation(const std::string &abbreviation) {
        return repository_.searchEmployeeByAbbreviation(abbreviation);
    }

    Employee* searchEmployeeByEmail(const std::string &email) {
        return repository_.searchEmployeeByEmail(email);
    }

    void startData() {
        repository_.startData();
    }

    void setupUnitTests() {
        repository_.setupUnitTests();
    }

};

#endif //CARSHARING_712_1_EMPLOYEECONTROLLER_H
