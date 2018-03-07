# © 2017 Joseph Cameron - All Rights Reserved
# Project: Hello Travis CI
# Created on 2017-12-7.

cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
enable_testing()

configure_file(cmake.h.in cmake.h @ONLY)

set(PROJECTWIDE_COMPILER_FEATURE_REQUIREMENTS
    PRIVATE
        cxx_variadic_templates
        cxx_nullptr
        cxx_lambdas
)

#[[project("Hello-Travis-CI")
add_executable(${PROJECT_NAME}
    "./main.cpp"
    "./Object.cpp" "./Object.h"
)
target_compile_features(${PROJECT_NAME} ${PROJECTWIDE_COMPILER_FEATURE_REQUIREMENTS})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

project("Example-Test")
add_executable(${PROJECT_NAME}
    "./test.cpp"
    "./Object.cpp" "./Object.h"
)
target_compile_features(${PROJECT_NAME} ${PROJECTWIDE_COMPILER_FEATURE_REQUIREMENTS})
add_test(${PROJECT_NAME} ${PROJECT_NAME})]]

SET(TEST_DIR "../tests")

project("default_ptr_test")
add_executable(${PROJECT_NAME}
    "${TEST_DIR}/default_ptr_test.cpp"
)
target_compile_features(${PROJECT_NAME} ${PROJECTWIDE_COMPILER_FEATURE_REQUIREMENTS})
add_test(${PROJECT_NAME} ${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE "common")
