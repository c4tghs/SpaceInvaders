//
// Created by cliff on 04/04/2020.
//

#ifndef PROJECT_COLLISIONDETECTOR_H
#define PROJECT_COLLISIONDETECTOR_H

#include <vector>
#include "../../Models/Headers/Bullet.h"
#include "../../Models/Headers/Bonus.h"
#include "../../Models/Headers/PlayerShip.h"

namespace GameNs
{
    class CollisionDetector {
        public:
            CollisionDetector();
            bool checkBulletCollision(Bullet* bullet, int xPos, int yPos, int width, int height);
            bool checkBonusCollision(Bonus* bonus, PlayerShip* playerShip);
            bool twoBulletsCollision(Bullet* playerBullet, Bullet* enemyBullet);


    };
}



#endif //PROJECT_COLLISIONDETECTOR_H
