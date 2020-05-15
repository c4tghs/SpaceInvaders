/**
 * Header for abstract factory
 */

#ifndef PROJECT_ABSTRACTFACTORY_H
#define PROJECT_ABSTRACTFACTORY_H


#include <string>
#include "../Controllers/Headers/Controller.h"
#include "../Models/Headers/Timer.h"
#include "../Models/Headers/PlayerShip.h"
#include "../Models/Headers/Window.h"
#include "../Models/Headers/EnemyShip.h"


namespace Abstract{
    class Factory {
    public:
        virtual Abstract::PlayerShip* createPlayerShip(double xPos, double yPos, double width, double height, Window* window) =0;
        virtual Abstract::EnemyShip* createEnemyShip(double xPos, double yPos, double width, double height, Window* window) =0;
       /* virtual Background* createBackground()=0;

        virtual Bullet *createBullet(int xPos, int yPos, int width, int height) =0;
        virtual Score* createScore()=0;
        virtual PlayerLife* createPlayerLife()=0;
        virtual Bonus *createBonus(int xPos, int yPos, int width, int height) =0;*/
        virtual Abstract::Window* createWindow(const char* title,int width, int height)=0;
        virtual Abstract::Timer* createTimer()=0;
        virtual Abstract::Controller* createController()=0;
        //virtual void render()=0;
        virtual ~Factory()=default;
    };
}



#endif //PROJECT_ABSTRACTFACTORY_H
