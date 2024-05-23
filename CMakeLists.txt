cmake_minimum_required(VERSION 3.26)
project(CarSharing_712_1)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(GoogleTests)
add_subdirectory(Repository-Car)
add_subdirectory(Repository-Customers)
add_subdirectory(Domain-Car)
add_subdirectory(Domain-Customer)

add_executable(CarSharing_712_1 main.cpp
        Controller/Controller.h
        Controller/Controller.cpp
        Domain-Employee/Employee.h
        Domain-Employee/Employee.cpp
        Repository-Employee/EmployeeRepository.h
        Repository-Employee/EmployeeRepository.cpp
        Domain-Admin/Admin.h
        Domain-Admin/Admin.cpp
        Controller-Customers/CustomerController.h
        Controller-Customers/CustomerController.cpp
        Domain-Car/Car.h
        Domain-Car/Car.cpp
        Repository-Car/CarRepository.h
        Repository-Car/CarRepository.cpp
        Controller-Autos/control.h
        Controller-Autos/control.cpp
        Controller-Employee/EmployeeController.h
        Controller-Employee/EmployeeController.cpp
        UI-Employee/EmployeeUI.h
        UI-Employee/EmployeeUI.cpp)


target_link_libraries(CarSharing_712_1 CarRepositoryLib CarLib)
