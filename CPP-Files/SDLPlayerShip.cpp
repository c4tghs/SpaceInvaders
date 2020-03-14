//
// Created by cliff on 12/03/2020.
//

#include "../Headers/SDLPlayerShip.h"

SDLPlayerShip::SDLPlayerShip(SDL_Renderer *renderer,int screenHeight,int screenWidth,string playerShipPath)
{
    m_renderer = renderer;
    m_playerShipPath = playerShipPath;
    m_screenHeight = screenHeight;
    m_screenWidth  = screenWidth;
    TextureManager *playerShipTexture = new TextureManager(m_renderer);
    m_playerShipTexture = playerShipTexture;
    //create texture
}
int SDLPlayerShip::getXPosition() {
    return m_xPos;
}
int SDLPlayerShip::getYPosition() {
    return m_yPos;
}
void SDLPlayerShip::loadMedia() {
    m_playerShipTexture->LoadTexture(m_playerShipPath,m_renderer);
    if(m_playerShipTexture->getTexture() == NULL){

    }

}
void SDLPlayerShip::render() {
    movePlayerShip();

    SDL_Rect render = {m_xPos,m_yPos};
    SDL_RenderCopy(m_renderer,m_playerShipTexture->getTexture(),NULL,&render);
}
void SDLPlayerShip::movePlayerShip() {
    int direction = m_keyStates->directions();
    switch(direction)
    {
        //left
        case 1:
            m_xPos --;
            break;
        case 2:
            m_xPos ++;
            break;
    }
    if(m_xPos <=0)
    {
        m_xPos = 0;
    }
    if(m_xPos >= m_screenWidth)
    {
        m_xPos = m_screenWidth;
    }
}
void SDLPlayerShip::close() {
 m_playerShipTexture->free();
}