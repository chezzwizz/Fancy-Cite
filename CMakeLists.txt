cmake_minimum_required(VERSION 3.10)

project(fcite VERSION 1.0.0.0 LANGUAGES CXX)
add_compile_options(/clr /diagnostics:caret)

add_executable(fcite FancyCite.cpp)
