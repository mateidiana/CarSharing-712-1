#include <iostream>
#include "Controller/Controller.h"
#include "Domain-Car/Car.h"
#include <vector>

using namespace std;

vector<Car> CarStartData()
{
    //  Car(string licensePlate, string model, string brand, int firstRegistrationYear, int mileage, double dailyPrice, string fuelType, string transmission, string color, string remark);
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

int main() {
    std::cout << "salut !" << std::endl;
    vector<Car> cars = CarStartData();
    Controller c;
    c.idk();
    std::cout<<"Test";



    return 0;
}
