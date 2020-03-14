//
// Created by cliff on 08/03/2020.
//

#ifndef PROJECT_ENEMYSHIP_H
#define PROJECT_ENEMYSHIP_H


#include "Ship.h"

class EnemyShip: public Ship {
public:
    EnemyShip();
    virtual int getXPosition()=0;
    virtual int getYPosition()=0;
    virtual void render() = 0;
    virtual void close() = 0;
};


#endif //PROJECT_ENEMYSHIP_H
