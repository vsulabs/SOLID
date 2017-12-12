cmake_minimum_required(VERSION 3.2)

project(SOLID)

add_subdirectory(SRP)
add_subdirectory(OCP)
add_subdirectory(LSP)
add_subdirectory(ISP)
add_subdirectory(DIP)

enable_testing()
add_test(SRP_test SRP/SRP_test)
add_test(OCP_test OCP/OCP_test)
add_test(LSP_test LSP/LSP_test)
add_test(ISP_test ISP/ISP_test)
add_test(DIP_test DIP/DIP_test)
