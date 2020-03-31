//
// Created by cliff on 08/03/2020.
//

#include <iostream>
#include "SDLFactory.h"

#include "../Headers/SDLPlayerShip.h"
#include "../Headers/SDLEnemyShip.h"
#include "../Headers/SDLBackground.h"


/**
 *
 * @param playerShipPath
 * @return
 */
Ship* SDLFactory::createPlayerShip(std::string playerShipPath)
{
    return new SDLPlayerShip(m_renderer,m_screenHeight,m_screenWidth,playerShipPath);
}
/**
 *
 * @param enemyShipPath
 * @return
 */
Ship * SDLFactory::createEnemyShip(std::string enemyShipPath, int xPos, int yPos) {
    return new SDLEnemyShip(m_renderer, m_screenHeight, m_screenWidth, enemyShipPath, xPos, yPos);
}

/**
 *
 * @param backgroundPath
 * @return
 */
Background* SDLFactory::createBackground()
{
    return new SDLBackground(m_renderer,m_screenWidth,m_screenHeight);
}

/***
 * Method used to create an SDL window
 * @param title - title of the window
 * @param width - width of the window
 * @param height - height of the window
 */
void SDLFactory::createWindow(const char* title, int width, int height) {
    m_window = SDL_CreateWindow(title,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width,height,SDL_WINDOW_SHOWN);
}
/**
 * Method used to create an SDL renderer
 */
void SDLFactory::createRender() {
    m_renderer = SDL_CreateRenderer(m_window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); //SDL_RENDERER_PRESENTVSYNC = synchronisation
}

/***
 * Method that returns private member renderer
 * @return private SDL_Renderer
 */
SDL_Renderer* SDLFactory::getRenderer()
{
    return m_renderer;
}
/**
 *
 * @return Boolean - if engine is running or not
 */
void SDLFactory::initialise(int windowWidth, int windowHeight){
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
                int imgFlags = IMG_INIT_PNG;
                if(!(IMG_Init(imgFlags) & imgFlags))
                {
                    SDL_Log("Failed to initialise SDL_image: %s",IMG_GetError());
                    printf("Failed to initialise SDL_image: %s",IMG_GetError());
                    m_IsRunning = false;
                } else
                {
                    //initialise PNG loading
                    int imgFlags_JPG = IMG_INIT_JPG;
                    if(!(IMG_Init(imgFlags_JPG) & imgFlags_JPG))
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
}

/**
 * Method used to clean everything after user quits the game
 *
 */
void SDLFactory::close()
{
    SDL_DestroyWindow(m_window);
    //SDL_DestroyRenderer(m_renderer);
    IMG_Quit();
    SDL_Quit();
    std::cout << "Game cleaned succesfully" << std::endl;
}

/**
 * Method used to set certain features of the renderer
 */
void SDLFactory::render(){
    SDL_RenderPresent(m_renderer);
}
/**
 * Method used to handle events
 */
bool SDLFactory::getEvents()
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

