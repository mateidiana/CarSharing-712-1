//
// Created by andre on 14/05/2024.
//

#ifndef CARSHARING_712_1_CARREPOSITORY_H
#define CARSHARING_712_1_CARREPOSITORY_H

#include <vector>
#include "../Domain-Car/Car.h"

using namespace std;

class CarManager {
private:
    vector<Car> cars;

public:
    void createCar(const Car& car);
    void modifyCar(const string& licensePlate, const Car& newCarData);
    void deleteCar(const string& licensePlate);
    void deactivateCar(const string& licensePlate);
};

#endif //CARSHARING_712_1_CARREPOSITORY_H
