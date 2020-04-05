/**
 * Header for SDLfactory
 */

#ifndef PROJECT_SDLFACTORY_H
#define PROJECT_SDLFACTORY_H


#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "../Models/Headers/Ship.h"
#include "AbstractFactory.h"
namespace SDLNs
{
    class SDLFactory:public GameNs::AbstractFactory {
    public:
        SDLFactory(){};

        GameNs::Ship* createPlayerShip(std::string playerShipPath);
        GameNs::Ship *createEnemyShip(std::string enemyShipPath, int xPos, int yPos);
        GameNs::Background* createBackground();
        GameNs::Bullet* createBullet(std::string bulletPath, int xPos, int yPos);
        GameNs::Timer* createTimer();
        GameNs::Score* createScore();
        void createWindow(const char* title,int width, int height);
        void createRender();
        SDL_Renderer* getRenderer();
        void initialise(int windowWidth, int windowHeight);
        void close();
        void render();
        bool getRunningState();

    private:
        bool m_IsRunning;
        SDL_Window *m_window;
        SDL_Renderer *m_renderer;

        int m_screenWidth;
        int m_screenHeight;
    };
}



#endif //PROJECT_SDLFACTORY_H
