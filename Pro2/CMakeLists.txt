cmake_minimum_required(VERSION 3.10)


project(Pro2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

add_executable(Pro2
    main.cpp
    SafeQueue.cpp
    Worker.cpp
    SleepManager.cpp
)