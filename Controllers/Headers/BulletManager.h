/**
 * BulletManager class
 * Methods to managing a bullet
 */

#ifndef PROJECT_BULLETMANAGER_H
#define PROJECT_BULLETMANAGER_H

#include <vector>
#include "../../Factories/AbstractFactory.h"
#include "../../SDL/Headers/SDLTimer.h"
#include "CollisionManager.h"

namespace GameNs{
    class BulletManager {
    public:
        static BulletManager* getInstance();
        static BulletManager* getInstance(Bullet* bullet,std::string bulletPath,Timer* timer,int screenHeight);
        void update();
        void moveBullet();
        void setBullet(Bullet* bullet);
        void checkBulletBounds();
        void setMoveDirection(int direction);
        bool getBulletFired();
        void setBulletFired(bool isFired);
        bool checkPlayerCollisions();
        void setEnemyShip(std::vector<Ship *> enemyShips);


    private:
        static BulletManager* m_instance;
        BulletManager();
        BulletManager(Bullet* bullet,std::string bulletPath,Timer* timer,int screenHeight);

        bool m_bulletFired;
        int m_moveDirection;
        Timer* m_timer;
        Bullet* m_bullet;
        std::string m_bulletPath;
        int m_screenHeight;
        CollisionManager* m_collisionManager;
        std::vector<Ship *> m_enemyShips;


    };
}



#endif //PROJECT_BULLETMANAGER_H
