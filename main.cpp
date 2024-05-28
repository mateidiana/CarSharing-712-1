#include <iostream>
#include <fstream>
#include <string>
#include "controller.cpp"
#include "Employee.h"
#include "User.h"
using namespace std;

void read(ifstream& inputFile, string name_, string lastName_, string position_, string abbreviation_, string phoneNumber_, string address_, string remarks_,
          double salary_, string birthDate_) {
    getline(inputFile, name_, ' ');
    getline(inputFile, lastName_, ' ');
    getline(inputFile, position_, ' ');
    getline(inputFile, abbreviation_, ' ');
    getline(inputFile, phoneNumber_, ' ');
    getline(inputFile, address_, ' ');
    getline(inputFile, remarks_, ' ');
    inputFile >> salary_;
    getline(inputFile, birthDate_, ' ');
}

int main() {
    EmployeeController controller;
    int nr;
    double salary_;
    string name_, lastName_, position_, abbreviation_, phoneNumber_, address_, remarks_, birthDate_;
    ifstream inputFile("file.txt");
    if(!inputFile.is_open()) {
        cerr << "Failed to open input file." << endl;
        return 1;
    }
    inputFile >> nr;
    inputFile.ignore();
    for(int i = 0; i < nr; ++i) {
        read(inputFile, name_, lastName_, position_, abbreviation_, phoneNumber_, address_, remarks_, salary_, birthDate_);
        Employee newEmployee(name_, lastName_, position_, abbreviation_, phoneNumber_, address_, remarks_, salary_, birthDate_);
        controller.addEmployee(newEmployee);
        inputFile.ignore();
        cout << name_ << " " << lastName_ << " " << position_ << " " << abbreviation_ << " " << phoneNumber_ << " " << address_ << " " <<
        remarks_ << " " << salary_ << " " << birthDate_;
    }
    inputFile.close();
    return 0;
}
