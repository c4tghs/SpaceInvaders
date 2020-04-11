//
// Created by cliff on 08/03/2020.
//

#include <vector>
#include "../Headers/Game.h"
#include "../Headers/EnemyManager.h"
#include "../Headers/PlayerManager.h"

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
}
/**
 * Method that holds the game's main loop
 */
void GameNs::Game::run() {
    m_factory->initialise(m_windowWidth,m_windowHeight);
    Background *background = m_factory->createBackground();
    PlayerManager* playerManager = new PlayerManager(m_factory,m_playerShipPath,m_playerBulletPath,m_windowHeight,m_windowWidth);
    EnemyManager* enemyManager = new EnemyManager(m_factory, m_windowWidth);

    while(m_factory->getRunningState())
    {
        background->render();
        playerManager->update();
        enemyManager->updateEnemies();
        m_factory->render();
    }
    background->close();
    playerManager->close();
    enemyManager->close();
    m_factory->close();
}


