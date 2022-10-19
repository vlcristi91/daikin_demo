cmake_minimum_required(VERSION 3.0.0)

project(Daikin_demo VERSION 1.0.0)
add_subdirectory(test)

add_executable(daikin


src/AcController.cpp
src/AcControllerStates.cpp
src/main.cpp)

target_include_directories(daikin PRIVATE include)