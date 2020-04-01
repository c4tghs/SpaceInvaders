//
// Created by cliff on 12/03/2020.
//

#include "../Headers/SDLEnemyShip.h"
/**
 * Method to initialise an instance of SDLEnemyShip
 * @param renderer
 * @param screenHeight
 * @param screenWidth
 * @param enemyShipPath
 * @param xPos
 * @param yPos
 */
SDLNs::SDLEnemyShip::SDLEnemyShip(SDL_Renderer *renderer, int screenHeight, int screenWidth, std::string enemyShipPath,int xPos,int yPos) {
    m_renderer = renderer;
    m_enemyShipPath = enemyShipPath;
    m_screenHeight = screenHeight;
    m_screenWidth = screenWidth;
    m_shipHeight = m_screenHeight/25;
    m_shipWidth = m_screenWidth/25;
    m_xPos = xPos;
    m_yPos = yPos;
    GameNs::TextureManager *enemyShipTexture = new GameNs::TextureManager(m_renderer);
    m_enemyShipTexture = enemyShipTexture;
    m_moveDirection = 1;
    //create texture
    loadMedia();

}
void SDLNs::SDLEnemyShip::loadMedia() {
    m_enemyShipTexture->LoadTexture(m_enemyShipPath,m_renderer);
    if(m_enemyShipTexture->getTexture() == NULL)
    {
        printf("Something went wrong loading texture %S",SDL_GetError());
    }

}
void SDLNs::SDLEnemyShip::setMoveDirection(int direction) {
    m_moveDirection = direction;
}
int SDLNs::SDLEnemyShip::getMoveDirection() {
    return m_moveDirection;
}
int SDLNs::SDLEnemyShip::getXPosition()
{
    return m_xPos;
}
int SDLNs::SDLEnemyShip::getYPosition(){
    return m_yPos;
}
void SDLNs::SDLEnemyShip::setXPosition(int x){
    m_xPos = x;
}
void SDLNs::SDLEnemyShip::setYPosition(int y){
    m_yPos = y;
}
void SDLNs::SDLEnemyShip::render(){

    SDL_Rect render = {m_xPos,m_yPos,m_shipWidth,m_shipHeight};
    SDL_RenderCopy(m_renderer,m_enemyShipTexture->getTexture(),NULL,&render);

}
void SDLNs::SDLEnemyShip::close(){
    m_enemyShipTexture->free();
}