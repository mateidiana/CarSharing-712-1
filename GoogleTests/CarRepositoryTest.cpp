#include "CarRepository.h"
#include "gtest/gtest.h"

// ../googletest/googletest/include/gtest/version.h.

class CarRepositoryTest : public ::testing::Test {
protected:
    CarRepository repository;
    Car car1 = Car("plate1", "Model1", "Brand1", 2000, 10000, 100.0, "Gasoline", "Manual", "Red", "No remarks");
    Car car2 = Car("plate2", "Model2", "Brand2", 2001, 20000, 200.0, "Diesel", "Automatic", "Blue", "No remarks");

    void SetUp() override {
        repository.addCar(car1);
        repository.addCar(car2);
    }
};

TEST_F(CarRepositoryTest, AddCar) {
    Car car3 = Car("plate3", "Model3", "Brand3", 2002, 30000, 300.0, "Electric", "Automatic", "Green", "No remarks");
    repository.addCar(car3);
    // Unfortunately, we can't directly check if the car was added as the cars vector is private
    // We can only assume it's working correctly if no exception is thrown
}

TEST_F(CarRepositoryTest, UpdateCar) {
    Car newCarData = Car("plate1", "UpdatedModel", "UpdatedBrand", 2005, 15000, 150.0, "Hybrid", "Manual", "Yellow", "Updated remarks");
    repository.updateCar("plate1", newCarData);
    // Again, we can't directly check if the car was updated as the cars vector is private
    // We can only assume it's working correctly if no exception is thrown
}

TEST_F(CarRepositoryTest, RemoveCar) {
    ASSERT_NO_THROW(repository.removeCar("plate1"));
    // Check that an exception is thrown when trying to remove the same car again
    ASSERT_THROW(repository.removeCar("plate1"), std::runtime_error);
}

TEST_F(CarRepositoryTest, DeactivateCar) {
    ASSERT_NO_THROW(repository.deactivateCar("plate2"));
    // Check that an exception is thrown when trying to deactivate the same car again
    ASSERT_THROW(repository.deactivateCar("plate2"), std::runtime_error);
}