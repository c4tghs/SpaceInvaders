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
        Abstract::EnemyShip* createEnemyShip(double xPos, double yPos, double width, double height, Abstract::Window *window, ENEMY_TYPE type) override;
        Abstract::Bullet* createBullet(double xPos, double yPos, double width, double height, Abstract::Window *window, BULLET_TYPE type) override;
        Abstract::Bonus* createBonus(double xPos, double yPos, double width, double height, Abstract::Window *window, BONUS_TYPE type) override;
    };
}



#endif //PROJECT_SDLFACTORY_H
