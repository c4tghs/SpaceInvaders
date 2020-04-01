//
// Created by cliff on 01/04/2020.
//

#include "../Headers/PlayerManager.h"
GameNs::PlayerManager::PlayerManager() {

}
GameNs::PlayerManager::PlayerManager(GameNs::AbstractFactory *AF,std::string playerShipPath,int screenHeight, int screenWidth){
    m_factory = AF;
    m_timer = new SDLNs::SDLTimer();
    m_playerShipPath = playerShipPath;
    m_playerShip  = AF->createPlayerShip(m_playerShipPath);
    m_screenHeight = screenHeight;
    m_screenWidth = screenWidth;
    m_shipHeight = m_screenHeight/10;
    m_shipWidth = m_screenWidth/10;
    m_playerShip->setXPosition((m_screenWidth/2)-50);
    m_playerShip->setYPosition(m_screenHeight-(m_shipHeight+10));
}
void GameNs::PlayerManager::update() {
    //move player
    movePlayer();
    checkPlayerBoundaries();
    //update timer
    m_timer->update();
    //render player
    m_playerShip->render();
}
void GameNs::PlayerManager::movePlayer() {
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
            //TODO add space in keystates so player can shoot
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
    m_playerShip->close();
}