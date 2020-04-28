#pragma once
#ifndef PROJECT_LEVELCONTROLLER_H
#define PROJECT_LEVELCONTROLLER_H

#include "../../Factories/AbstractFactory.h"
#include "PlayerManager.h"
#include "BonusManager.h"
#include "EnemyManager.h"

namespace GameNs{
    class LevelController {
        public:
            LevelController();
            ~LevelController();
            LevelController(AbstractFactory *AF, Timer *timer, CollisionDetector *collisionDetector,ConfigHandler *configHandler);
            void createObjects();
            void setLevel(int level);
            void clean();
            void startLevel();
            void update();

        private:
            AbstractFactory* m_factory= nullptr;
            PlayerManager* m_playerManager= nullptr;
            BulletManager* m_bulletManager= nullptr;
            BonusManager* m_bonusManager= nullptr;
            ConfigHandler* m_configHandler= nullptr;
            EnemyManager* m_enemyManager= nullptr;
            CollisionDetector* m_collisionDetector= nullptr;
            Score* m_playerScore= nullptr;
            Timer* m_timer= nullptr;
            int m_playerCurrentScore = 0;
            int m_currentLevel=0;
    };
}



#endif //PROJECT_LEVELCONTROLLER_H
