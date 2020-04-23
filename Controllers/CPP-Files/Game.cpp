//
// Created by cliff on 08/03/2020.
//

#include <vector>
#include <iostream>
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
GameNs::Game* GameNs::Game::getInstance(AbstractFactory* AF) {
    if(m_instance == nullptr)
    {
        m_instance = new Game(AF);
    }
    return m_instance;
}


GameNs::Game::~Game() {
    //Deallocate memory
    delete m_bulletManager;
    delete m_playerManager;
    delete m_enemyManager;
    delete m_bonusManager;
    delete m_collisionDetector;
    delete m_configHandler;
}

/**
 * Constructor
 */
GameNs::Game::Game() {}

/**
 * Constructor
 * @param AF - abstract factory to create instances of objects
 */
GameNs::Game::Game(AbstractFactory* AF) {
    m_factory = AF;
    m_timer = m_factory->createTimer();
    m_collisionDetector = new CollisionDetector();
    m_configHandler = new ConfigHandler();
    m_screenWidth = m_configHandler->getScreenWidth();
    m_screenHeight = m_configHandler->getScreenHeight();
}
/**
 * Method that holds the game's main loop
 */
void GameNs::Game::run() {

    //Create background
    Background *background = m_factory->createBackground();
    //Create player score
    m_playerScore = m_factory->createScore();
    //Create bullet manager
    m_bulletManager = new BulletManager(m_timer, m_collisionDetector, m_configHandler);
    //Create player manager
    m_playerManager = new PlayerManager(m_factory, m_bulletManager, m_timer,m_collisionDetector, m_configHandler);
    //Create enemy manager
    m_enemyManager = new EnemyManager(m_factory, m_bulletManager, m_timer, m_playerScore,m_collisionDetector, m_configHandler);
    //Create bonus manager
    m_bonusManager = new BonusManager(m_factory, m_playerManager, m_playerScore, m_collisionDetector, m_timer, m_configHandler);

    //Game loop for updating.
    while(m_factory->isRunning())
    {
        background->render();
        m_playerManager->update();
        m_enemyManager->update();
        m_bulletManager->update();
        m_bonusManager->update();
        m_playerScore->render();
        m_factory->render();
    }
    background->close();
    m_playerScore->close();

}



