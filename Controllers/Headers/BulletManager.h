/**
 * BulletManager class
 * Methods to managing a bullet
 */
#pragma once

#ifndef PROJECT_BULLETMANAGER_H
#define PROJECT_BULLETMANAGER_H

#include <vector>
#include "../../Factories/AbstractFactory.h"
#include "../../SDL/Headers/SDLTimer.h"
#include "CollisionDetector.h"
#include "ConfigHandler.h"

namespace GameNs{
    class BulletManager {
    public:
        BulletManager();
        BulletManager(Timer *timer, CollisionDetector *collisionDetector, ConfigHandler *configHandler);
        void update();
        void moveBullet();
        void setPlayerBullet(Bullet* bullet);
        void setEnemyBullet(Bullet* bullet);
        void checkBulletBounds();
        bool isPlayerBulletInFlight();
        bool isEnemyBulletInFlight();
        void setPlayerBulletInFlight(bool inFlight);
        void setEnemyBulletInFlight(bool isFlight);

        void setPlayerBulletCollision(bool isCollided);
        void bulletsCollision();
        Bullet* getPlayerBullet();
        Bullet* getEnemyBullet();

    private:
        bool m_playerBulletCollided= false;
        bool m_pBulletInFlight = false;
        bool m_eBulletInFlight = false;
        Timer* m_timer= nullptr;
        Bullet* m_playerBullet = nullptr;
        Bullet* m_enemyBullet = nullptr;
        ConfigHandler* m_configHandler= nullptr;
        CollisionDetector* m_collisionDetector= nullptr;
        int m_bulletSpeed=0;
        int m_screenHeight = 0;



    };
}



#endif //PROJECT_BULLETMANAGER_H
