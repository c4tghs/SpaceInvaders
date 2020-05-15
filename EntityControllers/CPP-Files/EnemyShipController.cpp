#include "../Headers/EnemyShipController.h"

EnemyShipController::EnemyShipController(Abstract::Factory *factory, Abstract::Controller *controller, Abstract::Timer *timer) {
    m_factory = factory;
    m_controller =controller;
    m_timer = timer;
    createEnemies();
}
/**
 * Destructor
 */
EnemyShipController::~EnemyShipController() {
    for(auto & enemyShip : m_enemyShips)
    {
        delete enemyShip;
    }
}

/**
 * Method to update
 */
void EnemyShipController::update() {
    //move enemyships
    for(auto & enemyShip : m_enemyShips) {
        enemyShip->moveEntity(enemyShip->getXPosition() + (m_timer->getDeltaTime() * enemyShip->getMoveDirection() * 100),enemyShip->getYPosition());
    }
    if(checkBoundaries())
    {
        for(auto & enemyShip : m_enemyShips)
        {
            int moveDirection = enemyShip->getMoveDirection();
            if(moveDirection==1)
            {
                moveDirection = -1;
            }
            else
            {
                moveDirection = 1;
            }
            enemyShip->setMoveDirection(moveDirection);
            enemyShip->moveEntity(enemyShip->getXPosition(),enemyShip->getYPosition()+10);
        }
    }



    for(auto & enemyShip : m_enemyShips)
    {
        enemyShip->render();
    }
}

/**
 * Method to create enemies
 */
void EnemyShipController::createEnemies() {
    m_enemyShips.reserve(30);
    for(int i=0; i < 30; i++)
    {
        //m_enemyShips.emplace_back(m_factory->createEnemyShip());
        double xPos = ((i % 10) * 70) + 100;
        double yPos= ((i / 10) * 50) + 70;
        double width = m_controller->getWindow()->getWindowWidth()/25.0;
        double height = m_controller->getWindow()->getWindowHeight()/25.0;
        //Create enemy and add it to vector.
        if(i < 10)
        {
            m_enemyShips.emplace_back(m_factory->createEnemyShip(xPos,yPos,width,height,m_controller->getWindow()));
            //Set enemy type.
            m_enemyShips[i]->setEnemyType(OCTOPUS);

        }
        else if (i >= 10 && i < 20)
        {
            m_enemyShips.emplace_back(m_factory->createEnemyShip(xPos,yPos,width,height,m_controller->getWindow()));
            //Set enemy type.
            m_enemyShips[i]->setEnemyType(CRAB);
        }
        else
        {
            m_enemyShips.emplace_back(m_factory->createEnemyShip(xPos,yPos,width,height,m_controller->getWindow()));
            //Set enemy type.
            m_enemyShips[i]->setEnemyType(SQUID);
        }
    }
}

/**
 * Method to check if an enemy has reached boundary of screen or not
 * @return boolean representing if an enemy has reached boundary of screen
 */
bool EnemyShipController::checkBoundaries() {
    for(auto & enemyShip : m_enemyShips)
    {
        if((enemyShip->getXPosition() <= 0 ) or (enemyShip->getXPosition() >= m_controller->getWindow()->getWindowWidth()-enemyShip->getWidth())){
            return true;
        }
    }
    return false;
}
