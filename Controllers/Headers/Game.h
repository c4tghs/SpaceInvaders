//
// Created by cliff on 08/03/2020.
//
#pragma once


#ifndef PROJECT_GAME_H
#define PROJECT_GAME_H


#include "../../Factories/AbstractFactory.h"
#include "PlayerManager.h"
#include "EnemyManager.h"
#include "BonusManager.h"
#include "ConfigHandler.h"
#include "LevelController.h"

namespace GameNs{
    class Game {
    public:
        static Game* getInstance();
        static Game* getInstance(AbstractFactory *AF);
        void run();
        void setLeveLCompleted(bool isCompleted);
        ~Game();

    private:
        static Game* m_instance;
        Game();
        Game(AbstractFactory *AF);
        Background* m_background= nullptr;
        Timer* m_timer=nullptr;
        CollisionDetector* m_collisionDetector= nullptr;
        AbstractFactory* m_factory = nullptr;
        ConfigHandler* m_configHandler= nullptr;
        LevelController* m_levelController= nullptr;
        int m_currentGameLevel=1;
        bool m_levelCompleted=false;
        int m_screenHeight = 0;
        int m_screenWidth = 0;
    };



}


#endif //PROJECT_GAME_H
