cmake_minimum_required(VERSION 3.28)
project(label)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML COMPONENTS graphics window REQUIRED)

add_executable(${PROJECT_NAME} main.cpp drawer.cpp drawer.hpp)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics)