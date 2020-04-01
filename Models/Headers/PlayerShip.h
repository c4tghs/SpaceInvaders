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

        virtual int getXPosition()=0;
        virtual int getYPosition()=0;
        virtual void setXPosition(int x)=0;
        virtual void setYPosition(int y)=0;
        virtual void render() = 0;
        virtual void close() = 0;
        int getMoveDirection();
        void setMoveDirection(int direction);



    };

}


#endif //PROJECT_PLAYERSHIP_H