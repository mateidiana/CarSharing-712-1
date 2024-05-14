//
// Created by andre on 14/05/2024.
//

#include "CarRepository.h"
#include <algorithm>
#include <stdexcept>

void CarManager::createCar(const Car& car) {
    cars.push_back(car);
}

void CarManager::modifyCar(const string& licensePlate, const Car& newCarData) {
    for (Car& car : cars) {
        if (car.getLicensePlate() == licensePlate) {
            car = newCarData;
            return;
        }
    }
    throw runtime_error("Car not found");
}