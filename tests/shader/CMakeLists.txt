cmake_minimum_required (VERSION 3.1)

set (TARGET_NAME "test_shader")

file (GLOB MAIN_SRC
        *.cpp
        )

file (GLOB MAIN_HEADERS
        *.h
        )

add_executable(${TARGET_NAME} MAIN_SRC)      