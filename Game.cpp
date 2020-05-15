#include <iostream>
#include "Game.h"

//static variable
Game* Game::m_instance = nullptr;


/**
 * Method that returns instance of Game
 * @param AF - Abstract factory class
 * @return Game object
 */
Game* Game::getInstance(Abstract::Factory* AF) {
    if(m_instance == nullptr)
    {
        m_instance = new Game(AF);
    }
    return m_instance;
}

/**
 * Destructor
 */
Game::~Game() {
    //Deallocate memory
    delete m_enemyShipController;
    delete m_playerShipController;
    delete m_controller;
    delete m_timer;
    delete m_window;
}

/**
 * Method to destroy game instance
 */
void Game::destroyGame() {
    delete m_instance;
}
/**
 * Constructor
 * @param AF - abstract factory to create instances of objects
 */
Game::Game(Abstract::Factory* AF) {
    m_factory = AF;
    //create window
    m_window = m_factory->createWindow("Space invaders",1080,720);
    if(m_window->initialise())
    {
        if(m_window->loadMedia())
        {
            std::cout << "Initialised and loaded media successfully\n";
        }
        else{
            std::cerr << "Failed to load media\n";
            exit(1);
        }
    }
    else
    {
        std::cerr << "Initialisation failed\n";
        //TODO change
        exit(1);
    }
}
/**
 * Method that holds the game's main loop
 */
void Game::run() {
    createStartObjects();
    while (!m_controller->isRunning())
    {
        m_timer->update();
        if(m_timer->getDeltaTime() >= 1.0/FRAME_RATE)
        {
            m_window->refresh();
            m_playerShipController->update();
            m_enemyShipController->update();
            m_window->render();

            //Reset timer
            m_timer->reset();
        }

    }

}

/**
 * Method used to create game start objects ie controller,player controller, enemycontroller etc.
 */
void Game::createStartObjects() {
    //Create controller
    m_controller = m_factory->createController();
    m_controller->setWindow(m_window);

    //Create timer
    m_timer = m_factory->createTimer();

    //Create player ship controller
    m_playerShipController = new PlayerShipController(m_controller, m_factory, m_timer);

    //Create enemy ship controller
    m_enemyShipController = new EnemyShipController(m_factory,m_controller,m_timer);
}





