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
        Models/CPP-Files/Bonus.cpp
        Models/Headers/Bonus.h
        Models/CPP-Files/RandomNumber.cpp
        Models/Headers/RandomNumber.h
        SDL/CPP-Files/TextureManager.cpp
        SDL/Headers/TextureManager.h
        Models/Headers/Window.h
        Models/CPP-Files/Window.cpp
        SDL/CPP-Files/TextManager.cpp
        SDL/Headers/TextManager.h

        SDL/CPP-Files/SDLTimer.cpp
        SDL/Headers/SDLTimer.h
        SDL/CPP-Files/SDLWindow.cpp
        SDL/Headers/SDLWindow.h
        SDL/CPP-Files/SDLPlayerShip.cpp
        SDL/Headers/SDLPlayerShip.h
        SDL/CPP-Files/SDLEnemyShip.cpp
        SDL/Headers/SDLEnemyShip.h
        SDL/CPP-Files/SDLBullet.cpp
        SDL/Headers/SDLBullet.h


        Constants.h
        Constants.cpp
        Configuration.cpp
        Configuration.h

        Controllers/Headers/Controller.h
        Controllers/CPP-Files/Controller.cpp
        Controllers/CPP-Files/SDLController.cpp
        Controllers/Headers/SDLController.h

        )

target_link_libraries(SpaceInvaders ${SDL2_LIBRARY} -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer)