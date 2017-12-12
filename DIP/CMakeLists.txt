cmake_minimum_required(VERSION 3.2)

project(DIP)

add_subdirectory(CppInject)

set(CMAKE_AUTOMOC ON)
find_package(Qt5Test REQUIRED)
add_executable(DIP_test
    teststringreader.cpp
    servicebad.cpp
    servicebad.h
    servicegood.cpp
    servicegood.h
    )

target_link_libraries(DIP_test CppInject Qt5::Test)
include_directories(CppInject/include)
