/**
 * CPP file for BulletManager class
 */

#include "../Headers/BulletManager.h"
#include "../../SDL/Headers/SDLBullet.h"
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
GameNs::BulletManager::BulletManager(Bullet* bullet,std::string bulletPath,Timer* timer, int screenHeight) {
    m_bullet = bullet;
    m_timer = timer;
    m_bulletPath = bulletPath;
    m_bulletFired = false;
    m_screenHeight = screenHeight;
}
/**
 * Update method
 */
void GameNs::BulletManager::update() {
    //check if bullet has been fired
    //get out of function if it has not been fired
    if(!m_bulletFired)
    {
        return;
    }
    moveBullet();
    checkBulletBounds();
    m_bullet->render();
    //TODO collision detection
}
/**
 * Method to move bullet
 */
void GameNs::BulletManager::moveBullet() {
    //change y position of bullet using time
    m_bullet->setYPosition(m_bullet->getYPosition() + m_timer->getDeltaTime() * m_moveDirection*5);
}
/**
 * Method to check bullet boundaries
 */
void GameNs::BulletManager::checkBulletBounds() {
    //check if bullet has moved out of visible area
    if(m_bullet->getYPosition() < - m_bullet->getHeight() || m_bullet->getYPosition() > (m_screenHeight + m_bullet->getHeight()))
    {
        setBulletFired(false);
    }
}
/**
 * Method to set direction of bullet
 * @param direction - direction of bullet, ie up (-1) or down (1)
 */
void GameNs::BulletManager::setMoveDirection(int direction)
{
    m_moveDirection = direction;
}
/**
 * Return if bullet has been fired
 * @return - true or false
 */
bool GameNs::BulletManager::getBulletFired() {
    return m_bulletFired;
}
/**
 * Method to set bullet
 * @param bullet - the bullet to use
 */
void GameNs::BulletManager::setBullet(Bullet* bullet){
    m_bullet = bullet;
}
/**
 * Method to set the state of bulletFired
 * @param isFired - state of bulletFired
 */
void GameNs::BulletManager::setBulletFired(bool isFired) {
    m_bulletFired = isFired;
}

