cmake_minimum_required(VERSION 3.0)
project(label)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

set(LABEL label)

add_library(${LABEL} INTERFACE)
target_include_directories(${LABEL} INTERFACE src)

if(${BUILD_TESTS})
add_subdirectory(test)
endif()
