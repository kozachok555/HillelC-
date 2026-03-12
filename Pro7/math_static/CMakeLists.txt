add_library(mymath_static STATIC math.cpp)

target_include_directories(mymath_static PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(mymath_static PROPERTIES
    SUFFIX ".mylib"
)

add_library(mymath::static ALIAS mymath_static)