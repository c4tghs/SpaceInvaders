/**
 * CPP file of PlayerManager class
 */

#include "../Headers/PlayerManager.h"

#include <utility>
#include <iostream>

/**
 * Method to create instance of PlayerManager
 */
GameNs::PlayerManager::PlayerManager() {}

/**
 * Method to create an instance of PlayerManager
 * @param AF - abstract factory
 * @param playerShipPath - path of player ship image
 * @param bulletPath - path of bullet image
 * @param screenHeight - screen height
 * @param screenWidth - screen width
 */
GameNs::PlayerManager::PlayerManager(GameNs::AbstractFactory *AF, int screenHeight, int screenWidth,
                                     BulletManager *bulletManager,
                                     Timer *timer) {
    m_factory = AF;
    //create timer
    m_timer = timer;
    //create playerShip;
    m_playerShip  = m_factory->createPlayerShip(m_playerShipPath);
    m_screenHeight = screenHeight;
    m_screenWidth = screenWidth;
    //get player starting position
    m_playerStartPosX = m_playerShip->getXPosition();
    //reserve
    m_bullets.reserve(10);
    //create 10 bullets
    createBullets();
    //get m_bulletManager
    m_bulletManager = bulletManager;
    //create player life
    m_playerLife = m_factory->createPlayerLife();
}
/**
 * update method
 */
void GameNs::PlayerManager::update() {
    //move player
    playerActions();
    //update timer
    m_timer->update();
    checkPlayerBoundaries();
    //render player life
    m_playerLife->render();
    //render player
    m_playerShip->render();
}
/**
 * Method to check what button used has pressed
 */
void GameNs::PlayerManager::playerActions() {
    int direction = m_keyStates->directions();
    int xPos;
    switch(direction)
    {
        case 1:
            xPos = m_playerShip->getXPosition() - m_timer->getDeltaTime() *5;
            m_playerShip->setXPosition(xPos);
            break;
        case 2:
            xPos = m_playerShip->getXPosition() + m_timer->getDeltaTime() *5;
            m_playerShip->setXPosition(xPos);
            break;
        case 3:
            shoot();
        default:
            break;
    }
}
/**
 * Method used to check player boundaries and collision with enemy bullet
 */
void GameNs::PlayerManager::checkPlayerBoundaries() {
    if(m_playerShip->getXPosition() < 0)
    {
        m_playerShip->setXPosition(0);
    }
    else if(m_playerShip->getXPosition() > m_screenWidth - m_playerShip->getWidth())
    {
        m_playerShip->setXPosition(m_screenWidth - m_playerShip->getWidth());

    }
    if(m_bulletManager->getEnemyBulletFired())
    {
        if(CollisionManager::checkCollision(m_bulletManager->getEnemyBullet(), m_playerShip->getXPosition(), m_playerShip->getYPosition(), m_playerShip->getWidth(), m_playerShip->getHeight()))
        {
            m_playerLife->setPlayerLife(m_playerLife->getPlayerLife()-1);
            //m_playerShip->setXPosition(m_playerStartPosX);
            m_bulletManager->setEnemyBulletFired(false);

        }

    }
}
/**
 * Method to destroy player texture
 */
void GameNs::PlayerManager::close() {
    for(auto & m_bullet : m_bullets)
    {
        m_bullet->close();
    }
    m_playerShip->close();

}
/**
 * Method that allows a player to shoot
 */
void GameNs::PlayerManager::shoot() {
    //if(m_timer->)
    if(m_bulletManager->getPlayerBulletFired())
    {
        return;
    }
    for(int i =0; i < m_bullets.size();i++)
    {
        m_bullets[i]->setXPosition(m_playerShip->getXPosition()+60);
        m_bullets[i]->setYPosition(m_playerShip->getYPosition());
        if(m_bulletManager->getPlayerBulletFired())
        {
            break;
        }
        m_bulletManager->setPlayerBullet(m_bullets[i]);
        m_bulletManager->setPlayerBulletFired(true);
        //remove one bullet from vector
        m_bullets.erase(m_bullets.begin()+i);
        break; //execute this loop once
    }
    if(m_bullets.size() == 1)
    {
        createBullets();
    }
}

/**
 * Method to create bullets
 */
void GameNs::PlayerManager::createBullets() {
    for(int i =0; i<10;i++)
    {
        m_bullets.emplace_back(m_factory->createBullet(m_bulletPath,m_playerShip->getXPosition(),m_playerShip->getYPosition()));
    }
}

