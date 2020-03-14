//
// Created by cliff on 12/03/2020.
//

#include "../Headers/SDLEnemyShip.h"
SDLEnemyShip:: SDLEnemyShip(SDL_Renderer *renderer,string enemyShipPath){
    m_renderer = renderer;
    m_enemyShipPath = enemyShipPath;
}
int SDLEnemyShip::getXPosition()
{
    return m_xPos;
}
int SDLEnemyShip::getYPosition(){
    return m_yPos;
}
void SDLEnemyShip::render(){

}
void SDLEnemyShip::close(){

}