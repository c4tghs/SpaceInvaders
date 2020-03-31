//
// Created by cliff on 12/03/2020.
//

#include "../Headers/SDLEnemyShip.h"
SDLEnemyShip::SDLEnemyShip(SDL_Renderer *renderer, int screenHeight, int screenWidth, std::string enemyShipPath,int xPos,int yPos) {
    m_renderer = renderer;
    m_enemyShipPath = enemyShipPath;
    m_screenHeight = screenHeight;
    m_screenWidth = screenWidth;
    m_shipHeight = m_screenHeight/25;
    m_shipWidth = m_screenWidth/25;
    m_xPos = xPos;
    m_yPos = yPos;
    TextureManager *enemyShipTexture = new TextureManager(m_renderer);
    m_enemyShipTexture = enemyShipTexture;
    m_moveDirection = 1;
    m_timer = new SDLTimer();
    //create texture
    loadMedia();

}
void SDLEnemyShip::loadMedia() {
    m_enemyShipTexture->LoadTexture(m_enemyShipPath,m_renderer);
    if(m_enemyShipTexture->getTexture() == NULL)
    {
        printf("Something went wrong loading texture %S",SDL_GetError());
    }

}
void SDLEnemyShip::moveEnemyShip() {

    m_xPos += (50*(m_timer->getDeltaTime()/5))*m_moveDirection;

}
void SDLEnemyShip::setMoveDirection(int direction) {
    m_moveDirection = direction;
}
/**
 * Method used to check if an enemy ship has hit boundary
 * 0 or m_screenWidth-m_shipWidth
 * @return
 */
bool SDLEnemyShip::hitBoundary() {
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
int SDLEnemyShip::getMoveDirection() {
    return m_moveDirection;
}
int SDLEnemyShip::getXPosition()
{
    return m_xPos;
}
int SDLEnemyShip::getYPosition(){
    return m_yPos;
}
void SDLEnemyShip::setXPosition(int x){
    m_xPos = x;
}
void SDLEnemyShip::setYPosition(int y){
    m_yPos = y;
}
void SDLEnemyShip::render(){
    moveEnemyShip();
    //update time
    m_timer->update();

    SDL_Rect render = {m_xPos,m_yPos,m_shipWidth,m_shipHeight};
    SDL_RenderCopy(m_renderer,m_enemyShipTexture->getTexture(),NULL,&render);

}
void SDLEnemyShip::close(){
    m_enemyShipTexture->free();
}