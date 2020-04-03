/**
 * CPP file for EnemyManager class
 */

#include "../Headers/EnemyManager.h"
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
GameNs::EnemyManager::EnemyManager(AbstractFactory *AF,std::string enemyShipPath, int screenWidth)
{
    m_factory = AF;
    m_enemyShipPath = enemyShipPath;
    m_timer = AF->createTimer();
    m_screenWidth = screenWidth;
}
/**
 * Method used to create enemy instances
 * @param number - number of enemy instances to create
 */
void GameNs::EnemyManager::createEnemies(int number) {
    m_enemyShips.reserve(number);
    int xPos;
    int yPos;
    for(int y =0; y < number/10;y++)
    {
        for(int i=0; i < number; i++)
        {
            xPos = ((i % 10) *55) + 10;
            //xPos = i * 100;
            yPos = ((i /11) *55)+1;
            m_enemyShips.emplace_back(m_factory->createEnemyShip(m_enemyShipPath,xPos,yPos));
        }
    }
}
/**
 * Method that returns private member enemyships
 * @return vector containing enemy instances
 */
std::vector<GameNs::Ship *> GameNs::EnemyManager::getEnemies()
{
    return m_enemyShips;
}
/**
 * Method to update enemies, ie direction, rendering
 */
void GameNs::EnemyManager::updateEnemies() {
    moveEnemies();
    //update time
    m_timer->update();
    for(int i =0; i < m_enemyShips.size(); i ++)
    {
        m_enemyShips[i]->render();
        // TODO check if enemy has reached player
    }
    if(checkEnemyBoundaries())
    {
        int moveDirection = m_enemyShips[0]->getMoveDirection();
        if(moveDirection==1)
        {
            moveDirection = -1;
        } else{
            moveDirection = 1;
        }
        for(int y =0; y < m_enemyShips.size(); y ++)
        {
            m_enemyShips[y]->setMoveDirection(moveDirection);
            m_enemyShips[y]->setXPosition(m_enemyShips[y]->getXPosition());
            m_enemyShips[y]->setYPosition(m_enemyShips[y]->getYPosition()+10);
        }
    }
}
/**
 * Method to move enemies across screen
 */
void GameNs::EnemyManager::moveEnemies(){
    for(int i =0; i < m_enemyShips.size(); i ++){
        m_enemyShips[i]->setXPosition(m_enemyShips[i]->getXPosition()+ m_timer->getDeltaTime()*m_enemyShips[i]->getMoveDirection());
    }
}
/**
 * Method to check if an enemy has hit a boundary
 * @return True of False
 */
bool GameNs::EnemyManager::checkEnemyBoundaries() {
    for(int i =0; i < m_enemyShips.size(); i ++) {
        if(m_enemyShips[i]->getXPosition() < 0)
        {
            return true;
        }
        else if(m_enemyShips[i]->getXPosition() > m_screenWidth-m_enemyShips[i]->getWidth()){
            return true;
        }
    }
    return false;
}
