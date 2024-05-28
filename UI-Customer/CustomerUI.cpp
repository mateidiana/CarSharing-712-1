//
// Created by so17 on 5/26/24.
//
#include "CustomerUI.h"
#include "../Repository-Car/CarRepository.h"
#include <iostream>
#include <exception>
using namespace std;


CustomerUI::CustomerUI(CustomerController &controller):controller(controller) {};

void CustomerUI::showMenu() {
    int choice;
    do{
    cout << "1. Login";
    cout <<"2. Add Customer";
    cout <<"3. Add car to favourite list"<<endl;
    cout<< "4. See favourite cars"<<endl;
    cout << "Choose option";
    cin>>choice;
    switch(choice){
        case 1:
            login();
            break;
        case 2:
            addCustomer();
            break;
        case 3:
            addToFavourites();
            break;
        case 4:

        default:
            cout<<"Invalid option please try again!"<<endl;

        }
    }while(choice!=1 && choice !=2);

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
            customer.setLoginStatus(true);
        }else{
            cout<<"Invalid email or password"<<endl;
            customer.setLoginStatus(false);
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

void CustomerUI::addToFavourites() {
    string email;
    cout<<"Input your email adress:";
    cin>>email;
    Customer customer=controller.findByEmail(email);
    vector<Car> cars;
    CarRepository carrepo;
    cars=carrepo.returnList();
    for(int i=0; i<cars.size(); i++) {
        cout<<i<<". "<<cars[i].getBrand()<<" "<<cars[i].getModel()<<" "<<cars[i].getDailyPrice()<<endl;
    }
    try{
        int preference;
        cout<<"Enter prefered number in the list: ";
        cin>>preference;
        customer.addToFavourites(cars[preference]);

    }catch(const std::exception &e) {
        cout << "Error adding customer: " << e.what() << endl;
    }
}

void CustomerUI::seeFavouriteList(){
    string email;
    cout<<"Input your email adress:";
    cin>>email;
    Customer customer=controller.findByEmail(email);
    vector<Car>  favouritelist =customer.seeFavourites();
    for(auto vroom: favouritelist)
        cout<<vroom.getBrand()<<" "<<vroom.getModel()<<" "<<vroom.getDailyPrice()<<vroom.getColor()<<" "<<endl;
};