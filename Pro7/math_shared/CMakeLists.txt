add_library(mymath_shared SHARED math.cpp)

target_include_directories(mymath_shared PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(mymath_shared PROPERTIES
    PREFIX "custom_"
)

if(WIN32)
  set_target_properties(mymath_shared PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()