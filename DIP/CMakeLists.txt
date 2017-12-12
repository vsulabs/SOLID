cmake_minimum_required(VERSION 3.2)

project(DIP VERSION 0.0)

add_subdirectory(CppInject)
add_executable(DPI
    main.cpp
    servicebad.cpp
    servicebad.h
    servicegood.cpp
    servicegood.h
    )

target_link_libraries(DPI CppInject)
include_directories(CppInject/include)
