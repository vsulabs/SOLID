cmake_minimum_required(VERSION 3.2)

project(OCP)

set(CMAKE_AUTOMOC ON)
find_package(Qt5Test REQUIRED)
add_executable(OCP_test
        testcmdprocessor.cpp
        cmdprocessorbad.cpp
        cmdprocessorgood.cpp
        cmdprocessortemplate.cpp
        icmdprocessor.h 
        cmdprocessorbad.h
        cmdprocessorgood.h
        cmdprocessortemplate.h)

target_link_libraries(OCP_test Qt5::Test)
