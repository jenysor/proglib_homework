cmake_minimum_required(VERSION 3.30)

set(PROJECT_NAME proglib_homework)
project(${PROJECT_NAME})

#target_include_directories()

add_subdirectory(googletest)

add_executable(${PROJECT_NAME}_main main.cpp)