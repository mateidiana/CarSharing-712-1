#include "../Repository-Customers/CustomerRepository.h"
#include "../Domain-User/User.h"
#include "../Controller-Customers/CustomerController.h"
#include "gtest/gtest.h"


class CustomerControllerTest : public ::testing::Test {
protected:
    CustomerRepository customerRepo;    //stocare clienti
    CustomerController controller;

    Customer customer1 = Customer("1", "John", "Mike", "john.mike@example.com", "+1234567890", "Address1", "Remarks1", false, "password");
    Customer customer2 = Customer("2", "Jane", "Smith", "jane.smith@example.com", "+0987654321", "Address2", "Remarks2", false, "password");

    CustomerControllerTest() : controller(CustomerRepository()) {}

    void SetUp() override {
        customerRepo.createCustomer(customer1, false);
        customerRepo.createCustomer(customer2, false);
        controller = CustomerController(std::move(customerRepo));   //mutare repo in controller
    }
};

TEST_F(CustomerControllerTest, IsEmailTakenReturnsTrueForExistingEmail) {
    ASSERT_TRUE(controller.isEmailTaken("john.mike@example.com"));  //luat
}

TEST_F(CustomerControllerTest, IsEmailTakenReturnsFalseForNonExistingEmail) {
    ASSERT_FALSE(controller.isEmailTaken("new.email@example.com")); //neluat
}

TEST_F(CustomerControllerTest, IsPhoneNumberValidReturnsFalseForInvalidNumber) {
    ASSERT_FALSE(controller.isPhoneNumberValid("123-456-7890"));    //invalid
    ASSERT_FALSE(controller.isPhoneNumberValid("phone1234"));     //invalid
    ASSERT_FALSE(controller.isPhoneNumberValid("+123 456 78A9"));     //invalid
}

TEST_F(CustomerControllerTest, IsPhoneNumberValidReturnsTrueForValidNumber) {   //valide toate
    ASSERT_TRUE(controller.isPhoneNumberValid("+1234567890"));
    ASSERT_TRUE(controller.isPhoneNumberValid("1234567890"));
    ASSERT_TRUE(controller.isPhoneNumberValid("+123 456 7890"));
}

TEST_F(CustomerControllerTest, IsEmailFormaValidReturnsFalseForInvalidEmail) {  //invalide
    ASSERT_FALSE(controller.isEmailFormaValid("plainaddress"));
    ASSERT_FALSE(controller.isEmailFormaValid("@missingusername.com"));
    ASSERT_FALSE(controller.isEmailFormaValid("username@.com"));
}

TEST_F(CustomerControllerTest, IsEmailFormaValidReturnsTrueForValidEmail) { //valide
    ASSERT_TRUE(controller.isEmailFormaValid("email@example.com"));
    ASSERT_TRUE(controller.isEmailFormaValid("firstname.lastname@example.com"));
    ASSERT_TRUE(controller.isEmailFormaValid("email@subdomain.example.com"));
}
//gdprDeleted = false, toate campurile completate
TEST_F(CustomerControllerTest, AddCustomerThrowsNoErrorWhenGdprFalseAndAllFieldsFilled) {
    ASSERT_NO_THROW(controller.addCustomer("3", "Alice", "Wonder", "alice.wonder@example.com", "password",
                                           "+1122334455", "Address3", "Remarks3", false, false));
}

//gdprDeleted = false, campuri obligatorii necompletate
TEST_F(CustomerControllerTest, AddCustomerThrowsErrorWhenGdprFalseAndFieldsMissing) {
    ASSERT_THROW(controller.addCustomer("", "Alice", "Wonder", "alice.wonder@example.com", "password",
                                        "+1122334455", "Address3", "Remarks3", false, false), std::runtime_error);
    ASSERT_THROW(controller.addCustomer("3", "", "Wonder", "alice.wonder@example.com", "password",
                                        "+1122334455", "Address3", "Remarks3", false, false), std::runtime_error);
    ASSERT_THROW(controller.addCustomer("3", "Alice", "", "alice.wonder@example.com", "password",
                                        "+1122334455", "Address3", "Remarks3", false, false), std::runtime_error);
    ASSERT_THROW(controller.addCustomer("3", "Alice", "Wonder", "", "password",
                                        "+1122334455", "Address3", "Remarks3", false, false), std::runtime_error);
    ASSERT_THROW(controller.addCustomer("3", "Alice", "Wonder", "alice.wonder@example.com", "",
                                        "+1122334455", "Address3", "Remarks3", false, false), std::runtime_error);
    ASSERT_THROW(controller.addCustomer("3", "Alice", "Wonder", "alice.wonder@example.com", "password",
                                        "", "Address3", "Remarks3", false, false), std::runtime_error);
}

//gdprDeleted = true, name + lastName completate
TEST_F(CustomerControllerTest, AddCustomerThrowsNoErrorWhenGdprTrueAndNameFieldsFilled) {
    ASSERT_NO_THROW(controller.addCustomer("", "Alice", "Wonder", "", "",
                                           "", "", "Remarks3", true, false));
}

//gdprDeleted = true, name + lastName necompletate
TEST_F(CustomerControllerTest, AddCustomerThrowsErrorWhenGdprTrueAndNameFieldsMissing) {
    ASSERT_THROW(controller.addCustomer("", "", "Wonder", "", "",
                                        "", "", "Remarks3", true, false), std::runtime_error);
    ASSERT_THROW(controller.addCustomer("", "Alice", "", "", "",
                                        "", "", "Remarks3", true, false), std::runtime_error);
}
