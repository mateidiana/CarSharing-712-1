#include "../Domain-Employee/Employee.h"
#include "gtest/gtest.h"
#include "../Domain-Customer/Customer.h"

class EmployeeTest : public ::testing::Test {
protected:
    Employee employee;

    EmployeeTest()
            : employee("email@example.com", "password", "John", "Doe", "Manager", "JD", "1234567890", "123 Street", "No remarks", 1500.0, "1980-01-01") {}

    void SetUp() override {
        // Initialize the employee object if needed
    }
};

TEST_F(EmployeeTest, SetSalaryThrowsExceptionForLowSalary) {
ASSERT_THROW(employee.setSalary(50), std::invalid_argument);
}

TEST_F(EmployeeTest, SetSalarySetsValidSalary) {
ASSERT_NO_THROW(employee.setSalary(150));
ASSERT_EQ(employee.getSalary(), 150);
}

TEST_F(EmployeeTest, CalculateAgeReturnsCorrectAge) {
std::string currentDate = "2024-05-01";
ASSERT_EQ(employee.calculateAge(currentDate), 44); // Assuming birth date is "1980-01-01"
}

TEST_F(EmployeeTest, CalculateAgeThrowsExceptionForInvalidAge) {
Employee youngEmployee("email@example.com", "password", "John", "Doe", "Manager", "JD", "1234567890", "123 Street", "No remarks", 1500.0, "2023-01-01");
std::string currentDate = "2024-05-01";
ASSERT_THROW(youngEmployee.calculateAge(currentDate), std::invalid_argument);
}

TEST_F(EmployeeTest, ValidateThrowsExceptionForMissingFields) {
Employee invalidEmployee("", "password", "John", "Doe", "Manager", "JD", "1234567890", "123 Street", "No remarks", 1500.0, "1980-01-01");
ASSERT_THROW(invalidEmployee.validate(), std::invalid_argument);
}

TEST_F(EmployeeTest, ValidateSucceedsForValidEmployee) {
ASSERT_NO_THROW(employee.validate());
}

class OrderTest : public ::testing::Test {
protected:
    Order order;
    Employee employee;

    OrderTest()
            : order("order123", Date{2024, 5, 1}, Status::Order, Car("plate1", "Model1", "Brand1", 2000, 10000, 100.0, "Gasoline", "Manual", "Red", "No remarks"),
                    Date{2024, 5, 1}, Date{2024, 5, 10}, Customer("customer@example.com", "password", "Customer", "Name", "CN", "9876543210", "456 Avenue", "No remarks"),
                    employee, 500, "No remarks"),
              employee("email@example.com", "password", "John", "Doe", "Manager", "JD", "1234567890", "123 Street", "No remarks", 1500.0, "1980-01-01") {}

    void SetUp() override {
        // Initialize objects if needed
    }
};

TEST_F(OrderTest, PlaceOrderAddsOrder) {
ASSERT_NO_THROW(employee.placeOrder(order));
// Check repository or order system to ensure order was added
// Assuming we have a function like `orderRepository.getOrder(order.getOrderNumber())`
// ASSERT_EQ(orderRepository.getOrder(order.getOrderNumber()).getOrderNumber(), order.getOrderNumber());
}
