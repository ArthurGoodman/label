cmake_minimum_required(VERSION 3.0)
project(label)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

set(LABEL label)

file(GLOB_RECURSE SOURCES src/*.cpp src/*.hpp)
add_library(${LABEL} ${SOURCES})
set_target_properties(${LABEL} PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(${LABEL}
    PUBLIC src)

add_subdirectory(test)
