cmake_minimum_required(VERSION 3.1)

# Compiler
SET(CMAKE_C_COMPILER gcc)
SET(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 17)

# Project
project(BomberMan)

# Define SFML
set(SFML_DIR "D:/Libraries/SFML/SFML-2.5.1-64/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)

# Use static libraries if required
# set(SFML_STATIC_LIBRARIES TRUE)

# Executable
add_executable(BomberMan main.cpp Includes/Tile.h Includes/TileType.h Source/Tile.cpp Includes/Game.h Includes/Spritemap.h Source/Spritemap.cpp Includes/GraphicsEntity.h Source/GraphicsEntity.cpp Includes/Player.h Source/Player.cpp Source/Game.cpp)

# Link libraries
target_link_libraries(BomberMan sfml-system sfml-window sfml-graphics sfml-audio)