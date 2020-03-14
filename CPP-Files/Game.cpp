//
// Created by cliff on 08/03/2020.
//

#include "../Headers/Game.h"
Game::Game(AbstractFactory *AF) {
    m_factory = AF;
}
void Game::run() {
    m_factory->initialise(m_windowWidth,m_windowHeight);
    Background *background = m_factory->createBackground();
    Ship* playerShip = m_factory->createPlayerShip(m_playerShipPath);

    while(m_factory->getEvents())
    {
        background->render();
        playerShip->render();
        m_factory->render();
    }
}