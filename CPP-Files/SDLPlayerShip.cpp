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
    m_shipHeight = m_screenHeight/10;
    m_shipWidth = m_screenWidth/10;
    m_xPos = (m_screenWidth/2)-50;
    m_yPos = m_screenHeight-(m_shipHeight+10);
    TextureManager *playerShipTexture = new TextureManager(m_renderer);
    m_playerShipTexture = playerShipTexture;
    //create texture
    loadMedia();
}
int SDLPlayerShip::getXPosition() {
    return m_xPos;
}
int SDLPlayerShip::getYPosition() {
    return m_yPos;
}
void SDLPlayerShip::setXPosition(int x){
    m_xPos = x;
}
void SDLPlayerShip::setYPosition(int y){
    m_yPos = y;
}
void SDLPlayerShip::loadMedia() {
    m_playerShipTexture->LoadTexture(m_playerShipPath,m_renderer);
    if(m_playerShipTexture->getTexture() == NULL){
        printf("Something went wrong loading texture %S",SDL_GetError());
    }

}
void SDLPlayerShip::render() {
    movePlayerShip();

    //SDL_Rect render = {m_xPos,m_yPos};
    SDL_Rect render = {m_xPos,m_yPos,m_shipWidth,m_shipHeight};
    SDL_RenderCopy(m_renderer,m_playerShipTexture->getTexture(),NULL,&render);
}
void SDLPlayerShip::movePlayerShip() {
    int direction = m_keyStates->directions();
    switch(direction)
    {
        //left
        case 1:
            m_xPos = m_xPos -5;
            break;
        case 2:
            m_xPos = m_xPos +5;
            break;
    }
    if(m_xPos <=0)
    {
        m_xPos = 0;
    }
    if(m_xPos >= m_screenWidth-m_shipWidth)
    {
        m_xPos = m_screenWidth-m_shipWidth;
    }
}
void SDLPlayerShip::close() {
 m_playerShipTexture->free();
}