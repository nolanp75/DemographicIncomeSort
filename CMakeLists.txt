cmake_minimum_required(VERSION 3.30)
project(DemographicIncomeSort)

set(CMAKE_CXX_STANDARD 14)

add_executable(DemographicIncomeSort
        main.cpp
        Customer.cpp
        quicksort.cpp
        quicksort.h
        Customer.h
)
