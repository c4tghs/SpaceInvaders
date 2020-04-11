/**
 * CPP file for BulletManager class
 */

#include "../Headers/BulletManager.h"
#include <iostream>

//static member
GameNs::BulletManager* GameNs::BulletManager::m_instance =nullptr;

GameNs::BulletManager* GameNs::BulletManager::getInstance() {
    if(m_instance == nullptr)
    {
        m_instance = new BulletManager();
    }
    return m_instance;
}
GameNs::BulletManager * GameNs::BulletManager::getInstance(Timer *timer, int screenHeight) {
    if(m_instance ==nullptr)
    {
        m_instance = new BulletManager(timer, screenHeight);
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
GameNs::BulletManager::BulletManager(Timer *timer, int screenHeight) {
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
    if(m_playerBulletCollided)
    {
        m_playerBullet->setYPosition(0);
        m_playerBullet->close();
    }

}
/**
 * Method to move bullet
 */
void GameNs::BulletManager::moveBullet() {
    //-1 because bullet is moving up
    //change y position of bullet using time
    if(m_playerFired)
    {
        m_playerBullet->setYPosition(m_playerBullet->getYPosition() + m_timer->getDeltaTime() * -1 * 5);
    }
    //1 because bullet is moving down
    //change y position of bullet using time
    if(m_enemyFired)
    {
        m_enemyBullet->setYPosition(m_enemyBullet->getYPosition() + m_timer->getDeltaTime() * 1 * 10);
    }

}
/**
 * Method to check bullet boundaries
 */
void GameNs::BulletManager::checkBulletBounds() {
    //check if bullet has moved out of visible area
    if(m_playerFired)
    {
        if(m_playerBullet->getYPosition() < - m_playerBullet->getHeight() || m_playerBullet->getYPosition() > (m_screenHeight + m_playerBullet->getHeight()))
        {
            setPlayerBulletFired(false);
        }
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

/**
 * Method that to check if player bullet has collided with an enemy
 * @return true or false
 */
bool GameNs::BulletManager::checkPlayerCollisions() {
    return m_playerBulletCollided;
}

/**
 * Method that sets enemy bullet
 * @param bullet - the enemy bullet
 */
void GameNs::BulletManager::setEnemyBullet(GameNs::Bullet *bullet) {
    m_enemyBullet = bullet;
}

void GameNs::BulletManager::setEnemyBulletFired(bool isFired) {
    m_enemyFired = isFired;
}

bool GameNs::BulletManager::getEnemyBulletFired() {
    return m_enemyFired;
}

GameNs::Bullet *GameNs::BulletManager::getPlayerBullet() {
    return m_playerBullet;
}

void GameNs::BulletManager::setPlayerBulletCollision(bool collided) {
    m_playerBulletCollided = collided;
}

GameNs::Bullet *GameNs::BulletManager::getEnemyBullet() {
    return m_enemyBullet;
}



