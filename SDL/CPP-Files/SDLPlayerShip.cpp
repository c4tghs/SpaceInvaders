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
SDLNs::SDLPlayerShip::SDLPlayerShip(int xPos, int yPos, int width, int height,SDL_Renderer* renderer,std::string playerShipPath):PlayerShip(
        xPos,yPos,width,height)
{
    m_renderer = renderer;
    m_playerShipPath = std::move(playerShipPath);

    m_playerShipTexture = new GameNs::TextureManager(m_renderer);
    //create texture
    loadMedia();
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
/**
 * Method to destroy player texture
 */
void SDLNs::SDLPlayerShip::close() {
    m_playerShipTexture->free();
}