cmake_minimum_required(VERSION 3.14)
project(my_project)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  TestAcController
  TestAcController.cpp
)
target_link_libraries(
    TestAcController
    daikin_ac_controller
  GTest::gtest_main
  gmock_main

)

target_include_directories(TestAcController PUBLIC ../include)

include(GoogleTest)
gtest_discover_tests(TestAcController)
