cmake_minimum_required(VERSION 3.30)
project(ul2.4 C)

set(CMAKE_C_STANDARD 11)

find_package(SDL2 REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)

add_executable(ul2.4 main.c)
target_link_libraries(ul2.4 PRIVATE SDL2::SDL2main SDL2::SDL2 SDL2_mixer::SDL2_mixer SDL2_ttf::SDL2_ttf)




