cmake_minimum_required(VERSION 3.15)
project(Ennibot
	LANGUAGES C)
add_executable(ennibot ennibot.c)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
target_include_directories(ennibot src)

