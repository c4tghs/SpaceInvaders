//
// Created by cliff on 08/03/2020.
//

#ifndef PROJECT_ENEMYSHIP_H
#define PROJECT_ENEMYSHIP_H


#include "Ship.h"
namespace GameNs
{
    class EnemyShip: public Ship {
    public:
        EnemyShip();
        EnemyShip(int xPos, int yPos, int width, int height);
        virtual void render() = 0;
        virtual void close() = 0;
        virtual int getMoveDirection()=0;
        virtual void setMoveDirection(int direction)=0;
    };
}



#endif //PROJECT_ENEMYSHIP_H
