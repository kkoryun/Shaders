cmake_minimum_required (VERSION 3.1)

set (TARGET_NAME "glslshader")

file (GLOB MAIN_SRC
        shaders/*.cpp
        )

file (GLOB MAIN_HEADERS
        shaders/*.h
        )

add_library(${TARGET_NAME} SHARED ${MAIN_SRC} ${MAIN_HEADERS})
set_target_lib_version(${TARGET_NAME})
set_compile_flags(${TARGET_NAME})