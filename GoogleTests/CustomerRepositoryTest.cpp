#include "../Repository-Customers/CustomerRepository.h"
#include "../Domain-Employee/Employee.h"
#include "gtest/gtest.h"

class CustomerRepositoryTest : public ::testing::Test {
protected:
    CustomerRepository repository;
    Customer customer1;
    Employee employee;

    CustomerRepositoryTest()
            : customer1("1", "John", "Doe", "john.doe@example.com", "1234567890", "Address", "Remarks", false, "byhdusi3"),
              employee("emp@example.com", "password", "name", "lastName", "position", "abbreviation", "1234567890", "Address", "remarks", 150000, "01.01.1980")
    {
    }
};

TEST_F(CustomerRepositoryTest, CreateCustomer_Success) {
    Customer newCustomer("11", "Jane", "Smith", "jane.smith@example.com", "0987654321", "Another Address", "More Remarks", false, "newid");

    ASSERT_NO_THROW(repository.createCustomer(newCustomer, employee));
    ASSERT_EQ(repository.getAll().size(), 2);
}

TEST_F(CustomerRepositoryTest, CreateCustomer_NotEmployee) {
    Customer newCustomer("11", "Jane", "Smith", "jane.smith@example.com", "0987654321", "Another Address", "More Remarks", false, "newid");

    ASSERT_THROW(repository.createCustomer(newCustomer, employee), std::invalid_argument);
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

    Employee wrongEmployee("wrong@example.com", "wrongpassword", "wrongname", "wronglastName", "wrongposition", "wrongabbreviation", "0987654321", "Wrong Address", "wrongremarks", 100000, "02.02.1985");

    ASSERT_THROW(repository.modifyCustomer(modifiedCustomer, wrongEmployee), std::invalid_argument);
    auto customers = repository.getAll();
    ASSERT_EQ(customers.at(0).getEmail(), "john.doe@example.com");
}

TEST_F(CustomerRepositoryTest, DeleteCustomer_Success) {
    ASSERT_NO_THROW(repository.deleteCustomer(customer1, employee));
    ASSERT_EQ(repository.getAll().size(), 0);
}

TEST_F(CustomerRepositoryTest, DeleteCustomer_NotEmployee) {
    ASSERT_THROW(repository.deleteCustomer(customer1, employee), std::invalid_argument);
    ASSERT_EQ(repository.getAll().size(), 1);
}

TEST_F(CustomerRepositoryTest, AnonymizeCustomer_NotEmployee) {
    ASSERT_THROW(repository.anonymizeCustomer(customer1, employee), std::invalid_argument);
    auto customers = repository.getAll();
    ASSERT_EQ(customers.at(0).getName(), "John");
}

TEST_F(CustomerRepositoryTest, AnonymizeCustomer_Success) {
    ASSERT_NO_THROW(repository.anonymizeCustomer(customer1, employee));
    auto customers = repository.getAll();
    ASSERT_EQ(customers.at(0).getName(), "Customer-1");
    ASSERT_EQ(customers.at(0).getlastName(), "Unknown");
    ASSERT_EQ(customers.at(0).getEmail(), "");
    ASSERT_EQ(customers.at(0).getPhoneNumber(), "");
    ASSERT_EQ(customers.at(0).getAddress(), "");
    ASSERT_EQ(customers.at(0).getRemarks(), "");
    ASSERT_TRUE(customers.at(0).getGdprDeleted());
}
