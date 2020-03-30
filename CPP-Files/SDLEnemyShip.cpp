//
// Created by cliff on 12/03/2020.
//

#include "../Headers/SDLEnemyShip.h"
SDLEnemyShip:: SDLEnemyShip(SDL_Renderer *renderer,int screenHeight,int screenWidth,string enemyShipPath, int xPos, int yPos){
    m_renderer = renderer;
    m_enemyShipPath = enemyShipPath;
    m_screenHeight = screenHeight;
    m_screenWidth = screenWidth;
    m_shipHeight = m_screenHeight/10;
    m_shipWidth = m_screenWidth/10;
    m_xPos = xPos;
    m_yPos = yPos;
    TextureManager *enemyShipTexture = new TextureManager(m_renderer);
    m_enemyShipTexture = enemyShipTexture;
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

    m_xPos = SDL_GetTicks()/10;
    /*if(m_xPos <= m_screenWidth-m_shipWidth)
    {

    }*/
    if(m_xPos >= m_screenWidth-m_shipWidth)
    {
        //m_xPos -= m_screenWidth-m_shipWidth;
        m_xPos -= SDL_GetTicks()/10;
        m_yPos +=1;
    }
    if(m_xPos <= m_shipWidth)
    {
        m_yPos +=1;
    }
    if(m_yPos >= m_screenHeight-m_shipHeight)
    {
        m_yPos = 100;
    }

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

    SDL_Rect render = {m_xPos,m_yPos,m_shipWidth,m_shipHeight};
    SDL_RenderCopy(m_renderer,m_enemyShipTexture->getTexture(),NULL,&render);

}
void SDLEnemyShip::close(){
    m_enemyShipTexture->free();
}