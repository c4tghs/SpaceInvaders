/**
 * EnemyManager class
 * Method for managing enemies
 */

#pragma once

#ifndef PROJECT_ENEMYMANAGER_H
#define PROJECT_ENEMYMANAGER_H


#include "../../Factories/AbstractFactory.h"
#include "../../SDL/Headers/SDLTimer.h"
#include "CollisionDetector.h"
#include "BulletManager.h"
#include "ConfigHandler.h"
#include <vector>
#include <random>

namespace GameNs
{
    class EnemyManager {
    public:
        EnemyManager();
        EnemyManager(AbstractFactory *AF, Timer *timer, CollisionDetector *collisionDetector,
                     ConfigHandler *configHandler,BulletManager *bulletManager, Score *score);
        ~EnemyManager();
        void createEnemies(int number);
        void update();
        void moveEnemies();
        bool checkEnemyBoundaries();
        void enemyShoot();
        void createBullets();

    private:
        AbstractFactory* m_factory=nullptr;
        std::vector<EnemyShip *> m_enemyShips;
        Timer* m_timer=nullptr;
        BulletManager* m_bulletManager= nullptr;
        CollisionDetector* m_collisionDetector= nullptr;
        ConfigHandler* m_configHandler= nullptr;
        int m_screenWidth=0;
        int m_screenHeight=0;
        double m_nextMissile=0.0;
        std::vector<Bullet*> m_bullets;
        Score* m_score= nullptr;
        int m_randomId=0;
    };
}



#endif //PROJECT_ENEMYMANAGER_H
