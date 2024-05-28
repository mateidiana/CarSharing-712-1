#include "../Repository-Car/CarRepository.h"
#include "gtest/gtest.h"

class CarRepositoryTest : public ::testing::Test {
protected:
    CarRepository repository;
    Car car1 = Car("plate1", "Model1", "Brand1", 2000, 10000, 100.0, "Gasoline", "Manual", "Red", "No remarks");
    Car car2 = Car("plate2", "Model2", "Brand2", 2001, 20000, 200.0, "Diesel", "Automatic", "Blue", "No remarks");

    void SetUp() override {
        car1.setOrdered(false);
        car2.setOrdered(false);
        repository.addCar(car1);
        repository.addCar(car2);
    }
};

TEST_F(CarRepositoryTest, AddCarIncreasesRepositorySize) {
    size_t initialSize = repository.returnList().size();
    Car car3 = Car("plate3", "Model3", "Brand3", 2002, 30000, 300.0, "Electric", "Automatic", "Green", "No remarks");
    repository.addCar(car3);
    ASSERT_EQ(repository.returnList().size(), initialSize + 1);
}

TEST_F(CarRepositoryTest, UpdateCarChangesCarData) {
    Car newCarData = Car("plate1", "UpdatedModel", "UpdatedBrand", 2005, 15000, 150.0, "Hybrid", "Manual", "Yellow", "Updated remarks");
    repository.updateCar("plate1", newCarData);
    auto cars = repository.returnList();
    auto it = std::find_if(cars.begin(), cars.end(), [](const Car& car) {
        return car.getLicensePlate() == "plate1";
    });
    ASSERT_NE(it, cars.end());
    ASSERT_EQ(it->getModel(), "UpdatedModel");
    ASSERT_EQ(it->getBrand(), "UpdatedBrand");
}

TEST_F(CarRepositoryTest, RemoveCarDecreasesRepositorySize) {
    size_t initialSize = repository.returnList().size();
    ASSERT_NO_THROW(repository.removeCar("plate1"));
    ASSERT_EQ(repository.returnList().size(), initialSize - 1);
}

TEST_F(CarRepositoryTest, RemoveCarThrowsExceptionWhenCarNotFound) {
    ASSERT_THROW(repository.removeCar("nonexistent_plate"), std::runtime_error);
}

TEST_F(CarRepositoryTest, DeactivateCarChangesCarStatus) {
    ASSERT_NO_THROW(repository.deactivateCar("plate2"));
    auto cars = repository.returnList();
    auto it = std::find_if(cars.begin(), cars.end(), [](const Car& car) {
        return car.getLicensePlate() == "plate2";
    });
    ASSERT_NE(it, cars.end());
    ASSERT_FALSE(it->isActive());
}

TEST_F(CarRepositoryTest, DeactivateCarThrowsExceptionWhenCarNotFound) {
    ASSERT_THROW(repository.deactivateCar("nonexistent_plate"), std::runtime_error);
}

//// Matei Dana-Maria
//#include <gtest/gtest.h>
//#include "../Domain-Employee/Employee.h"
//#include "../Repository-Employee/EmployeeRepository.h"
//
//TEST(EmployeeTest, CreateEmployee) {
//    // testul verifica daca  un obiect 'employee' este creeat corect cu atributele corespunzatoare
//    Employee employee("john.doe@example.com", "password123", "John", "Doe", "Manager", "JD", "077125639", "123 Main St", "No remarks", 50000);
//    // verificam daca valoarea asteptata (primul argument) este aceeasi cu valoarea obtinuta (al doilea argument)
//    ASSERT_EQ(employee.getEmail(), "john.doe@example.com");
//    ASSERT_EQ(employee.getPassword(), "password123");
//    ASSERT_EQ(employee.getName(), "John");
//    ASSERT_EQ(employee.getLastName(), "Doe");
//    ASSERT_EQ(employee.getPosition(), "Manager");
//    ASSERT_EQ(employee.getAbbreviation(), "JD");
//    ASSERT_EQ(employee.getPhoneNumber(), "555-0101");
//    ASSERT_EQ(employee.getAddress(), "123 Main St");
//    ASSERT_EQ(employee.getRemarks(), "No remarks");
//    ASSERT_EQ(employee.getSalary(), 50000);
//}
//
//TEST(EmployeeRepositoryTest, AddAndSearchEmployee) {
//    // testul verifica adaugarea unui angajat in repository si cautarea lui dupa email si abreviere
//    EmployeeRepository repo;
//    Employee employee("john.doe@example.com", "password123", "John", "Doe", "Manager", "JD", "555-0101", "123 Main St", "No remarks", 50000);
//    // adaugam angajatul in repository
//    repo.addEmployee(employee);
//    // cautam angajatul dupa email
//    Employee* foundEmployee = repo.searchEmployeeByEmail("john.doe@example.com");
//    // verific daca anjajatul a fost gasit (pointerul nu este null)
//    ASSERT_NE(foundEmployee, nullptr);
//    // verific daca numele angajatului gasit este John
//    EXPECT_EQ(foundEmployee->getName(), "John");
//    // caut angajatul dupa abreviere
//    foundEmployee = repo.searchEmployeeByAbbreviation("JD");
//    // verific daca anjajatul a fost gasit (pointerul nu este null)
//    ASSERT_NE(foundEmployee, nullptr);
//    // verific daca mail-ul angajatului gasit este ...
//    EXPECT_EQ(foundEmployee->getEmail(), "john.doe@example.com");
//}
//
//TEST(EmployeeRepositoryTest, RemoveEmployee) {
//    // testul verifica eliminarea unui angajat din repository si confirma ca angajatul nu mai poate fi gasit dupa eliminare
//    EmployeeRepository repo;
//    Employee employee("john.doe@example.com", "password123", "John", "Doe", "Manager", "JD", "555-0101", "123 Main St", "No remarks", 50000);
//    repo.addEmployee(employee);
//    repo.removeEmployee("john.doe@example.com");
//
//    Employee* foundEmployee = repo.searchEmployeeByEmail("john.doe@example.com");
//    ASSERT_EQ(foundEmployee, nullptr); // varificam ca angajatul nu mai est egasit
//}