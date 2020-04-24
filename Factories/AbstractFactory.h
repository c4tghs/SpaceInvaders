/**
 * Header for abstract factory
 */

#ifndef PROJECT_ABSTRACTFACTORY_H
#define PROJECT_ABSTRACTFACTORY_H


#include <string>
#include "../Models/Headers/Background.h"
#include "../Models/Headers/Timer.h"
#include "../Models/Headers/Bullet.h"
#include "../Models/Headers/Score.h"
#include "../Models/Headers/PlayerLife.h"
#include "../Models/Headers/PlayerShip.h"
#include "../Models/Headers/EnemyShip.h"
#include "../Models/Headers/Bonus.h"

namespace GameNs{
    class AbstractFactory {
    public:
        virtual PlayerShip* createPlayerShip(std::string playerShipPath)=0;
        virtual EnemyShip *createEnemyShip(std::string enemyShipPath, int xPos, int yPos,GameNs::Timer* timer) =0;
        virtual Background* createBackground()=0;
        virtual Timer* createTimer()=0;
        virtual GameNs::Bullet *createBullet(std::string bulletPath, int xPos, int yPos, int width, int height) =0;
        virtual Score* createScore()=0;
        virtual PlayerLife* createPlayerLife()=0;
        virtual Bonus* createBonus(std::string bonusImagePath, int xPos, int yPos, int width, int height)=0;
        virtual void render()=0;
        virtual bool isRunning()=0;
        virtual void setRunningState(bool state)=0;
        virtual ~AbstractFactory(){};
    };
}



#endif //PROJECT_ABSTRACTFACTORY_H
