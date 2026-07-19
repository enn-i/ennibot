add_executable(Ennibot ennibot.c economy.c embeds.c utils_ennibot.c wrappers.c)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
target_link_libraries(
  Ennibot
  PUBLIC core
  PUBLIC lib
  PUBLIC generated
  PUBLIC reflect-c
  PUBLIC include)

