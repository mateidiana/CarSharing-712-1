#include "CarRepository.h"
#include <algorithm>
#include <stdexcept>

void CarRepository::addCar(const Car& car) {
    cars.push_back(car);
}

void CarRepository::updateCar(const string& licensePlate, const Car& newCarData) {
    for (Car& car : cars) {
        if (car.getLicensePlate() == licensePlate) {
            car = newCarData;
            return;
        }
    }
    throw runtime_error("Car not found");
}

void CarRepository::removeCar(const string& licensePlate) {
    for (auto it = cars.begin(); it != cars.end(); ++it) {
        if (it->getLicensePlate() == licensePlate) {
            if (it->isOrdered()) {
                throw runtime_error("Car cannot be deleted because it has been ordered before");
            }
            cars.erase(it);
            return;
        }
    }
    throw runtime_error("Car not found");
}

void CarRepository::deactivateCar(const string& licensePlate) {
    for (Car& car : cars) {
        if (car.getLicensePlate() == licensePlate) {
            if (car.isOrdered()) {
                throw runtime_error("Car cannot be deactivated because it is currently ordered");
            }
            car.setActive(false);
            return;
        }
    }
    throw runtime_error("Car not found");
}


vector<Car> CarRepository::returnList() {
    return cars;
}

vector<Car> CarRepository::startData() {
        vector<Car> cars;
        cars.push_back(Car("SB23HBS", "Model S", "Tesla", 2020, 10000, 100.0, "Electric", "Automatic", "Red", "No remarks"));
        cars.push_back(Car("B294CTI", "Model 3", "Tesla", 2021, 5000, 80.0, "Electric", "Automatic", "Blue", "Some remarks"));
        cars.push_back(Car("SB11CIT", "Model Y", "Tesla", 2020, 10000, 100.0, "Electric", "Automatic", "Red", "No remarks"));
        cars.push_back(Car("CJ44HLF", "Model X", "Tesla", 2021, 5000, 200.0, "Electric", "Automatic", "Black", "Some remarks"));
        cars.push_back(Car("BH23MJE", "Series 5", "BMW", 2023, 20000, 125.0, "Diesel", "Automatic", "Black", "No remarks"));
        cars.push_back(Car("CT89HAM", "Series 4", "BMW", 2023, 4000, 90.0, "Petrol", "Automatic", "White", "Some remarks"));
        cars.push_back(Car("SJ10GRT", "Series 7", "BMW", 2023, 0, 300.0, "Diesel", "Automatic", "Black", "No remarks"));
        cars.push_back(Car("GJ02FMG", "C Class", "Mercedes-Benz", 2024, 6000, 100.0, "Petrol", "Automatic", "White", "Some remarks"));
        cars.push_back(Car("TR55BSC", "E Class", "Mercedes-Benz", 2024, 70000, 105.5, "Diesel", "Automatic", "Red", "No remarks"));
        cars.push_back(Car("GL13MGL", "S Class", "Mercedes-Benz", 2024, 9000, 99.0, "Petrol", "Automatic", "White", "Some remarks"));
        return cars;
}

