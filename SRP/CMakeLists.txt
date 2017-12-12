cmake_minimum_required(VERSION 3.2)

project(SRP)

set(CMAKE_AUTOMOC ON)
find_package(Qt5Test REQUIRED)
add_executable(SRP_test
        testtextcorrector.cpp
        textcorrectorbad.cpp
        textcorrectorbad.h
        textcorrectorgood.cpp
        textcorrectorgood.h)

target_link_libraries(SRP_test Qt5::Test)
