/**
 * BulletManager class
 * Methods to managing a bullet
 */

#ifndef PROJECT_BULLETMANAGER_H
#define PROJECT_BULLETMANAGER_H

#include <vector>
#include "../../Factories/AbstractFactory.h"
#include "../../SDL/Headers/SDLTimer.h"
#include "CollisionDetector.h"

namespace GameNs{
    class BulletManager {
    public:
        BulletManager();
        BulletManager(Timer *timer, CollisionDetector *collisionDetector, int screenHeight);
        void update();
        void moveBullet();
        void setPlayerBullet(Bullet* bullet);
        void setEnemyBullet(Bullet* bullet);
        void checkBulletBounds();
        bool isPlayerBulletFired();
        bool isEnemyBulletFired();
        void setPlayerBulletFired(bool isFired);
        void setEnemyBulletFired(bool isFired);
        bool checkPlayerCollisions();
        void setPlayerBulletCollision(bool isCollided);
        void bulletsCollision();
        Bullet* getPlayerBullet();
        Bullet* getEnemyBullet();

    private:
        bool m_playerBulletCollided= false;
        bool m_playerFired = false;
        bool m_enemyFired = false;
        Timer* m_timer= nullptr;
        Bullet* m_playerBullet = nullptr;
        Bullet* m_enemyBullet = nullptr;
        CollisionDetector* m_collisionDetector= nullptr;
        int m_screenHeight = 0;



    };
}



#endif //PROJECT_BULLETMANAGER_H
