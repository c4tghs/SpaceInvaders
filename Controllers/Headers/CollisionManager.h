//
// Created by cliff on 04/04/2020.
//

#ifndef PROJECT_COLLISIONMANAGER_H
#define PROJECT_COLLISIONMANAGER_H

#include <vector>
#include "../../Models/Headers/Bullet.h"
#include "../../Models/Headers/Bonus.h"
#include "../../Models/Headers/PlayerShip.h"

namespace GameNs
{
    class CollisionManager {
        public:
        static CollisionManager* getInstance();
        static bool checkBulletCollision(Bullet * bullet, int xPos, int yPos, int width, int height);
        static bool checkBonusCollision(Bonus *bonus, PlayerShip *playerShip);
        static bool twoBulletsCollision(Bullet* playerBullet, Bullet * enemyBullet);
    private:
        static CollisionManager* m_instance;
        CollisionManager();
    };
}



#endif //PROJECT_COLLISIONMANAGER_H
