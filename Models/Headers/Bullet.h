/**
 * Bullet class
 */
#ifndef PROJECT_BULLET_H
#define PROJECT_BULLET_H

#include "Entity.h"

namespace Abstract
{
    class Bullet:public Entity {
    public:
        Bullet(int xPos, int yPos, int width, int height);
        virtual ~Bullet();
        virtual void render()=0;
    };
}



#endif //PROJECT_BULLET_H
