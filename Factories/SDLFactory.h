//
// Created by cliff on 08/03/2020.
//

#ifndef PROJECT_SDLFACTORY_H
#define PROJECT_SDLFACTORY_H

//using namespace std;


#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include "../Headers/Ship.h"
#include "AbstractFactory.h"

class SDLFactory:public AbstractFactory {
public:
    SDLFactory(){};

    Ship* createPlayerShip(string playerShipPath);
    Ship* createEnemyShip(string enemyShipPath);
    Background* createBackground();


    void createWindow(const char* title,int width, int height);
    void createRender();
    SDL_Renderer* getRenderer();
    void initialise(int windowWidth, int windowHeight);
    void close();
    void render();
    bool getEvents();

private:
    int m_count = 0;
    bool m_rightDirection = true;
    bool m_IsRunning;
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;

    int m_screenWidth;
    int m_screenHeight;
};


#endif //PROJECT_SDLFACTORY_H
