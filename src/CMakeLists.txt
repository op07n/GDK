# © 2017 Joseph Cameron - All Rights Reserved
# Project: Hello Travis CI
# Created on 2017-12-7.
cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
enable_testing()

configure_file(cmake.h.in cmake.h @ONLY)

SET(TEST_DIR "../tests")
SET(LIBS_DIR "../libs")

#[[!
 \brief boilerplate for creating a unit test
 \param argv0: name of the test & test file
 \param argvN>0: [optional] additional c files needed to compile test. 
 \note Prefer mocking to including more code!
]]
function(create_unit_test ...)
    set(sourceList "")

    foreach(loop_var RANGE ${ARGC})
        if (loop_var GREATER 0 AND loop_var LESS ARGC)
            list(APPEND sourceList "${ARGV${loop_var}}")
        endif()
    endforeach()

    project("${ARGV0}")
    add_executable(${PROJECT_NAME}
        "${sourceList}"
        "${TEST_DIR}/${ARGV0}.cpp"
    )
    target_compile_features(${PROJECT_NAME} PRIVATE
        cxx_variadic_templates
        cxx_nullptr
        cxx_lambdas
    )
    add_test("${ARGV0}" ${PROJECT_NAME})
    target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
    target_include_directories(${PROJECT_NAME} PRIVATE "${LIBS_DIR}/test_framework")
    target_include_directories(${PROJECT_NAME} PRIVATE "${TEST_DIR}/mocks")
    target_include_directories(${PROJECT_NAME} PRIVATE ".")
endfunction()

#==========================================================================================

#Debug
create_unit_test("debug_log_test" "Debug/Logger.cpp")

#Memory
create_unit_test("default_ptr_test")
create_unit_test("lazy_ptr_test")
create_unit_test("static_pool_test")
create_unit_test("dynamic_pool_test")
#...

#Graphics
create_unit_test("graphics_shaderprogram_test" "Graphics/ShaderProgram.cpp")
create_unit_test("graphics_color_test" "Graphics/Color.cpp")
#...

project("GDK")
add_library (${PROJECT_NAME} STATIC 
    "Graphics/ShaderProgram.cpp"
)
target_compile_features(${PROJECT_NAME} PRIVATE
    cxx_variadic_templates
    cxx_nullptr
    cxx_lambdas
)
target_include_directories(${PROJECT_NAME} PRIVATE ".")
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE "${LIBS_DIR}/glew/include/GL")
    
#...
