//
// Created by cliff on 08/03/2020.
//

#include <vector>
#include "../Headers/Game.h"

//static variable
GameNs::Game* GameNs::Game::m_instance = nullptr;

GameNs::Game* GameNs::Game::getInstance() {
    if(m_instance == nullptr)
    {
        m_instance = new Game();
    }
    return m_instance;
}
GameNs::Game* GameNs::Game::getInstance(AbstractFactory *AF) {
    if(m_instance == nullptr)
    {
        m_instance = new Game(AF);
    }
    return m_instance;
}

/**
 * Constructor
 */
GameNs::Game::Game() {

}

/**
 * Constructor
 * @param AF - abstract factory to create instances of objects
 */
GameNs::Game::Game(AbstractFactory *AF) {
    m_factory = AF;
    m_timer = m_factory->createTimer();
}
/**
 * Method that holds the game's main loop
 */
void GameNs::Game::run() {
    m_factory->initialise(m_screenWidth, m_screenHeight);
    Background *background = m_factory->createBackground();
    m_bulletManager = new BulletManager(m_timer, m_screenHeight);
    m_playerManager = new PlayerManager(m_factory, m_screenHeight, m_screenWidth, m_bulletManager, m_timer);
    m_enemyManager = new EnemyManager(m_factory, m_screenWidth, m_screenHeight, m_bulletManager, m_timer);


    while(m_factory->getRunningState())
    {
        background->render();
        m_playerManager->update();
        m_enemyManager->updateEnemies();
        m_bulletManager->update();
        m_factory->render();
    }
    background->close();
    m_playerManager->close();
    m_enemyManager->close();
    m_factory->close();
}
/**
 * Method to initialise game objects
 */
void GameNs::Game::initialise() {

}


