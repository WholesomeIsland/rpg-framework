cmake_minimum_required(VERSION 4.0)


add_subdirectory("third-party/sfml")

set(src "main/main.cpp" "battle/Encounter.cpp" "entities/entity.cpp" "graphics/AnimationManager.cpp" "graphics/background.cpp" "graphics/sprite.cpp" "world/world.cpp")
project(rpg-framework)
add_executable(rpg-framework ${src})
target_link_libraries(rpg-framework PRIVATE SFML::Graphics)