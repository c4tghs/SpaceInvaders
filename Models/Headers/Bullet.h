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
        Bullet(double xPos, double yPos, double width, double height);
        virtual ~Bullet();
        virtual void render()=0;
    };
}



#endif //PROJECT_BULLET_H
