/**
 * CPP file for EnemyManager class
 */

#include "../Headers/EnemyManager.h"

#include <utility>
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
    m_enemyShipPath = std::move(enemyShipPath);
    m_timer = AF->createTimer();
    m_screenWidth = screenWidth;
    //get current time and add random between 1 and 3 to it
    m_nextMissile = m_timer->getTime()+std::rand()% 3 + 1;
    //create 50 bullets
    m_bullets.reserve(50);
    createBullets();
}
/**
 * Method used to create enemy instances
 * @param number - number of enemy instances to create
 */
void GameNs::EnemyManager::createEnemies(int number) {
    m_enemyShips.reserve(number);
    for(int y =0; y < number;y++)
    {
        int xPos = ((y%10)*70)+100;
        int yPos=((y/10)*50)+70;

        m_enemyShips.emplace_back(m_factory->createEnemyShip(m_enemyShipPath,xPos,yPos));
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
    if(checkEnemyBoundaries())
    {
        int moveDirection = m_enemyShips[0]->getMoveDirection();
        if(moveDirection==1)
        {
            moveDirection = -1;
        } else{
            moveDirection = 1;
        }
        for(auto & m_enemyShip : m_enemyShips)
        {
            m_enemyShip->setMoveDirection(moveDirection);
            m_enemyShip->setXPosition(m_enemyShip->getXPosition());
            m_enemyShip->setYPosition(m_enemyShip->getYPosition()+10);
        }
    }
    for(auto & m_enemyShip : m_enemyShips)
    {
        m_enemyShip->render();
        // TODO check if enemy has reached player
        // TODO check collisions
    }
    //allow enemy to shoot
    enemyShoot();
 }
/**
 * Method to move enemies across screen
 */
void GameNs::EnemyManager::moveEnemies(){
    for(auto & m_enemyShip : m_enemyShips){
        m_enemyShip->setXPosition(m_enemyShip->getXPosition()+ m_timer->getDeltaTime()*m_enemyShip->getMoveDirection());
    }
}
/**
 * Method to check if an enemy has hit a boundary
 * @return True of False
 */
bool GameNs::EnemyManager::checkEnemyBoundaries() {
    for(auto & m_enemyShip : m_enemyShips) {
        if((m_enemyShip->getXPosition() < 0 ) or (m_enemyShip->getXPosition() > m_screenWidth-m_enemyShip->getWidth())){
            return true;
        }
    }
    return false;
}

/**
 * Method that allows an enemy to shoot
 */
void GameNs::EnemyManager::enemyShoot() {
    if(m_timer->getTime() < m_nextMissile)
    {
        return;
    }
    int randomId = std::rand() % m_enemyShips.size();
    printf("The generated random id is %d  and amount of ships are %d\n",randomId,m_enemyShips.size());
    for(int i =0; i < m_bullets.size();i++)
    {
        m_bullets[i]->setXPosition(m_enemyShips[randomId]->getXPosition()+20);
        m_bullets[i]->setYPosition(m_enemyShips[randomId]->getYPosition());
        if(BulletManager::getInstance()->getEnemyBulletFired())
        {
            continue;
        }
        BulletManager::getInstance()->setEnemyBulletFired(true);
        BulletManager::getInstance()->setEnemyBullet(m_bullets[i]);
        m_bullets.erase(m_bullets.begin()+i);
        break;
    }
    if(m_bullets.size()==1)
    {
        createBullets();
    }
    m_nextMissile = m_timer->getTime()+ std::rand()%3+1;
}

void GameNs::EnemyManager::createBullets() {
    for(int i =0; i<50;i++)
    {
        m_bullets.emplace_back(m_factory->createBullet(m_bulletPath,i+50,i+50));
    }
}

