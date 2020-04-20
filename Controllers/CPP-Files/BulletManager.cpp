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
GameNs::BulletManager::BulletManager(Timer *timer, CollisionDetector *collisionDetector, int screenHeight) {
    m_timer = timer;
    m_collisionDetector = collisionDetector;
    m_playerFired = false;
    m_screenHeight = screenHeight;
}
/**
 * Update method
 */
void GameNs::BulletManager::update() {
    //Check if bullet has been fired
    //If so, render bullet
    if(m_playerFired)
    {
        m_playerBullet->render();
    }
    if(m_enemyFired)
    {
        m_enemyBullet->render();
    }
    //If enemy or player bullet has been fired, execute the following methods.
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
    bulletsCollision();
    setPlayerBulletCollision(false);

}
/**
 * Method to move bullet
 */
void GameNs::BulletManager::moveBullet() {
    //-1 because bullet is moving up.
    //Change y position of bullet using time.
    if(m_playerFired)
    {
        m_playerBullet->setYPosition(m_playerBullet->getYPosition() + m_timer->getDeltaTime() * -1 * 5);
    }
    //1 because bullet is moving down.
    //Change y position of bullet using time
    if(m_enemyFired)
    {
        m_enemyBullet->setYPosition(m_enemyBullet->getYPosition() + m_timer->getDeltaTime() * 1 * 5);
    }

}
/**
 * Method to check bullet boundaries
 */
void GameNs::BulletManager::checkBulletBounds() {
    //Check if bullet has moved out of visible area
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
            m_enemyBullet->getYPosition() > (m_screenHeight + m_enemyBullet->getHeight()))
        {
            setEnemyBulletFired(false);
        }
    }

}

/**
 * Method to check if player bullet has been fired
 * @return - true or false
 */
bool GameNs::BulletManager::isPlayerBulletFired() {
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
 * Method to set if player has fired a bullet
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

/**
 * Method to set if enemy has fired a bullet
 * @param isFired - if bullet is fired
 */
void GameNs::BulletManager::setEnemyBulletFired(bool isFired) {
    m_enemyFired = isFired;
}

/**
 * Method to check if enemy has fired a bullet
 * @return true of false
 */
bool GameNs::BulletManager::isEnemyBulletFired() {
    return m_enemyFired;
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
    if(m_playerFired and m_enemyFired)
    {

        if(m_collisionDetector->twoBulletsCollision(m_playerBullet, m_enemyBullet))
        {
            m_playerBullet->setYPosition(0);
            m_enemyBullet->setYPosition(m_screenHeight+5);
        }
    }
}



