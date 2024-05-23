#include "../Repository-Customers/CustomerRepository.h"
#include "../Domain-Employee/Employee.h"
#include "gtest/gtest.h"


class CustomerRepositoryTest : public ::testing::Test {
protected:
    CustomerRepository repository;
    Customer customer1;
    Employee employee;

    void SetUp() override {
        customer1 = Customer("1", "John", "Doe", "john.doe@example.com", "1234567890", "Address", "Remarks", false, "byhdusi3");
        employee = Employee("emp@example.com", "password", "name", "lastName", "position", "abbreviation", "1234567890", "Address", "remarks", 150000);
    }
};

TEST_F(CustomerRepositoryTest, CreateCustomer_Success) {
    Customer newCustomer("11", "Jane", "Smith", "jane.smith@example.com", "0987654321", "Another Address", "More Remarks", false, "newid");

    ASSERT_NO_THROW(repository.createCustomer(newCustomer, true));
    ASSERT_EQ(repository.getAll().size(), 2);
}

TEST_F(CustomerRepositoryTest, CreateCustomer_NotEmployee) {
    Customer newCustomer("11", "Jane", "Smith", "jane.smith@example.com", "0987654321", "Another Address", "More Remarks", false, "newid");

    ASSERT_THROW(repository.createCustomer(newCustomer, false), std::invalid_argument);
    ASSERT_EQ(repository.getAll().size(), 1);
}

TEST_F(CustomerRepositoryTest, ModifyCustomer_Success) {
    Customer modifiedCustomer("1", "John", "Doe", "john.new@example.com", "9876543210", "New Address", "New Remarks", false, "byhdusi3");

    ASSERT_NO_THROW(repository.modifyCustomer(modifiedCustomer, employee));
    auto customers = repository.getAll();
    ASSERT_EQ(customers.at(0).getEmail(), "john.new@example.com");
    ASSERT_EQ(customers.at(0).getPhoneNumber(), "9876543210");
    ASSERT_EQ(customers.at(0).getAddress(), "New Address");
}

TEST_F(CustomerRepositoryTest, ModifyCustomer_NotEmployee) {
    Customer modifiedCustomer("1", "John", "Doe", "john.new@example.com", "9876543210", "New Address", "New Remarks", false, "byhdusi3");

    Employee wrongEmployee("wrong@example.com", "wrongpassword", "wrongname", "wronglastName", "wrongposition", "wrongabbreviation", "0987654321", "Wrong Address", "wrongremarks", 100000);

    ASSERT_THROW(repository.modifyCustomer(modifiedCustomer, wrongEmployee), std::invalid_argument);
    auto customers = repository.getAll();
    ASSERT_EQ(customers.at(0).getEmail(), "john.doe@example.com");
}

TEST_F(CustomerRepositoryTest, DeleteCustomer_Success) {
    ASSERT_NO_THROW(repository.deleteCustomer(customer1, true));
    ASSERT_EQ(repository.getAll().size(), 0);
}

TEST_F(CustomerRepositoryTest, DeleteCustomer_NotEmployee) {
    ASSERT_THROW(repository.deleteCustomer(customer1, false), std::invalid_argument);
    ASSERT_EQ(repository.getAll().size(), 1);
}


TEST_F(CustomerRepositoryTest, AnonymizeCustomer_NotEmployee) {
    ASSERT_THROW(repository.anonymizeCustomer(customer1, false), std::invalid_argument);
    auto customers = repository.getAll();
    ASSERT_EQ(customers.at(0).getName(), "John");
}
