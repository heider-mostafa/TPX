cmake_minimum_required(VERSION 3.10.2)
project(TPX C)

set(CMAKE_C_STANDARD 99)
find_package(Threads REQUIRED)

add_executable(TPX main.c)
target_link_libraries(${PROJECT_NAME} Threads::Threads)