cmake_minimum_required(VERSION 3.15)

project(WeatherFromWebCpp)

option(WFW_COMPILE_EXAMPLE "Compile example project" OFF)

add_subdirectory(WeatherFromWeb)

if(WFW_COMPILE_EXAMPLE)
    add_subdirectory(example)
    message(STATUS "Compiling example project")
else()
    message(STATUS "NOT compiling example project")
endif()
