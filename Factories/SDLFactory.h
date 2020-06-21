#ifndef PROJECT_SDLFACTORY_H
#define PROJECT_SDLFACTORY_H

#include "Factory.h"

namespace SDL
{
    class SDLFactory:public Abstract::Factory {
    public:
        SDLFactory();
        ~SDLFactory()override;
        Abstract::Controller* createController() override ;
        Abstract::Timer* createTimer() override;
        Abstract::PlayerShip* createPlayerShip(double xPos, double yPos, double width, double height, Abstract::Window* window) override;
        Abstract::Window* createWindow(const char* title,int width, int height)override ;
        Abstract::EnemyShip* createEnemyShip(double xPos, double yPos, double width, double height, Abstract::Window *window, Enemy_type type) override;
        Abstract::Bullet* createBullet(double xPos, double yPos, double width, double height, Abstract::Window *window, Bullet_type type) override;
        Abstract::Bonus* createBonus(double xPos, double yPos, double width, double height, Abstract::Window *window, Bonus_type type) override;
    };
}



#endif //PROJECT_SDLFACTORY_H
