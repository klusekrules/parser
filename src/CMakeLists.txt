project(MyHello CXX)
cmake_minimum_required(VERSION 2.8)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

file(GLOB_RECURSE PARSER_SOURCES "*.cpp")
file(GLOB_RECURSE PARSER_HEADERS "*.h")

set (PARSER_INCLUDE_DIRS "")
foreach (_headerFile ${PARSER_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND PARSER_INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES PARSER_INCLUDE_DIRS)

add_library(parser ${PARSER_SOURCES})
target_include_directories(parser PRIVATE ${PARSER_INCLUDE_DIRS})