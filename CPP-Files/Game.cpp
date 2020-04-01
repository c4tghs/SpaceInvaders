//
// Created by cliff on 08/03/2020.
//

#include <vector>
#include "../Headers/Game.h"
#include "../Headers/EnemyManager.h"

GameNs::Game::Game(AbstractFactory *AF) {
    m_factory = AF;
}
void GameNs::Game::run() {
    m_factory->initialise(m_windowWidth,m_windowHeight);
    Background *background = m_factory->createBackground();
    Ship* playerShip = m_factory->createPlayerShip(m_playerShipPath);
    EnemyManager* manager = new EnemyManager(m_factory,m_enemyShipPath);
    manager->createEnemies(50);
    std::vector<Ship *> enemyShips = manager->getEnemies();

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