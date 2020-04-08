/**
 * CPP file for BulletManager class
 */

#include "../Headers/BulletManager.h"

#include <utility>
#include <iostream>
#include "../../SDL/Headers/SDLBullet.h"

//static member
GameNs::BulletManager* GameNs::BulletManager::m_instance =nullptr;

GameNs::BulletManager* GameNs::BulletManager::getInstance() {
    if(m_instance == nullptr)
    {
        m_instance = new BulletManager();
    }
    return m_instance;
}
GameNs::BulletManager* GameNs::BulletManager::getInstance(Bullet *bullet, Timer *timer, int screenHeight)  {
    if(m_instance ==nullptr)
    {
        m_instance = new BulletManager(bullet, timer, screenHeight);
    }
    return m_instance;
}

/**
 * Constructor
 */
GameNs::BulletManager::BulletManager() {}
/**
 * Constructor for BulletManager class
 * @param bullet - the bullet
 * @param bulletPath - path to bullet image
 * @param timer - timer
 * @param screenHeight - height of the screen
 */
GameNs::BulletManager::BulletManager(Bullet *bullet, Timer *timer, int screenHeight) {
    m_playerBullet = bullet;
    m_timer = timer;
    m_playerFired = false;
    m_screenHeight = screenHeight;
    CollisionManager::getInstance();
}
/**
 * Update method
 */
void GameNs::BulletManager::update() {
    //check if bullet has been fired
    //get out of function if it has not been fired
    if(m_playerFired)
    {
        m_playerBullet->render();
    }
    if(m_enemyFired)
    {
        m_enemyBullet->render();
    }
    if(m_playerFired or m_enemyFired)
    {
        moveBullet();
        checkBulletBounds();
    }


}
/**
 * Method to move bullet
 */
void GameNs::BulletManager::moveBullet() {
    //-1 because bullet is moving up
    //change y position of bullet using time
    m_playerBullet->setYPosition(m_playerBullet->getYPosition() + m_timer->getDeltaTime() * -1 * 5);
    if(m_enemyFired)
    {
        m_enemyBullet->setYPosition(m_enemyBullet->getYPosition() + m_timer->getDeltaTime() * 1 * 5);
    }

}
/**
 * Method to check bullet boundaries
 */
void GameNs::BulletManager::checkBulletBounds() {
    //check if bullet has moved out of visible area
    if(m_playerBullet->getYPosition() < - m_playerBullet->getHeight() || m_playerBullet->getYPosition() > (m_screenHeight + m_playerBullet->getHeight()))
    {
        setPlayerBulletFired(false);
    }
    if(m_enemyFired)
    {
        if (m_enemyBullet->getYPosition() < -m_enemyBullet->getHeight() ||
            m_enemyBullet->getYPosition() > (m_screenHeight + m_enemyBullet->getHeight())) {
            setEnemyBulletFired(false);
        }
    }

}

/**
 * Return if bullet has been fired
 * @return - true or false
 */
bool GameNs::BulletManager::getPlayerBulletFired() {
    return m_playerFired;
}
/**
 * Method to set bullet
 * @param bullet - the bullet to use
 */
void GameNs::BulletManager::setPlayerBullet(Bullet* bullet){
    m_playerBullet = bullet;
}
/**
 * Method to set the state of bulletFired
 * @param isFired - state of bulletFired
 */
void GameNs::BulletManager::setPlayerBulletFired(bool isFired) {
    m_playerFired = isFired;
}

bool GameNs::BulletManager::checkPlayerCollisions() {
    for(int i=0; i<m_enemyShips.size();i++)
    {
        if(CollisionManager::checkCollision(m_playerBullet, m_enemyShips[i]->getXPosition(), m_enemyShips[i]->getYPosition(), m_enemyShips[i]->getWidth(), m_enemyShips[i]->getHeight()))
        {
            m_enemyShips[i]->close();
            m_enemyShips.erase(m_enemyShips.begin()+i);
            setPlayerBulletFired(false);
            //set bullet position to 0 after collision
            //otherwise it keeps moving
            m_playerBullet->setYPosition(0);
            m_playerBullet->close();

            return true;
        }
    }
    return false;
}
void GameNs::BulletManager::setEnemyShip(std::vector<Ship *> &enemyShips) {
    m_enemyShips = enemyShips;
}

void GameNs::BulletManager::setEnemyBullet(GameNs::Bullet *bullet) {
    m_enemyBullet = bullet;
}

void GameNs::BulletManager::setEnemyBulletFired(bool isFired) {
    m_enemyFired = isFired;
}

bool GameNs::BulletManager::getEnemyBulletFired() {
    return m_enemyFired;
}



