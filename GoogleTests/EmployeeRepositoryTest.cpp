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

// Matei Dana-Maria

TEST(EmployeeTest, CreateEmployee) {
// testul verifica daca  un obiect 'employee' este creeat corect cu atributele corespunzatoare
Employee employee("john.doe@example.com", "password123", "John", "Doe", "Manager", "JD", "077125639", "123 Main St", "No remarks", 50000);
// verificam daca valoarea asteptata (primul argument) este aceeasi cu valoarea obtinuta (al doilea argument)
ASSERT_EQ(employee.getEmail(), "john.doe@example.com");
ASSERT_EQ(employee.getPassword(), "password123");
ASSERT_EQ(employee.getName(), "John");
ASSERT_EQ(employee.getLastName(), "Doe");
ASSERT_EQ(employee.getPosition(), "Manager");
ASSERT_EQ(employee.getAbbreviation(), "JD");
ASSERT_EQ(employee.getPhoneNumber(), "555-0101");
ASSERT_EQ(employee.getAddress(), "123 Main St");
ASSERT_EQ(employee.getRemarks(), "No remarks");
ASSERT_EQ(employee.getSalary(), 50000);
}

TEST(EmployeeRepositoryTest, AddAndSearchEmployee) {
// testul verifica adaugarea unui angajat in repository si cautarea lui dupa email si abreviere
EmployeeRepository repo;
Employee employee("john.doe@example.com", "password123", "John", "Doe", "Manager", "JD", "555-0101", "123 Main St", "No remarks", 50000);
// adaugam angajatul in repository
repo.addEmployee(employee);
// cautam angajatul dupa email
Employee* foundEmployee = repo.searchEmployeeByEmail("john.doe@example.com");
// verific daca anjajatul a fost gasit (pointerul nu este null)
ASSERT_NE(foundEmployee, nullptr);
// verific daca numele angajatului gasit este John
EXPECT_EQ(foundEmployee->getName(), "John");
// caut angajatul dupa abreviere
foundEmployee = repo.searchEmployeeByAbbreviation("JD");
// verific daca anjajatul a fost gasit (pointerul nu este null)
ASSERT_NE(foundEmployee, nullptr);
// verific daca mail-ul angajatului gasit este ...
EXPECT_EQ(foundEmployee->getEmail(), "john.doe@example.com");
}

TEST(EmployeeRepositoryTest, RemoveEmployee) {
// testul verifica eliminarea unui angajat din repository si confirma ca angajatul nu mai poate fi gasit dupa eliminare
EmployeeRepository repo;
Employee employee("john.doe@example.com", "password123", "John", "Doe", "Manager", "JD", "555-0101", "123 Main St", "No remarks", 50000);
repo.addEmployee(employee);
repo.removeEmployee("john.doe@example.com");

Employee* foundEmployee = repo.searchEmployeeByEmail("john.doe@example.com");
ASSERT_EQ(foundEmployee, nullptr); // varificam ca angajatul nu mai est egasit
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

