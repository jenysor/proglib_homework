project(movable)

file(GLOB_RECURSE SOURCE_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h )

add_library(${PROJECT_NAME} ${LIBRARY_TYPE} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PUBLIC interfaces)

target_include_directories(${PROJECT_NAME}
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB_RECURSE TEST_SOURCE_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/test/*)

add_executable(${PROJECT_NAME}_test ${TEST_SOURCE_FILES})
target_link_libraries(${PROJECT_NAME}_test ${PROJECT_NAME} gtest gmock)
set_target_properties(${PROJECT_NAME}_test PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/test
)

include(GoogleTest)
include(CTest)

gtest_discover_tests(${PROJECT_NAME}_test)




