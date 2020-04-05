//
// Created by cliff on 08/03/2020.
//

#include <vector>
#include "../Headers/Game.h"
#include "../Headers/EnemyManager.h"
#include "../Headers/PlayerManager.h"

/**
 * Method to initialise the Game class
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
    //Ship* playerShip = m_factory->createPlayerShip(m_playerShipPath);
    EnemyManager* enemyManager = new EnemyManager(m_factory, m_enemyShipPath, m_windowWidth);
    enemyManager->createEnemies(25);
    std::vector<Ship *> enemyShips = enemyManager->getEnemies();
    BulletManager::getInstance()->setEnemyShip(enemyShips);
    while(m_factory->getRunningState())
    {
        background->render();
        playerManager->update();
        //set bullet
        enemyManager->updateEnemies();
        m_factory->render();
    }
    background->close();
    playerManager->close();
    //playerShip->close();
    for(int i =0; i < enemyShips.size(); i ++)
    {
        enemyShips[i]->close();
    }
    m_factory->close();
}