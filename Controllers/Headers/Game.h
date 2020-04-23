//
// Created by cliff on 08/03/2020.
//

/**
 * Game class
 * Method to run game
 */
#ifndef PROJECT_GAME_H
#define PROJECT_GAME_H


#include "../../Factories/AbstractFactory.h"
#include "PlayerManager.h"
#include "EnemyManager.h"
#include "BonusManager.h"
#include "ConfigHandler.h"

namespace GameNs{
    class Game {
    public:
        static Game* getInstance();
        static Game* getInstance(AbstractFactory *AF);
        void run();
        ~Game();

    private:
        static Game* m_instance;
        Game(AbstractFactory *AF);
        Game();

        Timer* m_timer=nullptr;
        PlayerManager* m_playerManager = nullptr;
        EnemyManager* m_enemyManager  = nullptr;
        BulletManager* m_bulletManager = nullptr;
        BonusManager* m_bonusManager = nullptr;
        Score* m_playerScore = nullptr;
        CollisionDetector* m_collisionDetector= nullptr;
        AbstractFactory* m_factory = nullptr;
        ConfigHandler* m_configHandler= nullptr;
        int m_screenHeight = 0;
        int m_screenWidth = 0;
    };

}


#endif //PROJECT_GAME_H
