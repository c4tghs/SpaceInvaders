/**
 * CPP file of PlayerManager class
 */

#include "../Headers/PlayerManager.h"

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
    m_playerShipPath = playerShipPath;
    m_bulletPath = bulletPath;
    //create playerShip;
    m_playerShip  = AF->createPlayerShip(m_playerShipPath);
    m_screenHeight = screenHeight;
    m_screenWidth = screenWidth;

    //reserve
    m_bullets.reserve(10);
    //create 10 bullets
    for(int i =0; i<10;i++)
    {
        m_bullets.emplace_back(m_factory->createBullet(m_bulletPath,m_playerShip->getXPosition(),m_playerShip->getYPosition()));
    }
    //initialise Bullet bulletManager
    bulletManager = new BulletManager(m_bullets[0],m_bulletPath,m_timer,m_screenHeight);


}
/**
 * update method
 */
void GameNs::PlayerManager::update() {
    //move player
    playerActions();
    checkPlayerBoundaries();
    //update timer
    m_timer->update();
    bulletManager->update();
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
    }
}
/**
 * Method used to check player boundaries
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
}
/**
 * Method to destory player texture
 */
void GameNs::PlayerManager::close() {
    for(int i =0; i < m_bullets.size();i++)
    {
        m_bullets[i]->close();
    }
    m_playerShip->close();

}
/**
 * Method that allows a player to shoot
 */
void GameNs::PlayerManager::shoot() {
    //if(m_timer->)
    if(bulletManager->getBulletFired())
    {
        return;
    }
    for(int i =0; i < m_bullets.size();i++)
    {

        m_bullets[i]->setXPosition(m_playerShip->getXPosition());
        m_bullets[i]->setYPosition(m_playerShip->getYPosition());
        if(bulletManager->getBulletFired())
        {
            continue;
        }
        bulletManager->setBullet(m_bullets[i]);
        bulletManager->setMoveDirection(-1);
        bulletManager->setBulletFired(true);
        //remove one bullet from vector
        m_bullets.erase(m_bullets.begin()+i);
        break; //execute this loop once
    }
    //TODO player score
}
