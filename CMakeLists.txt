cmake_minimum_required(VERSION 3.30)

set(PROJECT_NAME proglib_homework)
project(${PROJECT_NAME})

if (UNIX)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/lib)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
elseif (WIN32)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)
endif ()

set(RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(TEST_OUTPUT_PATH "${RUNTIME_OUTPUT_DIRECTORY}/test")

set(LIBRARY_TYPE "SHARED")

file(GLOB_RECURSE SOURCE_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h )

add_subdirectory(googletest)
add_subdirectory(movable)
add_subdirectory(rotating)

add_executable(${PROJECT_NAME}_main main.cpp)
target_link_libraries(${PROJECT_NAME}_main PUBLIC movable rotating)

target_link_directories(movable_test PRIVATE ${CMAKE_BINARY_DIR}/movable)
target_link_directories(rotating_test PRIVATE ${CMAKE_BINARY_DIR}/rotating)

enable_testing()

#file(GLOB_RECURSE TEST_SOURCE_FILES
#        ${CMAKE_CURRENT_SOURCE_DIR}/test/*)
#
#add_executable(${PROJECT_NAME}_test ${TEST_SOURCE_FILES})