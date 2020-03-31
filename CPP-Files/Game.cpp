//
// Created by cliff on 08/03/2020.
//

#include <vector>
#include "../Headers/Game.h"
#include "../Headers/EnemyManager.h"

Game::Game(AbstractFactory *AF) {
    m_factory = AF;
}
void Game::run() {
    m_factory->initialise(m_windowWidth,m_windowHeight);
    Background *background = m_factory->createBackground();
    Ship* playerShip = m_factory->createPlayerShip(m_playerShipPath);
    EnemyManager* manager = new EnemyManager(m_factory,m_enemyShipPath);
    manager->createEnemies(55);
    std::vector<Ship *> enemyShips = manager->getEnemies();
    /*enemyShips.reserve(10);
    enemyShips.emplace_back(m_factory->createEnemyShip(m_enemyShipPath, 50, 50));
    enemyShips.emplace_back(m_factory->createEnemyShip(m_enemyShipPath,150,50));
    enemyShips.emplace_back(m_factory->createEnemyShip(m_enemyShipPath,250,50));
    enemyShips.emplace_back(m_factory->createEnemyShip(m_enemyShipPath,350,50));
    enemyShips.emplace_back(m_factory->createEnemyShip(m_enemyShipPath,450,50));
    enemyShips.emplace_back(m_factory->createEnemyShip(m_enemyShipPath,550,50));
    enemyShips.emplace_back(m_factory->createEnemyShip(m_enemyShipPath,650,50));
    enemyShips.emplace_back(m_factory->createEnemyShip(m_enemyShipPath,750,50));
    enemyShips.emplace_back(m_factory->createEnemyShip(m_enemyShipPath,150,150));
    enemyShips.emplace_back(m_factory->createEnemyShip(m_enemyShipPath,50,150));*/

    while(m_factory->getEvents())
    {
        background->render();
        playerShip->render();
        manager->updateEnemies();
        m_factory->render();
    }
    background->close();
    playerShip->close();
    for(int i =0; i < enemyShips.size(); i ++)
    {
        enemyShips[i]->close();
    }
    //enemyShip->close();
    m_factory->close();
}