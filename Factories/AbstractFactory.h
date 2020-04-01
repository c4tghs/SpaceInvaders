//
// Created by cliff on 08/03/2020.
//

#ifndef PROJECT_ABSTRACTFACTORY_H
#define PROJECT_ABSTRACTFACTORY_H


#include <string>
#include "../Headers/Ship.h"
#include "../Headers/Background.h"
#include "../Headers/Timer.h"
namespace GameNs{
    class AbstractFactory {
    public:
        virtual Ship* createPlayerShip(std::string playerShipPath)=0;
        virtual Ship *createEnemyShip(std::string enemyShipPath, int xPos, int yPos) =0;
        virtual Background* createBackground()=0;
        virtual void initialise(int windowWidth, int windowHeight)=0;
        virtual void render()=0;
        virtual void close()=0;
        virtual bool getEvents()=0;
    };
}



#endif //PROJECT_ABSTRACTFACTORY_H
