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
    m_playerShipTexture = playerShipTexture;
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

    SDL_Rect render = {m_xPos,m_yPos,m_shipWidth,m_shipHeight};
    SDL_RenderCopy(m_renderer,m_playerShipTexture->getTexture(),NULL,&render);
}

void SDLNs::SDLPlayerShip::close() {
 m_playerShipTexture->free();
}