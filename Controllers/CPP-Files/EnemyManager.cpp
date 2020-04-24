/**
 * CPP file for EnemyManager class
 */

#include <iostream>
#include "../Headers/EnemyManager.h"
#include "../../Models/Headers/RandomNumber.h"
#include "../Headers/ConfigHandler.h"


/**
 * Constructor
 */
GameNs::EnemyManager::EnemyManager() {}
/**
 *EnemyManager constructor
 * @param AF - abstract factory used to create instances of enemy ships
 * @param enemyShipPath - path to image of enemyShip
 * @param screenHeight - height of screen
 * @param screenWidth - width of screen
 */
GameNs::EnemyManager::EnemyManager(AbstractFactory *AF, Timer *timer, CollisionDetector *collisionDetector,
                                   ConfigHandler *configHandler,
                                   BulletManager *bulletManager, Score *score)
{
    m_factory = AF;
    m_timer =timer;
    m_screenWidth = configHandler->getScreenWidth();
    m_screenHeight = configHandler->getScreenHeight();
    m_bulletManager = bulletManager;
    m_collisionDetector = collisionDetector;
    m_configHandler = configHandler;
    //Get current time and add random between 0 and 3 to it
    m_nextMissile = m_timer->getTime()+ GameNs::RandomNumber::getInstance().getRandomDouble(0, 3);
    //Reserve memory for 100 bullets.
    m_bullets.reserve(100);
    //Create bullets
    createBullets();
    //Create enemies
    createEnemies(30);
    m_score = score;
}
GameNs::EnemyManager::~EnemyManager() {
    for(auto & enemyShip : m_enemyShips)
    {
        delete enemyShip;
    }
}

/**
 * Method used to create enemy instances
 * @param number - number of enemy instances to create
 */
void GameNs::EnemyManager::createEnemies(int number) {
    //Reserve memory for requested amount of enemies
    m_enemyShips.reserve(number);
    for(int i =0; i < number; i++)
    {
        int xPos = ((i % 10) * 70) + 100;
        int yPos= ((i / 10) * 50) + 70;
        //Create enemy and add it to vector.
        if(i < 10)
        {
            m_enemyShips.emplace_back(m_factory->createEnemyShip(m_spriteSheet, xPos, yPos,m_timer));
            //Set enemy type.
            m_enemyShips[i]->setEnemyType(Octopus);
            //Set enemy type
            m_enemyShips[i]->setEnemySpeed(m_configHandler->getEnemySpeed());
            //Sprite rectangular area octopus
            SDL_Rect spriteClips[SPRITES_FRAMES];
            //Closed
            spriteClips[0] = {315,35,45,35};
            //Open
            spriteClips[1] = {257,35,45,35};
            m_enemyShips[i]->setRect(spriteClips);
        }
        else if (i >= 10 && i < 20)
        {
            m_enemyShips.emplace_back(m_factory->createEnemyShip(m_spriteSheet, xPos, yPos,m_timer));
            //Set enemy type.
            m_enemyShips[i]->setEnemyType(Crab);
            //Set enemy type
            m_enemyShips[i]->setEnemySpeed(m_configHandler->getEnemySpeed());
            //Sprite rectangular area octopus
            SDL_Rect spriteClips[SPRITES_FRAMES];
            spriteClips[0] = {126,35,45,35};
            spriteClips[1] = {186,35,45,35};
            m_enemyShips[i]->setRect(spriteClips);
        }
        else
        {
            m_enemyShips.emplace_back(m_factory->createEnemyShip(m_spriteSheet, xPos, yPos,m_timer));
            //Set enemy type.
            m_enemyShips[i]->setEnemyType(Squid);
            //Set enemy type
            m_enemyShips[i]->setEnemySpeed(m_configHandler->getEnemySpeed());
            //Sprite rectangular area octopus
            SDL_Rect spriteClips[SPRITES_FRAMES];
            spriteClips[0] = {64,35,30,35};
            spriteClips[1] = {6,35,30,35};
            m_enemyShips[i]->setRect(spriteClips);
        }

    }
}

/**
 * Method to update enemies, ie direction, rendering
 */
void GameNs::EnemyManager::update() {
    //Move enemies.
    moveEnemies();
    //If an enemy has reached boundary, ie width of screen or 0, change direction.
    if(checkEnemyBoundaries())
    {
        for(auto & m_enemyShip : m_enemyShips)
        {
            int moveDirection = m_enemyShip->getMoveDirection();
            if(moveDirection==1)
            {
                moveDirection = -1;
            }
            else
            {
                moveDirection = 1;
            }
            m_enemyShip->setMoveDirection(moveDirection);
            m_enemyShip->setXPosition(m_enemyShip->getXPosition());
            //Move enemy down.
            m_enemyShip->setYPosition(m_enemyShip->getYPosition()+10);
        }
    }
    int i = 0;
    for(auto & m_enemyShip : m_enemyShips)
    {
        //Check collision with player bullet
        if(m_bulletManager->isPlayerBulletFired())
        {
            if(m_collisionDetector->checkBulletCollision(m_bulletManager->getPlayerBullet(), m_enemyShip->getXPosition(),
                                                       m_enemyShip->getYPosition(), m_enemyShip->getWidth(),m_enemyShip->getHeight()))
            {
                //Set player score.
                if(m_enemyShip->getEnemyType() == EnemyType::Squid)
                {
                    m_score->setScores(m_score->getScores()+1);
                }
                else if (m_enemyShip->getEnemyType() == EnemyType::Crab)
                {
                    m_score->setScores(m_score->getScores()+3);
                }
                else if(m_enemyShip->getEnemyType() == EnemyType::Octopus)
                {
                    m_score->setScores(m_score->getScores()+5);
                }

                //Close enemy ship, ie destroy texture
                delete m_enemyShip;
                //m_enemyShip->close();

                //Remove ship from vector
                m_enemyShips.erase(m_enemyShips.begin()+i);
                m_bulletManager->setPlayerBulletFired(false);
                m_bulletManager->setPlayerBulletCollision(true);
                //Execute once
                return;
            }
        }

        i++;
        m_enemyShip->render();
    }
    //Allow enemy to shoot
    enemyShoot();
    //End game if all enemies are dead
    if(m_enemyShips.empty())
    {
        m_factory->setRunningState(false);
    }
 }
/**
 * Method to move enemies across screen
 */
void GameNs::EnemyManager::moveEnemies(){
    for(auto & m_enemyShip : m_enemyShips){
        m_enemyShip->setXPosition(m_enemyShip->getXPosition()+ m_timer->getDeltaTime()*m_enemyShip->getMoveDirection()*m_enemyShip->getEnemySpeed());
    }
}
/**
 * Method to check if an enemy has hit a boundary
 * @return True of False
 */
bool GameNs::EnemyManager::checkEnemyBoundaries() {
    for(auto & m_enemyShip : m_enemyShips) {
        if((m_enemyShip->getXPosition() <= 0 ) or (m_enemyShip->getXPosition() >= m_screenWidth-m_enemyShip->getWidth())){
            return true;
        }
        //Player has been reached
        if(m_enemyShip->getYPosition() >= m_configHandler->getPlayerShipYPos())
        {
            m_factory->setRunningState(false);
        }
    }
    return false;
}

/**
 * Method that allows an enemy to shoot
 */
void GameNs::EnemyManager::enemyShoot() {
    //Get out of function if it's not time for enemy to shoot.
    //Get out of function if there're no enemy ships left.
    //Get out of function if an enemy has already fired.
    if((m_timer->getTime() < m_nextMissile/2) or m_enemyShips.empty() or m_bulletManager->isEnemyBulletFired())
    {
        return;
    }

    //Generate random number -> enemy to select
    int randomId = GameNs::RandomNumber::getInstance().getRandomInt(0,m_enemyShips.size());

    //Set initial position of bullet.
    m_bullets[0]->setXPosition(m_enemyShips[randomId]->getXPosition()+20);
    m_bullets[0]->setYPosition(m_enemyShips[randomId]->getYPosition());
    m_bulletManager->setEnemyBulletFired(true);
    //Set enemy bullet.
    m_bulletManager->setEnemyBullet(m_bullets[0]);
    m_bullets.erase(m_bullets.begin());

    //Create bullets if there're no more bullets left.
    if(m_bullets.empty())
    {
        createBullets();
    }
    //Set time for next bullet.
    m_nextMissile = m_timer->getTime()+ GameNs::RandomNumber::getInstance().getRandomDouble(0, 3);
}
/**
 * Method to create bullets
 */
void GameNs::EnemyManager::createBullets() {
    for(int i =0; i<50;i++)
    {
        m_bullets.emplace_back(m_factory->createBullet(m_bulletPath, i + 50, i + 50, 10, 10));
    }
}





