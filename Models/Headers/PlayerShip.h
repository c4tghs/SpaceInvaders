//
// Created by cliff on 08/03/2020.
//

#ifndef PROJECT_PLAYERSHIP_H
#define PROJECT_PLAYERSHIP_H


#include "Ship.h"
namespace GameNs
{
    class PlayerShip: public Ship {
    public:
        PlayerShip();
        PlayerShip(int xPos, int yPos, int width, int height);
        virtual void render() = 0;
        virtual void close() = 0;
        int getMoveDirection();
        void setMoveDirection(int direction);
    };

}


#endif //PROJECT_PLAYERSHIP_H
