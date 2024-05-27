//
// Created by so17 on 5/26/24.
//
#include "CustomerUI.h"
#include <iostream>
#include <exception>
using namespace std;


CustomerUI::CustomerUI(CustomerController &controller):controller(controller) {};

void CustomerUI::showMenu() {
    cout << "1. Login";
    cout <<"2.Add Customer";
    cout << "Choose option";


}

void CustomerUI::login() {
    string email,password;
    cout<<"Enter email: ";
    cin>>email;
    cout<<"Enter password: ";

    try{

        Customer customer=controller.findByEmail(email);

        if(customer.authenticate(email, password)){
            cout<<"Login successfull!"<<endl;
        }else{
            cout<<"Invalid email or password"<<endl;
        }
    }catch(const exception& e){
        cout<<"Error: "<<e.what()<<endl;
    }

}

void CustomerUI::addCustomer() {
    string id,name,lastName,email,password,phoneNumber,address,remarks;
    bool gdprDeleted=false;


    cout<<"Enter id: ";
    cin>>id;
    cin.ignore();
    cout<<"Enter First Name: ";
    cin>>name;
    cin.ignore();
    cout<<"Enter Last Name: ";
    cin>>lastName;
    cin.ignore();
    cout<<"Enter email: ";
    cin>>email;
    cin.ignore();
    cout<<"Enter password: ";
    cin>>password;
    cin.ignore();
    cout<<"Enter phoneNumber: ";
    cin>>phoneNumber;
    cin.ignore();
    cout<<"Enter address: ";
    cin>>address;
    cin.ignore();
    cout<<"Enter remarks: ";
    getline(cin,remarks);

    try{
        controller.addCustomer(id,name,lastName,email,password,phoneNumber,address,remarks,gdprDeleted);
        cout<<"Customer added successfully!";

    }catch(const std::exception &e) {
        cout << "Error adding customer: " << e.what() << endl;
    }

}