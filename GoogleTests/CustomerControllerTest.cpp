#include "../Repository-Car/CarRepository.h"
#include "gtest/gtest.h"

class CustomerControllerTest : public ::testing::Test {
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

TEST_F(CustomerControllerTest, AddCarIncreasesRepositorySize) {
    size_t initialSize = repository.returnList().size();
    Car car3 = Car("plate3", "Model3", "Brand3", 2002, 30000, 300.0, "Electric", "Automatic", "Green", "No remarks");
    repository.addCar(car3);
    ASSERT_EQ(repository.returnList().size(), initialSize + 1);
}

TEST_F(CustomerControllerTest, UpdateCarChangesCarData) {
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

TEST_F(CustomerControllerTest, RemoveCarDecreasesRepositorySize) {
    size_t initialSize = repository.returnList().size();
    ASSERT_NO_THROW(repository.removeCar("plate1"));
    ASSERT_EQ(repository.returnList().size(), initialSize - 1);
}

TEST_F(CustomerControllerTest, RemoveCarThrowsExceptionWhenCarNotFound) {
    ASSERT_THROW(repository.removeCar("nonexistent_plate"), std::runtime_error);
}

TEST_F(CustomerControllerTest, DeactivateCarChangesCarStatus) {
    ASSERT_NO_THROW(repository.deactivateCar("plate2"));
    auto cars = repository.returnList();
    auto it = std::find_if(cars.begin(), cars.end(), [](const Car& car) {
        return car.getLicensePlate() == "plate2";
    });
    ASSERT_NE(it, cars.end());
    ASSERT_FALSE(it->isActive());
}

TEST_F(CustomerControllerTest, DeactivateCarThrowsExceptionWhenCarNotFound) {
    ASSERT_THROW(repository.deactivateCar("nonexistent_plate"), std::runtime_error);
}