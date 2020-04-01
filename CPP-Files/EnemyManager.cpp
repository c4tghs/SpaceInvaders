//
// Created by cliff on 31/03/2020.
//

#include "../Headers/EnemyManager.h"
EnemyManager::EnemyManager() {}
EnemyManager::EnemyManager(AbstractFactory *AF,std::string enemyShipPath)
{
    m_factory = AF;
    m_enemyShipPath = enemyShipPath;
}
void EnemyManager::createEnemies(int number) {
    printf("The number of enemies are %d",number);
    m_enemyShips.reserve(number);
    int xPos;
    int yPos = 100;
    for(int i=0; i < number; i++)
    {
        //xPos = ((i % 200) *number) + 100;
        xPos = i * 100;
        if(i > 10)
        {
            yPos += 100;
        }
        //yPos = ((i /200) *number)+100;
        m_enemyShips.emplace_back(m_factory->createEnemyShip(m_enemyShipPath,xPos,yPos));
    }
}
std::vector<Ship *> EnemyManager::getEnemies()
{
    return m_enemyShips;
}
/**
 * Update all enemies
 */
void EnemyManager::updateEnemies() {
    bool enemyHitWall = false;
    for(int i =0; i < m_enemyShips.size(); i ++)
    {
        m_enemyShips[i]->render();
        if(m_enemyShips[i]->hitBoundary())
        {
            enemyHitWall = true;
        }
        // TODO check if enemy has reached player
    }
    if(enemyHitWall)
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
