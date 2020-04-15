//
// Created by cliff on 14/04/2020.
//

#include "../Headers/BonusManager.h"
#include "../../Models/Headers/RandomNumber.h"

/**
 * Constructor
 * @param AF - abstract factory
 * @param playerManager - player manager
 */
GameNs::BonusManager::BonusManager(AbstractFactory *AF, PlayerManager *playerManager, PlayerLife *playerLife,
                                   Score *score, Timer *timer,
                                   int screenWidth, int screenHeight) {
    m_timer = timer;
    m_playerShip = playerManager->getPlayerShip();
    m_factory = AF;
    m_screenWidth = screenWidth;
    m_screenHeight = screenHeight;
    m_playerLife = playerLife;
    m_playerSCore = score;
    createBonuses();
    m_nextBonus = m_timer->getTime()+ GameNs::RandomNumber::getInstance()->getRandomNumber(1,10);
}

/**
 * Method for updating
 */
void GameNs::BonusManager::update() {
    //update times
    m_timer->update();
    if((m_timer->getTime() >= m_nextBonus) && !m_moveBonus)
    {
        m_moveBonus = true;
        selectBonus();
    }
    if(m_moveBonus)
    {
        moveBonus();
        checkCollisions();
        if(m_bonuses[m_randomId]->getYPosition() > m_screenHeight)
        {
            m_moveBonus = false;
        }
    }
    //render bonus
    render();
}
/**
 * Method to create bonusses
 */
void GameNs::BonusManager::createBonuses() {
    m_bonuses.reserve(10);
    BonusType type;
    std::string filePath;
    int width = m_screenWidth/30;
    int height = m_screenWidth/30;
    int xPos;
    for(int i=0; i < 10; i++)
    {
        //get random type
        type = BonusType(GameNs::RandomNumber::getInstance()->getRandomNumber(0,3));
        if(type== BonusType::POINTS)
        {
            filePath = m_bonusPoints;
        } else if (type== BonusType::LIFE)
        {
            filePath = m_bonusLife;
        } else if (type== BonusType::SPEED)
        {
            filePath = m_bonusSpeed;
        }
        //random x position for bonus
        xPos = GameNs::RandomNumber::getInstance()->getRandomNumber(0,m_screenWidth);
        m_bonuses.emplace_back(m_factory->createBonus(filePath,xPos,-50,width,height));
        m_bonuses[i]->setBonusType(type);
    }
}

/**
 * Method to render
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
    m_bonuses[m_randomId]->setYPosition(m_bonuses[m_randomId]->getYPosition()+m_timer->getDeltaTime()*5);
}
/**
 * Method to select random bonus and set next bonus' time
 */
void GameNs::BonusManager::selectBonus() {

    m_randomId = GameNs::RandomNumber::getInstance()->getRandomNumber(0,m_bonuses.size());
    m_nextBonus = m_timer->getTime()+ GameNs::RandomNumber::getInstance()->getRandomNumber(1,10);
}
/**
 * Method to check collisions
 */
void GameNs::BonusManager::checkCollisions() {
    BonusType bonusType;
    if(CollisionManager::getInstance()->checkBonusCollision(m_bonuses[m_randomId],m_playerShip))
    {
        m_bonuses[m_randomId]->setYPosition(m_screenHeight+10);
        bonusType = m_bonuses[m_randomId]->getBonusType();
        if(bonusType == BonusType::SPEED)
        {
            m_playerShip->setPlayerSpeed(m_playerShip->getPlayerSpeed()+0.5);
        } else if (bonusType == BonusType::LIFE)
        {
            m_playerLife->setPlayerLife(m_playerLife->getPlayerLife()+1);
        } else if (bonusType == BonusType::POINTS)
        {
            m_playerSCore->setScores(m_playerSCore->getScores()+10);
        }

    }
}

/**
 * Method to destroy bonus textures
 */
void GameNs::BonusManager::close() {
    for(auto &bonus:m_bonuses)
    {
        bonus->close();
    }
}
