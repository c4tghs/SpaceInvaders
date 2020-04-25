/**
 * CPP file for BulletManager class
 */

#include "../Headers/BulletManager.h"

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
GameNs::BulletManager::BulletManager(Timer *timer, CollisionDetector *collisionDetector, ConfigHandler *configHandler) {
    m_timer = timer;
    m_collisionDetector = collisionDetector;
    m_pBulletInFlight = false;
    m_configHandler = configHandler;
    m_screenHeight = m_configHandler->getScreenWidth();
    m_bulletSpeed = m_configHandler->getBulletSpeed();
}
/**
 * Update method
 */
void GameNs::BulletManager::update() {
    //Check if bullet has been fired
    //If so, render bullet
    if(m_pBulletInFlight)
    {
        m_playerBullet->render();
    }
    if(m_eBulletInFlight)
    {
        m_enemyBullet->render();
    }
    //If enemy or player bullet has been fired, execute the following methods.
    if(m_pBulletInFlight or m_eBulletInFlight)
    {
        moveBullet();
        checkBulletBounds();
    }
    if(m_playerBulletCollided)
    {
        m_playerBullet->setYPosition(0);
    }
    bulletsCollision();
    setPlayerBulletCollision(false);

}
/**
 * Method to move bullet
 */
void GameNs::BulletManager::moveBullet() {
    //-1 because bullet is moving up.
    //Change y position of bullet using time.
    if(m_pBulletInFlight)
    {
        m_playerBullet->setYPosition(m_playerBullet->getYPosition() + m_timer->getDeltaTime() * -1 * m_bulletSpeed);
    }
    //1 because bullet is moving down.
    //Change y position of bullet using time
    if(m_eBulletInFlight)
    {
        m_enemyBullet->setYPosition(m_enemyBullet->getYPosition() + m_timer->getDeltaTime() * 1 * m_bulletSpeed);
    }

}
/**
 * Method to check bullet boundaries
 */
void GameNs::BulletManager::checkBulletBounds() {
    //Check if bullet has moved out of visible area
    if(m_pBulletInFlight)
    {
        if(m_playerBullet->getYPosition() < - m_playerBullet->getHeight() || m_playerBullet->getYPosition() > (m_screenHeight + m_playerBullet->getHeight()))
        {
            setPlayerBulletInFlight(false);
        }
    }
    if(m_eBulletInFlight)
    {
        if (m_enemyBullet->getYPosition() < -m_enemyBullet->getHeight() ||
            m_enemyBullet->getYPosition() > (m_screenHeight + m_enemyBullet->getHeight()))
        {
            setEnemyBulletInFlight(false);
        }
    }

}

/**
 * Method to check if player bullet is in flight
 * @return boolean
 */
bool GameNs::BulletManager::isPlayerBulletInFlight() {
    return m_pBulletInFlight;
}
/**
 * Method to set player bullet
 * @param bullet - the bullet to use
 */
void GameNs::BulletManager::setPlayerBullet(Bullet* bullet){
    m_playerBullet = bullet;
}
/**
 * Method to set whether player bullet is in flight
 * @param inFlight - state of bulletFired
 */
void GameNs::BulletManager::setPlayerBulletInFlight(bool inFlight) {
    m_pBulletInFlight = inFlight;
}

/**
 * Method that sets enemy bullet
 * @param bullet - the enemy bullet
 */
void GameNs::BulletManager::setEnemyBullet(GameNs::Bullet *bullet) {
    m_enemyBullet = bullet;
}

/**
 * Method to set if enemy has fired a bullet
 * @param isFlight - if bullet is fired
 */
void GameNs::BulletManager::setEnemyBulletInFlight(bool isFlight) {
    m_eBulletInFlight = isFlight;
}

/**
 * Method to check if enemy has fired a bullet
 * @return true of false
 */
bool GameNs::BulletManager::isEnemyBulletInFlight() {
    return m_eBulletInFlight;
}
/**
 * Method to get current player bullet
 * @return - bullet
 */
GameNs::Bullet *GameNs::BulletManager::getPlayerBullet() {
    return m_playerBullet;
}
/**
 * Method to set if player bullet has collided with enemy
 * @param isCollided
 */
void GameNs::BulletManager::setPlayerBulletCollision(bool isCollided) {
    m_playerBulletCollided = isCollided;
}
/**
 * Method to get current enemy bullet
 * @return - bullet
 */
GameNs::Bullet *GameNs::BulletManager::getEnemyBullet() {
    return m_enemyBullet;
}
/**
 * Method to check collision between player and enemy bullet
 */
void GameNs::BulletManager::bulletsCollision() {
    //If both enemy and player bullets are moving or not out of visible area, check for collision
    if(m_pBulletInFlight and m_eBulletInFlight)
    {

        if(m_collisionDetector->twoBulletsCollision(m_playerBullet, m_enemyBullet))
        {
            m_playerBullet->setYPosition(0);
            m_enemyBullet->setYPosition(m_screenHeight+5);
        }
    }
}



