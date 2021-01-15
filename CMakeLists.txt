cmake_minimum_required(VERSION 3.12)

project(narvos)

set(EXECUTABLE_NAME "narvos")

file(GLOB_RECURSE NARVOS_SRC
    ${CMAKE_SOURCE_DIR}/src/*.c)

include_directories(
    ${CMAKE_SOURCE_DIR}/include)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(${EXECUTABLE_NAME} ${NARVOS_SRC})
target_link_libraries(${EXECUTABLE_NAME} ${SDL2_LIBRARIES})

