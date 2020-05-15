cmake_minimum_required(VERSION 3.15)
project(SpaceInvaders)

set(CMAKE_MODULE_PATH  ${PROJECT_SOURCE_DIR}/cmake)

set(CMAKE_CXX_STANDARD 14)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
add_executable(SpaceInvaders
        main.cpp

        Game.cpp
        Game.h

        Factories/SDLFactory.cpp
        Factories/SDLFactory.h
        Factories/Factory.h

        Models/Headers/PlayerShip.h
        Models/CPP-Files/PlayerShip.cpp
        Models/CPP-Files/EnemyShip.cpp
        Models/Headers/EnemyShip.h
        Models/CPP-Files/Bullet.cpp
        Models/Headers/Bullet.h
        Models/Headers/Timer.h
        Models/CPP-Files/Entity.cpp
        Models/Headers/Entity.h
        Models/CPP-Files/Score.cpp
        Models/Headers/Score.h
        Models/CPP-Files/PlayerLife.cpp
        Models/Headers/PlayerLife.h
        Models/CPP-Files/Bonus.cpp
        Models/Headers/Bonus.h
        Models/CPP-Files/RandomNumber.cpp
        Models/Headers/RandomNumber.h
        Models/CPP-Files/TextureManager.cpp
        Models/Headers/TextureManager.h
        Models/Headers/Window.h
        Models/CPP-Files/Window.cpp

        SDL/CPP-Files/SDLTimer.cpp
        SDL/Headers/SDLTimer.h
        SDL/CPP-Files/SDLWindow.cpp
        SDL/Headers/SDLWindow.h
        SDL/CPP-Files/SDLPlayerShip.cpp
        SDL/Headers/SDLPlayerShip.h
        SDL/CPP-Files/SDLEnemyShip.cpp
        SDL/Headers/SDLEnemyShip.h


        Enums.h

        Controllers/Headers/Controller.h
        Controllers/CPP-Files/Controller.cpp
        Controllers/CPP-Files/SDLController.cpp
        Controllers/Headers/SDLController.h

        EntityControllers/CPP-Files/EnemyShipController.cpp
        EntityControllers/Headers/EnemyShipController.h
        EntityControllers/CPP-Files/PlayerShipController.cpp
        EntityControllers/Headers/PlayerShipController.h
        TranslateRelative.cpp TranslateRelative.h)

target_link_libraries(SpaceInvaders ${SDL2_LIBRARY} -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer)