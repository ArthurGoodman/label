set(LABEL_TEST label_test)

file(GLOB_RECURSE SOURCES src/*.cpp)
add_executable(${LABEL_TEST} ${SOURCES})

target_link_libraries(${LABEL_TEST} ${LABEL})

target_include_directories(${LABEL_TEST}
    PRIVATE ${PROJECT_SOURCE_DIR}/ext/rapidjson/include)
