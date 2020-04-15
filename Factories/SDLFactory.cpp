//
// Created by cliff on 08/03/2020.
//

#include <iostream>
#include "SDLFactory.h"
#include "../SDL/Headers/SDLPlayerShip.h"
#include "../SDL/Headers/SDLEnemyShip.h"
#include "../SDL/Headers/SDLBackground.h"
#include "../SDL/Headers/SDLBullet.h"
#include "../SDL/Headers/SDLScore.h"
#include "../SDL/Headers/SDLPlayerLife.h"
#include "../SDL/Headers/SDLBonus.h"


/**
 * Method to create an instance of SDLPlayerShip
 * @param playerShipPath
 * @return instance of PlayerShip
 */
GameNs::PlayerShip* SDLNs::SDLFactory::createPlayerShip(std::string playerShipPath)
{
    int shipHeight =m_screenHeight/10;
    int xPos =  (m_screenWidth/2)-50;
    int yPos = m_screenHeight-(shipHeight+10);
    int shipWidth = m_screenWidth/10;
    return new SDLPlayerShip(xPos,yPos,shipWidth,shipHeight,m_renderer,playerShipPath);
}
/**
 * Method used to create an instance of SDL enemyShip
 * @param enemyShipPath - path to image of enemyShip
 * @param xPos - x postion of ship
 * @param yPos - y position of ship
 * @return - instance of EnemyShip
 */
GameNs::EnemyShip * SDLNs::SDLFactory::createEnemyShip(std::string enemyShipPath, int xPos, int yPos) {
    int shipWidth = m_screenWidth/25;
    int shipHeight = m_screenHeight/25;
    return new SDLEnemyShip(m_renderer, enemyShipPath, xPos, yPos,shipWidth,shipHeight);
}

/**
 * Method used to create an instance of SDL background
 * @return -  instance of Background
 */
GameNs::Background* SDLNs::SDLFactory::createBackground()
{
    return new SDLBackground(m_renderer);
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
/**
 * Method used to create an instance of SDL Bullet
 * @param bulletPath - path to image of bullet
 * @param xPos - x position of bullet
 * @param yPos - y position of bullet
 * @return - instance of Bullet
 */
GameNs::Bullet * SDLNs::SDLFactory::createBullet(std::string bulletPath, int xPos, int yPos, int width, int height) {
    return new SDLBullet(m_renderer,bulletPath,xPos,yPos,width,height);
}
/**
 * Method to create an instance of SDLTimer
 * @return - instance of Timer
 */
GameNs::Timer* SDLNs::SDLFactory::createTimer() {
    return new SDLTimer();
}
/**
 * Method to create an instance of SDLScore
 * @return - instance of Score
 */
GameNs::Score *SDLNs::SDLFactory::createScore() {
    return new SDLScore(m_renderer);
}
/**
 * Method to create an instance of SDLPlayerLife
 * @return - instance of
 */
GameNs::PlayerLife *SDLNs::SDLFactory::createPlayerLife() {
    return new SDLPlayerLife(m_renderer,m_screenWidth);
}
/**
 * Method to create an instance of SDLBonus
 * @param bonusImagePath - path to bonus image
 * @param xPos - x position of bonus
 * @param yPos - y position of bonus
 * @param width - width of bonus
 * @param height - height of bonus
 * @return - Bonus instance
 */
GameNs::Bonus *SDLNs::SDLFactory::createBonus(std::string bonusImagePath, int xPos, int yPos, int width, int height) {
    return new SDLBonus(m_renderer,xPos,yPos,width,height,bonusImagePath);
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
        std::cout << "Failed to initialise SDL: "<< SDL_GetError() << std::endl;
        exit(1);
    } else if (TTF_Init() < 0)
    {
        std::cout << "Unable to initialise TTF library: "<< SDL_GetError() << std::endl;
        exit(1);
    }
    else{
        //create SDL window
        createWindow("Space invaders", m_screenWidth, m_screenHeight);

        //check if window was created successfully
        if(m_window == nullptr)
        {
            std::cout << "Failed to create Window: "<< SDL_GetError() << std::endl;
        } else
        {
            //create renderer
            createRender();

            //check if renderer was created succesfully
            if(m_renderer == nullptr)
            {
                std::cout << "Failed to create Renderer: "<< SDL_GetError() << std::endl;
                m_IsRunning = false;
            } else
            {
                //initialise PNG loading
                int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
                if(!(IMG_Init(imgFlags) & imgFlags))
                {
                    std::cout << "Failed to initialise SDL_image: "<< IMG_GetError() << std::endl;
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
    SDL_DestroyRenderer(m_renderer);
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
    std::cout << "Game cleaned successfully" << std::endl;

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
bool SDLNs::SDLFactory::getRunningState()
{
    SDL_Event event;

    while(SDL_PollEvent(&event) !=0)
    {
        if(event.type == SDL_QUIT)
        {
            m_IsRunning = false;
        }
    }

    return m_IsRunning;
}








