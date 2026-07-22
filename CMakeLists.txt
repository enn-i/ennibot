cmake_minimum_required(VERSION 3.15)
project(Ennibot LANGUAGES C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(core STATIC IMPORTED)
set_target_properties(
  core PROPERTIES IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/core/core.a"
                  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/core")
add_library(generated STATIC IMPORTED)
set_target_properties(
  generated
  PROPERTIES IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/generated/generated.a"
             INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/generated")
add_library(reflect-c STATIC IMPORTED)
set_target_properties(
  reflect-c
  PROPERTIES IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/reflect-c/reflect-c.a"
             INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/reflect-c")
add_library(include INTERFACE)
set_target_properties(include PROPERTIES INTERFACE_INCLUDE_DIRECTORIES
                                         "${CMAKE_SOURCE_DIR}/include")

find_package(CURL REQUIRED)
add_library(lib STATIC IMPORTED GLOBAL)
set_target_properties(
  lib PROPERTIES IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/lib/libdiscord.a"
  INTERFACE_LINK_LIBRARIES "CURL::libcurl")

target_link_libraries(include INTERFACE core generated reflect-c)
target_link_libraries(core INTERFACE generated reflect-c include)
target_link_libraries(generated INTERFACE core reflect-c include)
target_link_libraries(reflect-c INTERFACE core generated include)
add_subdirectory(src)
