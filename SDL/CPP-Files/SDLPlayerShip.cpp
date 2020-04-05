/**
 * CPP file for SDLPlayerShip class
 */

#include "../Headers/SDLPlayerShip.h"

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
SDLNs::SDLPlayerShip::SDLPlayerShip(int xPos, int yPos, int width, int height,SDL_Renderer *renderer,std::string playerShipPath):PlayerShip(
        xPos,yPos,width,height)
{
    m_renderer = renderer;
    m_playerShipPath = playerShipPath;

    GameNs::TextureManager *playerShipTexture = new GameNs::TextureManager(m_renderer);
    m_playerShipTexture = playerShipTexture;
    //create texture
    loadMedia();
}
/**
 * Method to create texture for player
 */
void SDLNs::SDLPlayerShip::loadMedia() {
    m_playerShipTexture->LoadTexture(m_playerShipPath,m_renderer);
    if(m_playerShipTexture->getTexture() == NULL){
        printf("Something went wrong loading texture %S",SDL_GetError());
        exit(1);
    }
}
/**
 * Method to show player
 */
void SDLNs::SDLPlayerShip::render() {

    SDL_Rect rect = {getXPosition(), getYPosition(), getWidth(), getHeight()};
    SDL_RenderCopy(m_renderer,m_playerShipTexture->getTexture(),NULL,&rect);
}
/**
 * Method to destroy player texture
 */
void SDLNs::SDLPlayerShip::close() {
 m_playerShipTexture->free();
}