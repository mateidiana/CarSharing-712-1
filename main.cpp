#include <iostream>
#include <fstream>
#include <string>
#include "controller.cpp"
using namespace std;

void read(ifstream& inputFile, string& firstName, string& lastName, string& EmailAddress, string& occupation, string& car, string& model) {
    getline(inputFile, firstName, ' ');
    getline(inputFile, lastName, ' ');
    getline(inputFile, EmailAddress, ' ');
    getline(inputFile, occupation, ' ');
    getline(inputFile, car, ' ');
    getline(inputFile, model, ' ');
}

int main() {
    EmployeeController controller;
    int nr;
    string firstName, lastName, EmailAddress, occupation, car, model;
    ifstream inputFile("file.txt");
    if(!inputFile.is_open()) {
        cerr << "Failed to open input file." << endl;
        return 1;
    }
    inputFile >> nr;
    inputFile.ignore();
    for(int i = 0; i < nr; ++i) {
        read(inputFile, firstName, lastName, EmailAddress, occupation, car, model);
        Employee newEmployee(firstName, lastName, EmailAddress, occupation, car, model);
        controller.addEmployee(newEmployee);
        inputFile.ignore();
        cout << firstName << " " << lastName << " " << EmailAddress << " " << occupation << " " << car << " " << model;
    }
    inputFile.close();
    return 0;
}