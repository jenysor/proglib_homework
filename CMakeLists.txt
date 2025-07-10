cmake_minimum_required(VERSION 3.30)

set(PROJECT_NAME proglib_homework)
project(${PROJECT_NAME})

file(GLOB_RECURSE SOURCE_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h )

add_subdirectory(googletest)
add_subdirectory(movable)
add_subdirectory(rotating)

add_executable(${PROJECT_NAME}_main main.cpp)
target_link_libraries(${PROJECT_NAME}_main PUBLIC movable rotating)

#file(GLOB_RECURSE TEST_SOURCE_FILES
#        ${CMAKE_CURRENT_SOURCE_DIR}/test/*)
#
#add_executable(${PROJECT_NAME}_test ${TEST_SOURCE_FILES})