cmake_minimum_required(VERSION 3.15)
project(Project)

set(CMAKE_MODULE_PATH  ${PROJECT_SOURCE_DIR/cmake})

set(CMAKE_CXX_STANDARD 14)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
add_executable(Project CPP-Files/main.cpp CPP-Files/Ship.cpp Headers/Ship.h CPP-Files/PlayerShip.cpp Headers/PlayerShip.h CPP-Files/EnemyShip.cpp Headers/EnemyShip.h CPP-Files/Graphics.cpp Headers/Graphics.h CPP-Files/ObjectFactory.cpp Headers/ObjectFactory.h Headers/TextureManager.h CPP-Files/TextureManager.cpp Factories/AbstractFactory.h Factories/SDLFactory.h CPP-Files/Game.cpp Headers/Game.h)
target_link_libraries(Project ${SDL2_LIBRARY} -lmingw32 -lSDL2main -lSDL2 -lSDL2_image)