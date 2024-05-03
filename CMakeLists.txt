cmake_minimum_required(VERSION 3.26)
project(CarSharing_712_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(CarSharing_712_1 main.cpp
        Controller/Controller.h
        Domain-Customer/Customer.h
        Domain-Customer/Customer.cpp
        Domain-Customer/Customer.cpp
        Repository-Customers/CustomerRepository.h
        Repository-Customers/CustomerRepository.cpp
        Controller/Controller.cpp)
