cmake_minimum_required(VERSION 3.26)
project(CarSharing_712_1)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(GoogleTests)
add_subdirectory(Repository-Car)
add_subdirectory(Domain-Car)

add_executable(CarSharing_712_1 main.cpp
        Controller/Controller.h
        Domain-Customer/Customer.h
        Domain-Customer/Customer.cpp
        Domain-Customer/Customer.cpp
        Repository-Customers/CustomerRepository.h
        Repository-Customers/CustomerRepository.cpp
        Controller/Controller.cpp
        Domain-Employee/Employee.h
        Domain-Employee/Employee.cpp
        Repository-Employee/EmployeeRepository.h
        Repository-Employee/EmployeeRepository.cpp
        Domain-Admin/Admin.h
        Domain-Admin/Admin.cpp
        Controller-Customers/CustomerController.h
        Controller-Customers/CustomerController.cpp
        Controller-Autos/control.h
        Controller-Autos/control.cpp)

target_link_libraries(CarSharing_712_1 CarRepositoryLib CarLib)
