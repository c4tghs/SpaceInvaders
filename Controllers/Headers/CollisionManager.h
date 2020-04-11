//
// Created by cliff on 04/04/2020.
//

#ifndef PROJECT_COLLISIONMANAGER_H
#define PROJECT_COLLISIONMANAGER_H

#include <vector>
#include "../../Models/Headers/Bullet.h"

namespace GameNs
{
    class CollisionManager {
        public:
        static CollisionManager* getInstance();
        static bool checkCollision(Bullet * bullet, int xPos, int yPos, int width, int height);
    private:
        static CollisionManager* m_instance;
        CollisionManager();
    };
}



#endif //PROJECT_COLLISIONMANAGER_H
