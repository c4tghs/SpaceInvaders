//
// Created by cliff on 12/03/2020.
//

#include "../Headers/SDLEnemyShip.h"

#include <utility>
#include <iostream>

/**
 * Constructor for SDlEnemyShip
 * @param renderer
 * @param screenHeight
 * @param screenWidth
 * @param enemyShipPath
 * @param xPos
 * @param yPos
 */
SDLNs::SDLEnemyShip::SDLEnemyShip(SDL_Renderer *renderer, std::string enemyShipPath,int xPos,int yPos,int width, int height):EnemyShip(
        xPos,yPos,width,height
        ) {
    m_renderer = renderer;
    m_enemyShipPath = std::move(enemyShipPath);
    m_enemyShipTexture = new GameNs::TextureManager(m_renderer);
    m_moveDirection = 1;
    //create texture
    loadMedia();

}
/**
 * Method to create enemyShip texture
 */
void SDLNs::SDLEnemyShip::loadMedia() {
    m_enemyShipTexture->LoadTexture(m_enemyShipPath);
    if(m_enemyShipTexture->getTexture() == nullptr)
    {
        std::cout << "Something went wrong loading texture: "<< SDL_GetError()<< std::endl;
        exit(1);
    }

}
/**
 * Method to set direction enemy
 * @param direction
 */
void SDLNs::SDLEnemyShip::setMoveDirection(int direction) {
    m_moveDirection = direction;
}
/**
 * Method to get the direction enemy is moving
 * @return - direction,ie -1 for left, 1 for right
 */
int SDLNs::SDLEnemyShip::getMoveDirection() {
    return m_moveDirection;
}
/**
 * Method to show enemy
 */
void SDLNs::SDLEnemyShip::render(){

    SDL_Rect render = {getXPosition(),getYPosition(),getWidth(),getHeight()};
    SDL_RenderCopy(m_renderer,m_enemyShipTexture->getTexture(),nullptr,&render);

}
/**
 * Method to destroy texture of enemy
 */
void SDLNs::SDLEnemyShip::close(){
    m_enemyShipTexture->free();
}