/**
 * CPP file of PlayerManager class
 */

#include <iostream>
#include "../Headers/PlayerManager.h"
#include "../Headers/ConfigHandler.h"
#include "../../Models/Headers/RandomNumber.h"

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
GameNs::PlayerManager::PlayerManager(GameNs::AbstractFactory *AF, Timer *timer, CollisionDetector *collisionDetector,
                                     ConfigHandler *configHandler, BulletManager *bulletManager) {
    m_factory = AF;
    m_timer = timer;
    m_bulletManager = bulletManager;
    m_configHandler = configHandler;
    m_playerLife = m_factory->createPlayerLife();
    m_screenHeight = m_configHandler->getScreenHeight();
    m_screenWidth =  m_configHandler->getScreenWidth();
    m_collisionDetector = collisionDetector;
    m_playerLife->setPlayerLife(m_configHandler->getPlayerLives());
    //Create playerShip;
    m_playerShip  = m_factory->createPlayerShip(m_configHandler->getPathPlayerShip().c_str());
    //Set player speed factor
    m_playerShip->setPlayerSpeed(m_configHandler->getPlayerSpeed());
    //Reserve memory for 10 bullets
    m_bullets.reserve(10);

    //Create 10 bullets
    createBullets();
}
/**
 * Destructor
 */
GameNs::PlayerManager::~PlayerManager() {
    for(auto & m_bullet : m_bullets)
    {
        delete m_bullet;
    }
    delete m_playerLife;
    delete m_playerShip;
}
/**
 * update method
 */
void GameNs::PlayerManager::update() {
    //Move player
    movePlayer();
    checkPlayerBoundaries();
    //End game if player has run out of lives
    if(m_playerLife->getPlayerLife() <=0)
    {
        m_factory->setRunningState(false);
    }
    //Render player
    m_playerShip->render();
    //Render player life
    m_playerLife->render();
}
/**
 * Method to check what button has pressed and chnage position of player ship
 */
void GameNs::PlayerManager::movePlayer() {
    //int xPos;
    switch(m_keyStates->directions())
    {
        case 1:
            //Move player ship left
            m_playerShip->setXPosition(m_playerShip->getXPosition() - m_timer->getDeltaTime() * m_playerShip->getPlayerSpeed());
            break;
        case 2:
            //Move player ship right
            m_playerShip->setXPosition(m_playerShip->getXPosition() + m_timer->getDeltaTime() * m_playerShip->getPlayerSpeed());
            break;
        case 3:
            shoot();
            break;
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
    //Check collision with enemy bullet, if an enemy bullet has been fired.
    if(m_bulletManager->isEnemyBulletInFlight())
    {
        if(m_collisionDetector->checkBulletCollision(m_bulletManager->getEnemyBullet(), m_playerShip->getXPosition(),
                                                   m_playerShip->getYPosition(), m_playerShip->getWidth(),
                                                   m_playerShip->getHeight()))
        {
            m_playerLife->setPlayerLife(m_playerLife->getPlayerLife()-1);
            m_bulletManager->setEnemyBulletInFlight(false);

        }
    }
}

/**
 * Method that allows a player to shoot
 */
void GameNs::PlayerManager::shoot() {
    if(m_bulletManager->isPlayerBulletInFlight())
    {
        return;
    }

    m_bullets[0]->setXPosition(m_playerShip->getXPosition()+40);
    m_bullets[0]->setYPosition(m_playerShip->getYPosition());
    m_bulletManager->setPlayerBullet(m_bullets[0]);
    m_bulletManager->setPlayerBulletInFlight(true);

    //Remove bullet from vector
    m_bullets.erase(m_bullets.begin());

    //Create bullets if there're no more bullets left.
    if(m_bullets.empty())
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
        //Create bullet and add it to vector.
        m_bullets.emplace_back(m_factory->createBullet(m_configHandler->getPathPlayerBullet().c_str(), m_playerShip->getXPosition(),
                m_playerShip->getYPosition(), 25, 25));

    }
}
/**
 * Method that returns playerShip
 * @return - playerShip
 */
GameNs::PlayerShip *GameNs::PlayerManager::getPlayerShip() {
    return m_playerShip;
}

GameNs::PlayerLife *GameNs::PlayerManager::getPlayerLife() {
    return m_playerLife;
}


