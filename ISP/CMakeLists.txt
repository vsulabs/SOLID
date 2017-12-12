cmake_minimum_required(VERSION 3.2)

project(ISP)

set(CMAKE_AUTOMOC ON)
find_package(Qt5Test          REQUIRED)
add_executable(ISP_test
        settingsbad.h
        settingsgood.h
        settingsbad.cpp
        settingsgood.cpp
        testsettings.cpp)

target_link_libraries(ISP_test Qt5::Test)
