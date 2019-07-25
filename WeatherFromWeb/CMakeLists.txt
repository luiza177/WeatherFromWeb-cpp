cmake_minimum_required(VERSION 3.15)

set(this WeatherFromWeb)
project(${this})

set(WFW_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(cpr)
include_directories(
    ${CPR_INCLUDE_DIRS}
    ${WFW_INCLUDE_DIR}
)

add_library(${this} src/WeatherFromWeb.cpp)
target_link_libraries(${this} ${CPR_LIBRARIES})
target_include_directories(${this} PUBLIC ${WFW_INCLUDE_DIR})