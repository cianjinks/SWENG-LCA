cmake_minimum_required(VERSION 3.14)
project(lca_project)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/3b49be074d5c1340eeb447e6a8e78427051e675a.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  lca_test
  lca_test.cpp
  lca.cpp
  lca.h
)
target_link_libraries(
  lca_test
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(lca_test)