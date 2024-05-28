#include "../Repository-Customers/CustomerRepository.h"
#include "gtest/gtest.h"


class CustomerRepositoryTest : public ::testing::Test {
protected:
    CustomerRepository repository;
    Customer customer1;
    vector<Customer> customers={customer1};


    CustomerRepositoryTest():
            repository(customers),
            customer1("1", "John", "Doe", "john.doe@example.com","byhdusi3", "1234567890", "Address", "Remarks", false ){}

    void SetUp() override {

        repository.createCustomer(customer1);
    }
};

TEST_F(CustomerRepositoryTest, CreateCustomer_Success) {
    Customer newCustomer("11", "Jane", "Smith", "jane.smith@example.com", "newid", "0987654321", "Another Address", "More Remarks", false);

    ASSERT_NO_THROW(repository.createCustomer(newCustomer));
    ASSERT_EQ(repository.getAll().size(), 2);
}

TEST_F(CustomerRepositoryTest, CreateCustomer_NotEmployee) {
    Customer newCustomer("11", "Jane", "Smith", "jane.smith@example.com","newid", "0987654321", "Another Address", "More Remarks", false);

    ASSERT_THROW(repository.createCustomer(newCustomer), std::invalid_argument);
    ASSERT_EQ(repository.getAll().size(), 1);
}

TEST_F(CustomerRepositoryTest, ModifyCustomer_Success) {
    Customer modifiedCustomer("1", "John", "Doe", "john.new@example.com","byhdusi3", "9876543210", "New Address", "New Remarks", false);

    ASSERT_NO_THROW(repository.modifyCustomer(modifiedCustomer));
    auto customers = repository.getAll();
    ASSERT_EQ(customers.at(0).getEmail(), "john.new@example.com");
    ASSERT_EQ(customers.at(0).getPhoneNumber(), "9876543210");
    ASSERT_EQ(customers.at(0).getAddress(), "New Address");
}

TEST_F(CustomerRepositoryTest, ModifyCustomer_NotEmployee) {
    Customer modifiedCustomer("1", "John", "Doe", "john.new@example.com","byhdusi3", "9876543210", "New Address", "New Remarks", false);

    Employee wrongEmployee("wrong@example.com", "wrongpassword", "wrongname", "wronglastName", "wrongposition", "wrongabbreviation", "0987654321", "Wrong Address", "wrongremarks", 100000,"wrongdate");

    ASSERT_THROW(repository.modifyCustomer(modifiedCustomer), std::invalid_argument);
    auto customers = repository.getAll();
    ASSERT_EQ(customers.at(0).getEmail(), "john.doe@example.com");
}

TEST_F(CustomerRepositoryTest, DeleteCustomer_Success) {
    ASSERT_NO_THROW(repository.deleteCustomer(customer1));
    ASSERT_EQ(repository.getAll().size(), 0);
}

TEST_F(CustomerRepositoryTest, DeleteCustomer_NotEmployee) {
    ASSERT_THROW(repository.deleteCustomer(customer1), std::invalid_argument);
    ASSERT_EQ(repository.getAll().size(), 1);
}

