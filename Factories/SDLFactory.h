//
// Created by cliff on 08/03/2020.
//

#ifndef PROJECT_SDLFACTORY_H
#define PROJECT_SDLFACTORY_H


#include "AbstractFactory.h"
#include "../Headers/PlayerShip.h"
#include "../Headers/EnemyShip.h"

class SDLFactory:public AbstractFactory {
public:
     Ship* createPlayerShip(){
         return new PlayerShip();
     };
     Ship* createEnemyShip(){
         return new EnemyShip();
     };
};


#endif //PROJECT_SDLFACTORY_H
