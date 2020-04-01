cmake_minimum_required(VERSION 3.15)
project(Project)

set(CMAKE_MODULE_PATH  ${PROJECT_SOURCE_DIR/cmake})

set(CMAKE_CXX_STANDARD 14)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
add_executable(Project main.cpp Models/Headers/Ship.h Models/CPP-Files/PlayerShip.cpp Models/Headers/PlayerShip.h Models/CPP-Files/EnemyShip.cpp Models/Headers/EnemyShip.h Factories/SDLFactory.cpp Factories/SDLFactory.h Controllers/Headers/TextureManager.h Controllers/CPP-Files/TextureManager.cpp Factories/AbstractFactory.h Controllers/CPP-Files/Game.cpp Controllers/Headers/Game.h SDL/CPP-Files/SDLPlayerShip.cpp SDL/Headers/SDLPlayerShip.h SDL/CPP-Files/SDLEnemyShip.cpp SDL/Headers/SDLEnemyShip.h SDL/CPP-Files/SDLKeyStates.cpp SDL/Headers/SDLKeyStates.h Models/CPP-Files/Background.cpp Models/Headers/Background.h SDL/CPP-Files/SDLBackground.cpp SDL/Headers/SDLBackground.h Models/CPP-Files/Bullet.cpp Models/Headers/Bullet.h SDL/CPP-Files/SDLBullet.cpp SDL/Headers/SDLBullet.h SDL/CPP-Files/SDLTimer.cpp SDL/Headers/SDLTimer.h Models/Headers/Timer.h Controllers/CPP-Files/EnemyManager.cpp Controllers/Headers/EnemyManager.h Controllers/CPP-Files/PlayerManager.cpp Controllers/Headers/PlayerManager.h)
target_link_libraries(Project ${SDL2_LIBRARY} -lmingw32 -lSDL2main -lSDL2 -lSDL2_image)