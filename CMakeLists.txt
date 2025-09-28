cmake_minimum_required(VERSION 4.0)


add_subdirectory("third-party/sfml")

set(src "main/main.cpp" "main/game.cpp" "battle/Encounter.cpp" "entities/entity.cpp" "graphics/AnimationManager.cpp" "graphics/background.cpp" "graphics/sprite.cpp" "world/world.cpp")
project(rpg-framework)
set(CMAKE_CXX_STANDARD 20)
add_executable(rpg-framework ${src})
target_link_libraries(rpg-framework PRIVATE SFML::Graphics)
target_include_directories(rpg-framework PRIVATE "third-party/sfml/include")