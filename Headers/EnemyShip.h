//
// Created by cliff on 08/03/2020.
//

#ifndef PROJECT_ENEMYSHIP_H
#define PROJECT_ENEMYSHIP_H


#include <vector>
#include "Ship.h"

class EnemyShip: public Ship {
public:
    EnemyShip();
    virtual int getXPosition()=0;
    virtual int getYPosition()=0;
    virtual void setXPosition(int x)=0;
    virtual void setYPosition(int y)=0;
    virtual void render() = 0;
    virtual void close() = 0;
    virtual void moveEnemyShip()=0;
    virtual bool hitBoundary()=0;
    virtual int getMoveDirection()=0;
    virtual void setMoveDirection(int direction)=0;
};


#endif //PROJECT_ENEMYSHIP_H
