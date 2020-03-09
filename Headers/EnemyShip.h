//
// Created by cliff on 08/03/2020.
//

#ifndef PROJECT_ENEMYSHIP_H
#define PROJECT_ENEMYSHIP_H


#include "Ship.h"

class EnemyShip: public Ship {
public:
    void moveLeft();
    void moveRight();
};


#endif //PROJECT_ENEMYSHIP_H
