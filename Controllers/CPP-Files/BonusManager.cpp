//
// Created by cliff on 14/04/2020.
//

#include <iostream>
#include "../Headers/BonusManager.h"
#include "../../Models/Headers/RandomNumber.h"

/**
 * Constructor
 * @param AF - abstract factory
 * @param playerManager - player manager
 */
GameNs::BonusManager::BonusManager(AbstractFactory *AF, Timer *timer, CollisionDetector *collisionDetector,
                                   ConfigHandler *configHandler,
                                   PlayerManager *playerManager, Score *score) {
    m_timer = timer;
    m_playerShip = playerManager->getPlayerShip();
    m_factory = AF;
    m_configHandler=configHandler;
    m_screenWidth = configHandler->getScreenWidth();
    m_screenHeight = configHandler->getScreenHeight();
    m_playerLife = playerManager->getPlayerLife();
    m_playerSCore = score;
    m_collisionDetector = collisionDetector;
    m_bonusSpeed = m_configHandler->getBonusSpeed();

    //Create bonuses.
    createBonuses();

    //Set time for next bonus.
    m_nextBonus = m_timer->getTime()+ GameNs::RandomNumber::getInstance().getRandomDouble(1, 10);
}

/**
 * Destructor
 */
GameNs::BonusManager::~BonusManager() {
    for(auto &bonus:m_bonuses)
    {
        delete bonus;
    }
}

/**
 * Method for updating
 */
void GameNs::BonusManager::update() {
    if((m_timer->getTime() >= m_nextBonus) && !m_moveBonus)
    {
        m_moveBonus = true;
        selectBonus();
    }
    //If a m_moveBonus is true, move the bonus and check for collisions.
    if(m_moveBonus)
    {
        moveBonus();
        checkCollisions();
        if(m_bonuses[m_randomId]->getYPosition() > m_screenHeight)
        {
            m_moveBonus = false;
        }
    }
    //Render bonus.
    render();
}
/**
 * Method to create bonusses
 */
void GameNs::BonusManager::createBonuses() {
    //Reserve memory for 10 bonuses.
    m_bonuses.reserve(10);
    BonusType type;
    std::string filePath;
    //Bonus width.
    int width = m_screenWidth/30;
    //Bonus height.
    int height = m_screenWidth/30;
    int xPos;
    for(int i=0; i < 10; i++)
    {
        //Get random type.
        type = BonusType(GameNs::RandomNumber::getInstance().getRandomDouble(0, 3));
        if(type== BonusType::POINTS)
        {
            filePath = m_configHandler->getPathBonusPoints();
        } else if (type== BonusType::LIFE)
        {
            filePath = m_configHandler->getPathBonusLife();
        } else if (type== BonusType::SPEED)
        {
            filePath = m_configHandler->getPathBonusSpeed();
        }
        //Random x position for bonus
        xPos = GameNs::RandomNumber::getInstance().getRandomDouble(0, m_screenWidth);
        //Create bonus and add it to vector.
        m_bonuses.emplace_back(m_factory->createBonus(filePath,xPos,-50,width,height));
        //Set type for the created bonus.
        m_bonuses[i]->setBonusType(type);
    }
}

/**
 * Method to render bonuses.
 */
void GameNs::BonusManager::render() {

   for(auto &bonus:m_bonuses)
    {
        bonus->render();
    }
}

/**
 * Method to move bonus
 */
void GameNs::BonusManager::moveBonus() {
    //Set Y position of bonus using time.
    m_bonuses[m_randomId]->setYPosition(m_bonuses[m_randomId]->getYPosition()+m_timer->getDeltaTime()*m_bonusSpeed);
}
/**
 * Method to select random bonus and set next bonus' time
 */
void GameNs::BonusManager::selectBonus() {
    //Get random number between 0 en size of bonus vector.
    m_randomId = GameNs::RandomNumber::getInstance().getRandomDouble(0, m_bonuses.size());
    //Set next bonus time.
    m_nextBonus = m_timer->getTime()+ GameNs::RandomNumber::getInstance().getRandomDouble(1, 10);
}
/**
 * Method to check collisions
 */
void GameNs::BonusManager::checkCollisions() {
    BonusType bonusType;
    //If there's collision between bonus and player ship:
    if(m_collisionDetector->checkBonusCollision(m_bonuses[m_randomId], m_playerShip))
    {
        //Set Y position of bonus -> move out visible area
        m_bonuses[m_randomId]->setYPosition(m_screenHeight+10);
        //Get bonus type
        bonusType = m_bonuses[m_randomId]->getBonusType();
        //Based on bonus type, perform the following:
        //Change player speed, add life, change player score.
        if(bonusType == BonusType::SPEED)
        {
            m_playerShip->setPlayerSpeed(m_playerShip->getPlayerSpeed()+1);
        } else if (bonusType == BonusType::LIFE)
        {
            m_playerLife->setPlayerLife(m_playerLife->getPlayerLife()+1);
        } else if (bonusType == BonusType::POINTS)
        {
            m_playerSCore->setScores(m_playerSCore->getScores()+10);
        }

    }
}

