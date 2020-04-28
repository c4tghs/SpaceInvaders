cmake_minimum_required(VERSION 3.15)
project(SpaceInvaders)

set(CMAKE_MODULE_PATH  ${PROJECT_SOURCE_DIR/cmake})

set(CMAKE_CXX_STANDARD 14)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
add_executable(SpaceInvaders
        main.cpp

        Factories/SDLFactory.cpp
        Factories/SDLFactory.h
        Factories/AbstractFactory.h

        Models/Headers/PlayerShip.h
        Models/CPP-Files/PlayerShip.cpp
        Models/CPP-Files/EnemyShip.cpp
        Models/Headers/EnemyShip.h
        Models/CPP-Files/Background.cpp
        Models/Headers/Background.h
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

        Controllers/Headers/TextureManager.h
        Controllers/CPP-Files/TextureManager.cpp
        Controllers/CPP-Files/ConfigHandler.cpp
        Controllers/Headers/ConfigHandler.h
        Controllers/CPP-Files/LevelController.cpp
        Controllers/Headers/LevelController.h
        Controllers/CPP-Files/Game.cpp
        Controllers/Headers/Game.h
        Controllers/CPP-Files/EnemyManager.cpp
        Controllers/Headers/EnemyManager.h
        Controllers/CPP-Files/PlayerManager.cpp
        Controllers/Headers/PlayerManager.h
        Controllers/CPP-Files/BulletManager.cpp
        Controllers/Headers/BulletManager.h
        Controllers/CPP-Files/CollisionDetector.cpp
        Controllers/Headers/CollisionDetector.h
        Controllers/CPP-Files/TextManager.cpp
        Controllers/Headers/TextManager.h
        Controllers/CPP-Files/BonusManager.cpp
        Controllers/Headers/BonusManager.h


        SDL/CPP-Files/SDLPlayerShip.cpp
        SDL/Headers/SDLPlayerShip.h
        SDL/CPP-Files/SDLEnemyShip.cpp
        SDL/Headers/SDLEnemyShip.h
        SDL/CPP-Files/SDLKeyStates.cpp
        SDL/Headers/SDLKeyStates.h
        SDL/CPP-Files/SDLBackground.cpp
        SDL/Headers/SDLBackground.h
        SDL/CPP-Files/SDLBullet.cpp
        SDL/Headers/SDLBullet.h
        SDL/CPP-Files/SDLTimer.cpp
        SDL/Headers/SDLTimer.h
        SDL/CPP-Files/SDLScore.cpp
        SDL/Headers/SDLScore.h
        SDL/CPP-Files/SDLPlayerLife.cpp
        SDL/Headers/SDLPlayerLife.h
        SDL/CPP-Files/SDLBonus.cpp
        SDL/Headers/SDLBonus.h
       )

target_link_libraries(SpaceInvaders ${SDL2_LIBRARY} -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf)