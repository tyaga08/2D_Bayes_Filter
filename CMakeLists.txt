cmake_minimum_required(VERSION 3.5)
project(2D_Bayes_Filter)

IF(NOT CMAKE_BUILD_TYPE)
SET(CMAKE_BUILD_TYPE Debug)
ENDIF()

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

add_compile_options(-std=c++11)

include_directories(dir
${PROJECT_SOURCE_DIR}/
${PROJECT_SOURCE_DIR}/include/
)

add_executable(bayes src/main.cpp)
