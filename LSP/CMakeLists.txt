cmake_minimum_required(VERSION 3.2)

project(LSP)

set(CMAKE_AUTOMOC ON)
find_package(Qt5Test REQUIRED)
add_executable(LSP_test
        messagebad.cpp
        messagebad.h
        testmessage.cpp)

target_link_libraries(LSP_test Qt5::Test)
