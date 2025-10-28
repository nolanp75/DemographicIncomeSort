cmake_minimum_required(VERSION 3.30)
project(DemographicIncomeSort)

set(CMAKE_CXX_STANDARD 14)

add_executable(main main.cpp
        Customer.cpp
        quicksort.cpp
        Customer.h
)
