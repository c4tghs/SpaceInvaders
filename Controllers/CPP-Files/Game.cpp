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
 * @return Game object
 */
GameNs::Game* GameNs::Game::getInstance()
{
    if(m_instance == nullptr)
    {
        m_instance = new Game();
    }
    return m_instance;
}

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
    delete m_collisionDetector;
    delete m_configHandler;
    delete m_background;
    delete m_timer;
    delete m_levelController;
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
    //Create timer;
    m_timer = m_factory->createTimer();

    //Create collision detector
    m_collisionDetector = new CollisionDetector();

    //Create configuration handler
    m_configHandler = new ConfigHandler();

    m_screenWidth = m_configHandler->getScreenWidth();
    m_screenHeight = m_configHandler->getScreenHeight();

    //Create level controller
    m_levelController = new LevelController(m_factory, m_timer, m_collisionDetector, m_configHandler);
}
/**
 * Method that holds the game's main loop
 */
void GameNs::Game::run() {
    //Create background
    m_background = m_factory->createBackground();
    //Set game level
    m_levelController->setLevel(1);
    //Create objects
    m_levelController->startLevel();

    //Game loop for updating.
    while(m_factory->isRunning())
    {
        if(m_levelCompleted)
        {
            m_levelCompleted=false;
            m_currentGameLevel = m_currentGameLevel+1;
            m_levelController->setLevel(m_currentGameLevel);
            m_levelController->clean();
            m_levelController->startLevel();
        }
        m_background->render();
        m_timer->update();
        m_levelController->update();
        m_factory->render();
    }

}

/**
 * Method to set that a level has been completed
 * @param isCompleted
 */
void GameNs::Game::setLeveLCompleted(bool isCompleted) {
    m_levelCompleted = isCompleted;
}



