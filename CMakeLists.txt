cmake_minimum_required(VERSION 4.0)


add_subdirectory("third-party/sfml")

set(src "main/main.cpp")
project(rpg-framework)
add_executable(rpg-framework "main/main.cpp")
target_link_libraries(rpg-framework PRIVATE SFML::Graphics)