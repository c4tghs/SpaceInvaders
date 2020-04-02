//
// Created by cliff on 01/04/2020.
//

#include "../Headers/PlayerManager.h"
GameNs::PlayerManager::PlayerManager() {

}
GameNs::PlayerManager::PlayerManager(GameNs::AbstractFactory *AF,std::string playerShipPath,std::string bulletPath,int screenHeight, int screenWidth){
    m_factory = AF;
    m_timer = AF->createTimer();
    m_playerShipPath = playerShipPath;
    m_bulletPath = bulletPath;
    //create playerShip;
    m_playerShip  = AF->createPlayerShip(m_playerShipPath);
    m_screenHeight = screenHeight;
    m_screenWidth = screenWidth;
    m_shipHeight = m_screenHeight/10;
    m_shipWidth = m_screenWidth/10;

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
void GameNs::PlayerManager::checkPlayerBoundaries() {
    if(m_playerShip->getXPosition() < 0)
    {
        m_playerShip->setXPosition(0);
    }
    else if(m_playerShip->getXPosition() > m_screenWidth -m_shipWidth)
    {
        m_playerShip->setXPosition(m_screenWidth -m_shipWidth);

    }
}
void GameNs::PlayerManager::close() {
    for(int i =0; i < m_bullets.size();i++)
    {
        m_bullets[i]->close();
    }
    m_playerShip->close();

}
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
        break;
    }
    //TODO player score
}
