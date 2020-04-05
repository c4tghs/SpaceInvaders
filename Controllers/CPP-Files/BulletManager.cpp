/**
 * CPP file for BulletManager class
 */

#include "../Headers/BulletManager.h"
#include "../../SDL/Headers/SDLBullet.h"

//static member
GameNs::BulletManager* GameNs::BulletManager::m_instance =0;

GameNs::BulletManager* GameNs::BulletManager::getInstance() {
    if(m_instance ==0)
    {
        m_instance = new BulletManager();
    }
    return m_instance;
}
GameNs::BulletManager* GameNs::BulletManager::getInstance(Bullet *bullet, std::string bulletPath, Timer *timer, int screenHeight)  {
    if(m_instance ==0)
    {
        m_instance = new BulletManager(bullet,bulletPath,timer,screenHeight);
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
GameNs::BulletManager::BulletManager(Bullet* bullet,std::string bulletPath,Timer* timer, int screenHeight) {
    m_bullet = bullet;
    m_timer = timer;
    m_bulletPath = bulletPath;
    m_bulletFired = false;
    m_screenHeight = screenHeight;
    m_collisionManager = CollisionManager::getInstance();
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
    //checkPlayerCollisions();

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

bool GameNs::BulletManager::checkPlayerCollisions() {
    for(int i=0; i<m_enemyShips.size();i++)
    {
        if(CollisionManager::checkCollision(m_bullet,m_enemyShips[i]->getXPosition(),m_enemyShips[i]->getYPosition(),m_enemyShips[i]->getWidth(),m_enemyShips[i]->getHeight()))
        {
            m_enemyShips[i]->close();
            m_enemyShips.erase(m_enemyShips.begin()+i);
            setBulletFired(false);
            //set bullet position to 0 after collision
            //otherwise it keeps moving
            m_bullet->setYPosition(0);
            m_bullet->close();
            printf("The size is now %d\n",m_enemyShips.size());
            return true;
        }
    }
    return false;
}
void GameNs::BulletManager::setEnemyShip(std::vector<Ship *> enemyShips) {
    m_enemyShips = enemyShips;
}



