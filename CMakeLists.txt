cmake_minimum_required(VERSION 3.12)

project(narvos)

set(EXECUTABLE_NAME "narvos")

file(GLOB_RECURSE NARVOS_SRC
    ${CMAKE_SOURCE_DIR}/src/*.cpp)

include_directories(
    ${CMAKE_SOURCE_DIR}/include)

add_executable(${EXECUTABLE_NAME} ${NARVOS_SRC})

