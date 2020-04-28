/**
 * CPP file for SDLPlayerShip class
 */

#include "../Headers/SDLPlayerShip.h"

#include <utility>
#include <iostream>

/**
 * Constructor for SDLPlayerShip
 * @param xPos
 * @param yPos
 * @param width
 * @param height
 * @param renderer
 * @param screenHeight
 * @param screenWidth
 * @param playerShipPath
 */
SDLNs::SDLPlayerShip::SDLPlayerShip(int xPos, int yPos, int width, int height, SDL_Renderer* renderer,
                                    const char *playerShipPath): PlayerShip(xPos, yPos, width, height)
{
    m_renderer = renderer;
    m_playerShipPath = playerShipPath;

    m_playerShipTexture = new GameNs::TextureManager(m_renderer);
    //create texture
    loadMedia();
}

/**
 * Destructor
 */
SDLNs::SDLPlayerShip::~SDLPlayerShip()
{
    delete m_playerShipTexture;
}

/**
 * Method to create texture for player
 */
void SDLNs::SDLPlayerShip::loadMedia() {
    m_playerShipTexture->loadTexture(m_playerShipPath);
    if(m_playerShipTexture->getTexture() == nullptr){
        std::cout << "Something went wrong loading texture: "<< SDL_GetError()<< std::endl;
        exit(1);
    }

}

/**
 * Method to show player
 */
void SDLNs::SDLPlayerShip::render() {
    //Create rectangular area
    SDL_Rect rect = {getXPosition(), getYPosition(), getWidth(), getHeight()};
    SDL_RenderCopy(m_renderer,m_playerShipTexture->getTexture(),nullptr,&rect);
}
