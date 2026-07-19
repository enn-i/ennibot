cmake_minimum_required(VERSION 3.15)
project(Ennibot LANGUAGES C)
add_subdirectory(src)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(core STATIC IMPORTED)
set_target_properties(
  core PROPERTIES IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/core/core.a"
                  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/core")
add_library(lib STATIC IMPORTED)
set_target_properties(lib PROPERTIES IMPORTED_LOCATION
                                     "${CMAKE_SOURCE_DIR}/lib/lib.a")
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
target_link_libraries(include INTERFACE core generated reflect-c)
