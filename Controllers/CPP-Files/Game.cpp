//
// Created by cliff on 08/03/2020.
//

#include <vector>
#include <iostream>
#include "../Headers/Game.h"

//static variable
GameNs::Game* GameNs::Game::m_instance = nullptr;

/**
 * Method that returns instance of Game
 * @param AF - Abstract factory class
 * @return Game object
 */
GameNs::Game* GameNs::Game::getInstance(AbstractFactory* AF) {
    if(m_instance == nullptr)
    {
        m_instance = new Game(AF);
    }
    return m_instance;
}

/**
 * Destructor
 */
GameNs::Game::~Game() {
    //Deallocate memory
    delete m_bulletManager;
    delete m_playerManager;
    delete m_enemyManager;
    delete m_bonusManager;
    delete m_collisionDetector;
    delete m_configHandler;
    delete m_playerScore;
    delete m_background;
    delete m_timer;
}

/**
 * Constructor
 * @param AF - abstract factory to create instances of objects
 */
GameNs::Game::Game(AbstractFactory* AF) {
    m_factory = AF;
    //Create timer;
    m_timer = m_factory->createTimer();

    //Create collision detector
    m_collisionDetector = new CollisionDetector();

    //Create configuration handler
    m_configHandler = new ConfigHandler();

    m_screenWidth = m_configHandler->getScreenWidth();
    m_screenHeight = m_configHandler->getScreenHeight();
}
/**
 * Method that holds the game's main loop
 */
void GameNs::Game::run() {

    //Create background
    m_background = m_factory->createBackground();
    //Create player score
    m_playerScore = m_factory->createScore();
    //Create bullet manager
    m_bulletManager = new BulletManager(m_timer, m_collisionDetector, m_configHandler);
    //Create player manager
    m_playerManager = new PlayerManager(m_factory, m_timer, m_collisionDetector, m_configHandler, m_bulletManager);
    //Create enemy manager
    m_enemyManager = new EnemyManager(m_factory, m_timer, m_collisionDetector, m_configHandler, m_bulletManager,m_playerScore);
    //Create bonus manager
    m_bonusManager = new BonusManager(m_factory, m_timer, m_collisionDetector, m_configHandler, m_playerManager,m_playerScore);

    //Game loop for updating.
    while(m_factory->isRunning())
    {
        m_timer->update();
        m_background->render();
        m_playerManager->update();
        m_enemyManager->update();
        m_bulletManager->update();
        m_bonusManager->update();
        m_playerScore->render();
        m_factory->render();
    }

}



