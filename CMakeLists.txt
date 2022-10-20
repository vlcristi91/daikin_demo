cmake_minimum_required(VERSION 3.0.0)

project(Daikin_demo VERSION 1.0.0)
add_subdirectory(test)


add_library(daikin_ac_controller
src/AcController.cpp
src/AcControllerStates.cpp
src/AcControllerInput.cpp
src/AcControllerOutput.cpp
)

target_include_directories(daikin_ac_controller PRIVATE include)

add_executable(daikin_demo
src/main.cpp)

target_link_libraries(daikin_demo daikin_ac_controller)

target_include_directories(daikin_demo PRIVATE include)