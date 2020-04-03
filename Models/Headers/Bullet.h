/**
 * Bullet class
 */
#ifndef PROJECT_BULLET_H
#define PROJECT_BULLET_H

#include "Entity.h"

namespace GameNs
{
    class Bullet:public Entity {
    public:
        Bullet();
        Bullet(int xPos, int yPos, int width, int height);
        virtual void close()=0;
        virtual void render()=0;
    };
}



#endif //PROJECT_BULLET_H
