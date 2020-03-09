//
// Created by cliff on 08/03/2020.
//

#ifndef PROJECT_ABSTRACTFACTORY_H
#define PROJECT_ABSTRACTFACTORY_H


#include "../Headers/Ship.h"

class AbstractFactory {
public:
    virtual Ship* createPlayerShip()=0;
    virtual Ship* createEnemyShip()=0;
};


#endif //PROJECT_ABSTRACTFACTORY_H
