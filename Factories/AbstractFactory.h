/**
 * Header for abstract factory
 */

#ifndef PROJECT_ABSTRACTFACTORY_H
#define PROJECT_ABSTRACTFACTORY_H


#include <string>
#include "../Models/Headers/Ship.h"
#include "../Models/Headers/Background.h"
#include "../Models/Headers/Timer.h"
#include "../Models/Headers/Bullet.h"

namespace GameNs{
    class AbstractFactory {
    public:
        virtual Ship* createPlayerShip(std::string playerShipPath)=0;
        virtual Ship *createEnemyShip(std::string enemyShipPath, int xPos, int yPos) =0;
        virtual Background* createBackground()=0;
        virtual Timer* createTimer()=0;
        virtual Bullet* createBullet(std::string bulletPath, int xPos, int yPos)=0;
        virtual void initialise(int windowWidth, int windowHeight)=0;
        virtual void render()=0;
        virtual void close()=0;
        virtual bool getRunningState()=0;
    };
}



#endif //PROJECT_ABSTRACTFACTORY_H
