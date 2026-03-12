cmake_minimum_required(VERSION 3.10)
project(Pro7)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()


add_subdirectory(math_static)
add_subdirectory(math_shared)

add_executable(app_static main.cpp)
target_link_libraries(app_static PRIVATE mymath::static)

add_executable(app_shared main.cpp)
target_link_libraries(app_shared PRIVATE mymath_shared)