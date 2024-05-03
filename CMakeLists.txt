cmake_minimum_required(VERSION 3.26)
project(CarSharing_712_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(CarSharing_712_1 main.cpp
        Controller/Controller.h
        Domain-Kunde/Customer.h
        Domain-Kunde/Customer.cpp
        Domain-Kunde/Customer.cpp
        Repository-Kunden/CustomerRepository.h
        Repository-Kunden/CustomerRepository.cpp
        Controller/Controller.cpp)
