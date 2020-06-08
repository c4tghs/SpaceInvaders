/**
 * Header for SDLfactory
 */

#ifndef PROJECT_SDLFACTORY_H
#define PROJECT_SDLFACTORY_H

#define SCREEN_HEIGHT 720
#define SCREEN_WIDTH 940

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Factory.h"
#include "../Models/Headers/PlayerShip.h"
#include "../Models/Headers/EnemyShip.h"
#include "../Models/Headers/Bullet.h"
#include "../Models/Headers/Timer.h"
#include "../Models/Headers/Bonus.h"
#include "../SDL/Headers/SDLWindow.h"
#include "../SDL/Headers/SDLEnemyShip.h"
//#include "../Controllers/Headers/ConfigHandler.h"

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
        Abstract::EnemyShip* createEnemyShip(double xPos, double yPos, double width, double height, Abstract::Window *window,ENEMY_TYPE type) override;
        Abstract::Bullet* createBullet(double xPos, double yPos, double width, double height, Abstract::Window *window, BULLET_TYPE type) override;
        /*Abstract::Bonus *createBonus(int xPos, int yPos, int width, int height) override;*/
    };
}



#endif //PROJECT_SDLFACTORY_H
