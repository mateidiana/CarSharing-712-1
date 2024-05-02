cmake_minimum_required(VERSION 3.26)
project(CarSharing_712_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(CarSharing_712_1 main.cpp
        Controller/Controller.h
        Domain-Kunde/Kunde.h
        Domain-Kunde/Kunde.cpp
        Domain-Kunde/Kunde.cpp
        Repository-Kunden/KundenRepository.h
        Repository-Kunden/KundenRepository.cpp)
