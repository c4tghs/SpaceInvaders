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
GameNs::PlayerManager::PlayerManager(GameNs::AbstractFactory *AF,std::string playerShipPath,std::string bulletPath,int screenHeight, int screenWidth){
    m_factory = AF;
    m_timer = AF->createTimer();
    m_playerShipPath = std::move(playerShipPath);
    m_bulletPath = std::move(bulletPath);
    //create playerShip;
    m_playerShip  = AF->createPlayerShip(m_playerShipPath);
    m_screenHeight = screenHeight;
    m_screenWidth = screenWidth;
    //get player starting position
    m_playerStartPosX = m_playerShip->getXPosition();
    //reserve
    m_bullets.reserve(10);
    //create 10 bullets
    createBullets();
    //get bulletManager
    bulletManager = BulletManager::getInstance(m_timer, m_screenHeight);
    //create user score
    m_score = AF->createScore();
    //set player score to 0
    m_score->setScores(0);
    //create player life
    m_playerLife = AF->createPlayerLife();

}
/**
 * update method
 */
void GameNs::PlayerManager::update() {
    bool collision;
    //move player
    playerActions();
    //update timer
    m_timer->update();
    bulletManager->update();
    //check if player bullet has collided with enemy
    collision = bulletManager->checkPlayerCollisions();
    if(collision)
    {
        m_score->setScores(m_score->getScores()+1);
    }
    checkPlayerBoundaries();
    //render player score
    m_score->render();
    //render player life
    m_playerLife->render();
    //render player
    m_playerShip->render();
    bulletManager->setPlayerBulletCollision(false);
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
    if(bulletManager->getEnemyBulletFired())
    {
        if(CollisionManager::checkCollision(BulletManager::getInstance()->getEnemyBullet(), m_playerShip->getXPosition(), m_playerShip->getYPosition(), m_playerShip->getWidth(), m_playerShip->getHeight()))
        {
            m_playerLife->setPlayerLife(m_playerLife->getPlayerLife()-1);
            //m_playerShip->setXPosition(m_playerStartPosX);
            BulletManager::getInstance()->setEnemyBulletFired(false);

        }

    }
}
/**
 * Method to destory player texture
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
    if(bulletManager->getPlayerBulletFired())
    {
        return;
    }
    for(int i =0; i < m_bullets.size();i++)
    {

        m_bullets[i]->setXPosition(m_playerShip->getXPosition()+60);
        m_bullets[i]->setYPosition(m_playerShip->getYPosition());
        if(bulletManager->getPlayerBulletFired())
        {
            break;
        }
        bulletManager->setPlayerBullet(m_bullets[i]);
        bulletManager->setPlayerBulletFired(true);
        //remove one bullet from vector
        m_bullets.erase(m_bullets.begin()+i);
        break; //execute this loop once
    }
    if(m_bullets.size() == 1)
    {
        createBullets();
    }
}

void GameNs::PlayerManager::createBullets() {
    for(int i =0; i<10;i++)
    {
        m_bullets.emplace_back(m_factory->createBullet(m_bulletPath,m_playerShip->getXPosition(),m_playerShip->getYPosition()));
    }
}

