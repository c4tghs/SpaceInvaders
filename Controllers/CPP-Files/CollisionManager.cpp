//
// Created by cliff on 04/04/2020.
//

#include "../Headers/CollisionManager.h"

//static variable
GameNs::CollisionManager* GameNs::CollisionManager::m_instance = nullptr;

/**
 * Method that creates instance of CollisionManager
 * @return instance of CollisionManager
 */
GameNs::CollisionManager* GameNs::CollisionManager::getInstance() {
    if(m_instance ==nullptr)
    {
        m_instance = new CollisionManager();
    }
    return m_instance;
}

/**
 * Constructor
 */
GameNs::CollisionManager::CollisionManager() {}

/**
 * Method to check if there's a collision between a bullet and enemyship
 * @param xPos - x position of other object
 * @param yPos - y position of other object
 * @param width - width of other object
 * @param height - height of other object
 * @param bullet - the bullet
 * @return
 */
bool GameNs::CollisionManager::checkCollision(Bullet * bullet,int xPos, int yPos, int width, int height) {
    return xPos + width >= bullet->getXPosition() &&
           xPos <= bullet->getXPosition() + bullet->getWidth() &&
           yPos + height >= bullet->getYPosition() &&
           yPos <= bullet->getYPosition() + bullet->getHeight();
}




