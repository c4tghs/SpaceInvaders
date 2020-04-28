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

SDLNs::SDLFactory::SDLFactory() {
    m_configHandler = new GameNs::ConfigHandler();
    m_screenWidth = m_configHandler->getScreenWidth();
    m_screenHeight = m_configHandler->getScreenHeight();
    //Check if SDL was initialised successfully
    if(SDL_Init(SDL_INIT_VIDEO) !=0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) !=0)
    {
        std::cerr << "Failed to initialise SDL: "<< SDL_GetError() << std::endl;
        m_isRunning = false;
        //exit(1);
    }
    //Check if TTF was initialised successfully
    else if (TTF_Init() < 0)
    {
        std::cerr << "Unable to initialise TTF library: "<< TTF_GetError() << std::endl;
        m_isRunning = false;
        //exit(1);
    }
    else
    {
        //Create SDL window
        createWindow("Space invaders", SCREEN_WIDTH, SCREEN_HEIGHT);

        //Check if window was created successfully
        if(m_window == nullptr)
        {
            std::cerr << "Failed to create Window." << std::endl;
            m_isRunning = false;
        }
        else
        {
            //Create renderer
            createRender();

            //Check if renderer was created successfully
            if(m_renderer == nullptr)
            {
                std::cerr << "Failed to create Renderer."<< std::endl;
                m_isRunning = false;
            }
            else
            {
                //Initialise PNG, JPG loading
                int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
                if(!(IMG_Init(imgFlags) & imgFlags))
                {
                    std::cerr << "Failed to initialise SDL_image: "<< IMG_GetError() << std::endl;
                    m_isRunning = false;
                } else
                {
                    m_isRunning = true;
                }
            }
        }

    }
}

/**
 * Destructor
 */
SDLNs::SDLFactory::~SDLFactory() {
    delete m_configHandler;
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
    std::cerr << "Game cleaned successfully" << std::endl;
}
/**
 * Method to create an instance of SDLPlayerShip
 * @param playerShipPath
 * @return instance of PlayerShip
 */
GameNs::PlayerShip* SDLNs::SDLFactory::createPlayerShip(const char *playerShipPath)
{
    return new SDLPlayerShip(m_configHandler->getPlayerShipXPos(), m_configHandler->getPlayerShipYPos(), m_configHandler->getPlayerShipWidth(), m_configHandler->getPlayerShipHeight(), m_renderer, playerShipPath);
}
/**
 * Method used to create an instance of SDL enemyShip
 * @param enemyShipPath - path to image of enemyShip
 * @param xPos - x postion of ship
 * @param yPos - y position of ship
 * @return - instance of EnemyShip
 */
GameNs::EnemyShip * SDLNs::SDLFactory::createEnemyShip(const char *enemyShipPath, int xPos, int yPos, GameNs::Timer* timer) {
    return new SDLEnemyShip(m_renderer, timer, enemyShipPath, xPos, yPos, m_configHandler->getEnemyShipWidth(), m_configHandler->getEnemyShipHeight());
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
void SDLNs::SDLFactory::createWindow(const char *title, int width, int height) {
    m_window = SDL_CreateWindow(title,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width,height,SDL_WINDOW_SHOWN| SDL_WINDOW_RESIZABLE);
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
GameNs::Bullet * SDLNs::SDLFactory::createBullet(const char *bulletPath, int xPos, int yPos, int width, int height) {
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
 * @return - instance of PlayerLife
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
GameNs::Bonus *SDLNs::SDLFactory::createBonus(const char* bonusImagePath, int xPos, int yPos, int width, int height) {
    return new SDLBonus(m_renderer,xPos,yPos,width,height,bonusImagePath);
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
bool SDLNs::SDLFactory::isRunning()
{
    SDL_Event event;

    while(SDL_PollEvent(&event) !=0)
    {
        //Press on X
        if(event.type == SDL_QUIT)
        {
            m_isRunning = false;
        }
        if(event.type == SDL_WINDOWEVENT_RESIZED)
        {
            std::cout << "Window has been resized" << std::endl;
        }
    }

    return m_isRunning;
}

/**
 * Method to set game running state
 * @param state - state of game
 */
void SDLNs::SDLFactory::setRunningState(bool state) {
    m_isRunning = state;
}








