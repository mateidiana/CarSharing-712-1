//
// Created by zaxx4 on 27.05.2024.
//
#include "../Repository-Employee/EmployeeRepository.h"
#include "../Domain-Employee/Employee.h"
#include "../Domain-Admin/Admin.h"
#include "gtest/gtest.h"


//Kogalniceanu Ana
class EmployeeRepositoryTest : public ::testing::Test {
protected:
    EmployeeRepository repoE;
    Employee employee1;
    Employee employee2;
    Admin admin1;
    vector<Employee> employees = {employee1, employee2};
    vector<Admin> admins={admin1};
    EmployeeRepositoryTest():
            repoE(employees,admins),
            employee1("emp1@example.com", "password1", "John", "Doe", "Developer", "JD", "1234567890", "123 Main St", "Remarks", 50000, "1990-01-01"),
            employee2("emp2@example.com", "password2", "Jane", "Smith", "Designer", "JS", "0987654321", "456 Elm St", "More Remarks", 60000, "1992-02-02"),
            admin1("admin1@example.com", "adminpass", "Alice", "Brown", "Manager", "AB", "1122334455", "789 Oak St", "Admin Remarks", 80000, "1988-03-03", &repoE) {
    }

    void SetUp() override {

        repoE.addEmployee(employee1);
        repoE.addEmployee(employee2);
        repoE.addAdmin(admin1);
    }
};


TEST_F(EmployeeRepositoryTest, AddEmployee_Success) {
Employee newEmployee("newemp@example.com", "newpassword", "New", "Employee", "Tester", "NE", "1112223333", "999 Pine St", "New Remarks", 55000, "1993-04-04");

ASSERT_NO_THROW(repoE.addEmployee(newEmployee));
ASSERT_EQ(repoE.getAllEmployees().size(), 3);
}

TEST_F(EmployeeRepositoryTest, RemoveEmployee_Success) {
ASSERT_NO_THROW(repoE.removeEmployee(employee1.getEmail()));
ASSERT_EQ(repoE.getAllEmployees().size(), 1);
ASSERT_EQ(repoE.searchEmployeeByEmail(employee1.getEmail()), nullptr);
}

TEST_F(EmployeeRepositoryTest, AddAdmin_Success) {
Admin newAdmin("newadmin@example.com", "adminpass", "New", "Admin", "CTO", "NA", "9998887777", "321 Birch St", "Admin Remarks", 90000, "1985-05-05", &repoE);

ASSERT_NO_THROW(repoE.addAdmin(newAdmin));
ASSERT_EQ(repoE.searchEmployeeByEmail(newAdmin.getEmail()), nullptr);
}

TEST_F(EmployeeRepositoryTest, RemoveAdmin_Success) {
ASSERT_NO_THROW(repoE.removeAdmin(admin1.getEmail()));
ASSERT_EQ(repoE.searchEmployeeByEmail(admin1.getEmail()), nullptr);
}

//Matei Dana

TEST_F(EmployeeRepositoryTest, AdjustSalary_Success) {
double newSalary = 70000;
repoE.adjustSalary(employee1, newSalary);
ASSERT_EQ(employee1.getSalary(), newSalary);
}

TEST_F(EmployeeRepositoryTest, ViewSalary_Success) {
testing::internal::CaptureStdout();
repoE.viewSalary(employee1);
std::string output = testing::internal::GetCapturedStdout();
ASSERT_EQ(output, "Salary of John: $50000\n");
}

TEST_F(EmployeeRepositoryTest, ResetPassword_Success) {
std::string newPassword = "newpassword123";
repoE.resetPassword(employee1, newPassword);
ASSERT_EQ(employee1.getPassword(), newPassword);
}

TEST_F(EmployeeRepositoryTest, SearchEmployeeByEmail_Success) {
Employee* foundEmployee = repoE.searchEmployeeByEmail(employee2.getEmail());
ASSERT_NE(foundEmployee, nullptr);
ASSERT_EQ(foundEmployee->getEmail(), employee2.getEmail());
}

TEST_F(EmployeeRepositoryTest, SearchEmployeeByAbbreviation_Success) {
Employee* foundEmployee = repoE.searchEmployeeByAbbreviation(employee2.getAbbreviation());
ASSERT_NE(foundEmployee, nullptr);
ASSERT_EQ(foundEmployee->getAbbreviation(), employee2.getAbbreviation());
}

TEST_F(EmployeeRepositoryTest, GetAllEmployees_Success) {
std::vector<Employee> employees = repoE.getAllEmployees();
ASSERT_EQ(employees.size(), 2);
ASSERT_EQ(employees[0].getName(), "Jane");
ASSERT_EQ(employees[1].getName(), "John");
}

TEST_F(EmployeeRepositoryTest, SearchEmployeesByNameAndLastName_Success) {
std::vector<Employee> foundEmployees = repoE.searchEmployeesByNameAndLastName("John", "Doe");
ASSERT_EQ(foundEmployees.size(), 1);
ASSERT_EQ(foundEmployees[0].getEmail(), employee1.getEmail());
}

TEST_F(EmployeeRepositoryTest, SearchEmployeesByBirthDateRange_Success) {
std::vector<Employee> foundEmployees = repoE.searchEmployeesByBirthDateRange("1989-01-01", "1991-01-01");
ASSERT_EQ(foundEmployees.size(), 1);
ASSERT_EQ(foundEmployees[0].getEmail(), employee1.getEmail());
}

TEST_F(EmployeeRepositoryTest, AssignAdminRights_Success) {
repoE.assignAdminRights(employee1);
ASSERT_EQ(repoE.searchEmployeeByEmail(employee1.getEmail()), nullptr);
}

TEST_F(EmployeeRepositoryTest, RemoveAdminRights_Success) {
repoE.removeAdminRights(admin1);
ASSERT_EQ(repoE.searchEmployeeByEmail(admin1.getEmail()), nullptr);
ASSERT_NE(repoE.searchEmployeeByEmail(admin1.getEmail()), nullptr);
}

