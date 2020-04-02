//
// Created by cliff on 08/03/2020.
//

#include <iostream>
#include "SDLFactory.h"

#include "../SDL/Headers/SDLPlayerShip.h"
#include "../SDL/Headers/SDLEnemyShip.h"
#include "../SDL/Headers/SDLBackground.h"
#include "../SDL/Headers/SDLBullet.h"


/**
 *
 * @param playerShipPath
 * @return
 */
GameNs::Ship* SDLNs::SDLFactory::createPlayerShip(std::string playerShipPath)
{
    return new SDLPlayerShip(m_renderer,m_screenHeight,m_screenWidth,playerShipPath);
}
/**
 * Method used to create an instance of SDL enemyShip
 * @param enemyShipPath - path to image of enemyShip
 * @param xPos - x postion of ship
 * @param yPos - y position of ship
 * @return - the created instance
 */
GameNs::Ship * SDLNs::SDLFactory::createEnemyShip(std::string enemyShipPath, int xPos, int yPos) {
    return new SDLEnemyShip(m_renderer, m_screenHeight, m_screenWidth, enemyShipPath, xPos, yPos);
}

/**
 * Method used to create an instance of SDL background
 * @return the created instance
 */
GameNs::Background* SDLNs::SDLFactory::createBackground()
{
    return new SDLBackground(m_renderer,m_screenWidth,m_screenHeight);
}

/***
 * Method used to create an instance of SDL window
 * @param title - title of the window
 * @param width - width of the window
 * @param height - height of the window
 */
void SDLNs::SDLFactory::createWindow(const char* title, int width, int height) {
    m_window = SDL_CreateWindow(title,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width,height,SDL_WINDOW_SHOWN);
}
/**
 * Method used to create an an instance of SDL renderer
 */
void SDLNs::SDLFactory::createRender() {
    m_renderer = SDL_CreateRenderer(m_window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); //SDL_RENDERER_PRESENTVSYNC = synchronisation
}
GameNs::Bullet* SDLNs::SDLFactory::createBullet(std::string bulletPath, int xPos, int yPos) {
    return new SDLBullet(m_renderer,bulletPath,xPos,yPos);
}
GameNs::Timer* SDLNs::SDLFactory::createTimer() {
    return new SDLTimer();
}

/***
 * Method that returns private member renderer
 * @return private SDL_Renderer
 */
SDL_Renderer* SDLNs::SDLFactory::getRenderer()
{
    return m_renderer;
}
/**
 * Method to initialise parameters ie, window, render etc.
 * @param windowWidth - width of the window
 * @param windowHeight - height of the window
 */
void SDLNs::SDLFactory::initialise(int windowWidth, int windowHeight){
    m_screenWidth = windowWidth;
    m_screenHeight = windowHeight;
    //check if SDL was initialised succesfully
    if(SDL_Init(SDL_INIT_VIDEO) !=0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) !=0)
    {
        SDL_Log("Failed to initialise SDL: %s",SDL_GetError());
    } else{
        //create SDL window
        createWindow("Space invaders", m_screenWidth, m_screenHeight);

        //check if window was created successfully
        if(m_window == NULL)
        {
            SDL_Log("Failed to create Window: %s",SDL_GetError());
        } else
        {
            //create renderer
            createRender();

            //check if renderer was created succesfully
            if(m_renderer == NULL)
            {
                SDL_Log("Failed to create Renderer: %s",SDL_GetError());
                m_IsRunning = false;
            } else
            {
                //initialise PNG loading
                int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
                if(!(IMG_Init(imgFlags) & imgFlags))
                {
                    SDL_Log("Failed to initialise SDL_image: %s",IMG_GetError());
                    printf("Failed to initialise SDL_image: %s",IMG_GetError());
                    m_IsRunning = false;
                } else
                {
                    m_IsRunning = true;
                }
            }
        }

    }
}

/**
 * Method used to clean everything after user quits the game
 *
 */
void SDLNs::SDLFactory::close()
{
    SDL_DestroyWindow(m_window);
    //SDL_DestroyRenderer(m_renderer);
    IMG_Quit();
    SDL_Quit();
    std::cout << "Game cleaned succesfully" << std::endl;
}

/**
 * Method used to present the renderer
 */
void SDLNs::SDLFactory::render(){
    SDL_RenderPresent(m_renderer);
}
/**
 * Method used to handle events
 * @return True or False
 */
bool SDLNs::SDLFactory::getEvents()
{
    SDL_Event event;

    while(SDL_PollEvent(&event) !=0)
    {
        if(event.type == SDL_QUIT)
        {
            m_IsRunning = false;
            close();
        }
    }

    return m_IsRunning;
}

