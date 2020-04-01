//
// Created by cliff on 12/03/2020.
//

#include "../Headers/SDLPlayerShip.h"

SDLNs::SDLPlayerShip::SDLPlayerShip(SDL_Renderer *renderer,int screenHeight,int screenWidth,std::string playerShipPath)
{
    m_renderer = renderer;
    m_playerShipPath = playerShipPath;
    m_screenHeight = screenHeight;
    m_screenWidth  = screenWidth;
    m_shipHeight = m_screenHeight/10;
    m_shipWidth = m_screenWidth/10;
    m_xPos = (m_screenWidth/2)-50;
    m_yPos = m_screenHeight-(m_shipHeight+10);
    GameNs::TextureManager *playerShipTexture = new GameNs::TextureManager(m_renderer);
    m_moveDirection = 1;
    m_playerShipTexture = playerShipTexture;
    m_timer = new SDLTimer();
    //create texture
    loadMedia();
}
int SDLNs::SDLPlayerShip::getXPosition() {
    return m_xPos;
}
int SDLNs::SDLPlayerShip::getYPosition() {
    return m_yPos;
}
void SDLNs::SDLPlayerShip::setXPosition(int x){
    m_xPos = x;
}
void SDLNs::SDLPlayerShip::setYPosition(int y){
    m_yPos = y;
}
void SDLNs::SDLPlayerShip::loadMedia() {
    m_playerShipTexture->LoadTexture(m_playerShipPath,m_renderer);
    if(m_playerShipTexture->getTexture() == NULL){
        printf("Something went wrong loading texture %S",SDL_GetError());
    }

}
void SDLNs::SDLPlayerShip::render() {
    movePlayerShip();
    //update timer
    m_timer->update();

    //SDL_Rect render = {m_xPos,m_yPos};
    SDL_Rect render = {m_xPos,m_yPos,m_shipWidth,m_shipHeight};
    SDL_RenderCopy(m_renderer,m_playerShipTexture->getTexture(),NULL,&render);
}
void SDLNs::SDLPlayerShip::movePlayerShip() {
    int direction = m_keyStates->directions();
    switch(direction)
    {
        //left
        case 1:
            m_xPos -= m_timer->getDeltaTime()*5;//m_xPos -5;
            break;
        case 2:
            m_xPos += m_timer->getDeltaTime()*5;//m_xPos +5;
            break;
    }
    hitBoundary();

}
void SDLNs::SDLPlayerShip::close() {
 m_playerShipTexture->free();
}
bool SDLNs::SDLPlayerShip::hitBoundary(){
    if(m_xPos < 0)
    {
        m_xPos = 0;
        return true;
    }
    else if (m_xPos > m_screenWidth-m_shipWidth)
    {
        m_xPos = m_screenWidth-m_shipWidth;
        return true;
    }
    return false;
}
int SDLNs::SDLPlayerShip::getMoveDirection(){
    return m_moveDirection;
}
void SDLNs::SDLPlayerShip::setMoveDirection(int direction){
    m_moveDirection =  direction;
}