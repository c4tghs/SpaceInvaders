//
// Created by cliff on 12/03/2020.
//

#include "../Headers/SDLEnemyShip.h"

#include <utility>
#include <iostream>
#define SPRITES_FRAMES 2
/**
 * Constructor for SDlEnemyShip
 * @param renderer
 * @param screenHeight
 * @param screenWidth
 * @param enemyShipPath
 * @param xPos
 * @param yPos
 */
SDLNs::SDLEnemyShip::SDLEnemyShip(SDL_Renderer* renderer, std::string enemyShipPath,int xPos,int yPos,int width, int height):EnemyShip(
        xPos,yPos,width,height)
{
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
    m_enemyShipTexture->loadTexture(m_enemyShipPath);
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
    //Create rectangular area
    SDL_Rect spriteClips[SPRITES_FRAMES];
    spriteClips[0] = {257,35,45,35};
    spriteClips[1] = {315,35,45,35};
    Uint32 ticks = SDL_GetTicks();
    Uint32 seconds = ticks/1000;
    Uint32 sprite = seconds%SPRITES_FRAMES;
    SDL_Rect currentRect = spriteClips[sprite];
    SDL_Rect rect = {getXPosition(), getYPosition(), getWidth(), getHeight()};
    SDL_RenderCopy(m_renderer,m_enemyShipTexture->getTexture(),&currentRect,&rect);


}
/**
 * Method to destroy texture of enemy
 */
void SDLNs::SDLEnemyShip::close(){
    m_enemyShipTexture->free();
    //Deallocate memory
    delete(m_enemyShipTexture);
}