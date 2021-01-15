cmake_minimum_required(VERSION 3.12)

project(narvos)

set(EXECUTABLE_NAME "narvos")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

file(GLOB_RECURSE NARVOS_SRC
    ${CMAKE_SOURCE_DIR}/src/*.c)

include_directories(
    ${CMAKE_SOURCE_DIR}/include)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

find_package(SDL2_image REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

add_executable(${EXECUTABLE_NAME} ${NARVOS_SRC})
target_link_libraries(${EXECUTABLE_NAME} ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

