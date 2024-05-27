#include "../Repository-Customers/CustomerRepository.h"
#include "../Controller-Customers/CustomerController.h"
#include "gtest/gtest.h"

//Mane Sorina

class CustomerControllerTest: public ::testing::Test{
protected:
    CustomerRepository repoC;
    CustomerController controllerC;

    CustomerControllerTest(): controllerC(repoC){}

    void SetUp() override{
        Customer customer1("1","John","Doe","john@yahoo.com","0725698653","123 Strreet","No remarks",false,"password123");
        Customer customer2("2","Jane","SMith","jane@yahoo.com","0725569653","89 Strreet","Some remarks",false,"password456");

        repoC.createCustomer(customer1,false);
        repoC.createCustomer(customer2,false);
    }
};

TEST_F(CustomerControllerTest,ChangePasswordSuccessful){
    std::string email="john@yahoo.com";
    std::string oldPassword="password123";
    std::string newPassword="newpassword123";

    ASSERT_NO_THROW(controllerC.changePassword(email,newPassword,oldPassword));
    Customer updatedCustomer=controllerC.findByEmail(email);
    ASSERT_TRUE(updatedCustomer.authenticate(email,newPassword));
}

TEST_F(CustomerControllerTest,ChangePasswordUnauthorized){
    std::string email="john@example.com";
    std::string oldPassword="wrongpassword";
    std::string newPassword="newpassword123";

    ASSERT_THROW(controllerC.changePassword(email,newPassword,oldPassword), std::runtime_error);
}

TEST_F(CustomerControllerTest,ChangePasswordCustomerNotFound){
    std::string email="nonexistent@example.com";
    std::string oldPassword="password123";
    std::string newPassword="newpassword123";
    ASSERT_THROW(controllerC.changePassword(email,newPassword,oldPassword), std::runtime_error);
}

TEST_F(CustomerControllerTest,ChangeRemarksSuccessful){
    std::string email="jane@example.com";
    std::string password="password456";
    std::string newRemarks="Updated remarks";
    ASSERT_NO_THROW(controllerC.changeRemarks(email,newRemarks,password));
    Customer updatedCustomer=controllerC.findByEmail(email);
    ASSERT_EQ(updatedCustomer.getRemarks(),newRemarks);
}

TEST_F(CustomerControllerTest, ChnageRemarksUnauthorized){
    std::string email="jane@yahoo.com";
    std::string password="wrongpassword";
    std::string newRemarks="Updated remarks";
    ASSERT_THROW(controllerC.changeRemarks(email,newRemarks,password),std::runtime_error);
}

TEST_F(CustomerControllerTest, ChangeRemarksCustomerNotFound){
    std::string email="nonexistent@gmail.com";
    std::string password="password456";
    std::string newRemarks="Update remarks";
    ASSERT_THROW(controllerC.changeRemarks(email,newRemarks,password), std::runtime_error);
}