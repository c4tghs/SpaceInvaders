//
// Created by cliff on 04/03/2020.
//
/**
 * Ship class
 */
#ifndef PROJECT_SHIP_H
#define PROJECT_SHIP_H

#include "Entity.h"

namespace GameNs
{
    class Ship:public Entity {
    public:
        Ship();
        Ship(int xPos, int yPos, int width, int height);

        virtual void render() = 0;
        virtual void close() = 0;
        virtual int getMoveDirection();
        virtual void setMoveDirection(int direction);
    };
}





#endif //PROJECT_SHIP_H
