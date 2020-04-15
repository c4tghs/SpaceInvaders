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

namespace GameNs{
    class Game {
    public:
        static Game* getInstance();
        static Game* getInstance(AbstractFactory *AF);

        void run();
        void initialise();

    private:
        static Game* m_instance;
        Game(AbstractFactory *AF);
        Game();
        Timer* m_timer;
        PlayerManager* m_playerManager = nullptr;
        EnemyManager* m_enemyManager  = nullptr;
        BulletManager* m_bulletManager = nullptr;
        BonusManager* m_bonusManager = nullptr;
        PlayerLife* m_playerLife = nullptr;
        Score* m_playerScore = nullptr;
        AbstractFactory* m_factory;
        const int m_screenHeight = 720 ;
        const int m_screenWidth = 1280;
    };

}


#endif //PROJECT_GAME_H
