//
// Created by cliff on 08/03/2020.
//

#ifndef PROJECT_SDLFACTORY_H
#define PROJECT_SDLFACTORY_H


#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include "../Headers/Ship.h"
#include "AbstractFactory.h"
#include "../Headers/Timer.h"
namespace SDLNs
{
    class SDLFactory:public GameNs::AbstractFactory {
    public:
        SDLFactory(){};

        GameNs::Ship* createPlayerShip(std::string playerShipPath);
        GameNs::Ship *createEnemyShip(std::string enemyShipPath, int xPos, int yPos);
        GameNs::Background* createBackground();
        GameNs::Timer* createTimer();


        void createWindow(const char* title,int width, int height);
        void createRender();
        SDL_Renderer* getRenderer();
        void initialise(int windowWidth, int windowHeight);
        void close();
        void render();
        bool getEvents();

    private:
        bool m_IsRunning;
        SDL_Window *m_window;
        SDL_Renderer *m_renderer;

        int m_screenWidth;
        int m_screenHeight;
    };
}



#endif //PROJECT_SDLFACTORY_H
