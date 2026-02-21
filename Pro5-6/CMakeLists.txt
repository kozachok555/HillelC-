cmake_minimum_required(VERSION 3.10)
project(Pro5-6)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

add_library(mymath_static STATIC math/math.cpp)
target_include_directories(mymath_static PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(mymath_shared SHARED math/math.cpp)
target_include_directories(mymath_shared PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

if(WIN32)
  set_target_properties(mymath_shared PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

add_executable(app_static main.cpp)
target_link_libraries(app_static PRIVATE mymath_static)

add_executable(app_shared main.cpp)
target_link_libraries(app_shared PRIVATE mymath_shared)