
#include "../Headers/EnemyShip.h"

/**
 * Constructor for EnemyShip
 * @param xPos - initial x position of ship
 * @param yPos -  initial y position of ship
 * @param width - width of ship
 * @param height - height of ship
 */
Abstract::EnemyShip::EnemyShip(double xPos, double yPos, double width, double height): Entity(xPos, yPos, width, height) {
    m_moveDirection = 1;
}

/**
 * Method that sets an enemy's type
 * @param type - enemy type
 */
void Abstract::EnemyShip::setEnemyType(ENEMY_TYPE type) {
    m_enemyType = type;
}

/**
 * Method that returns an enemy's type
 * @return - ENEMYTYPE
 */
ENEMY_TYPE Abstract::EnemyShip::getEnemyType() {
    return m_enemyType;
}

SPRITE Abstract::EnemyShip::getSpriteType() {
   if(m_enemyType == SQUID)
   {
       return ENEMY_SMALL;
   }
   else if(m_enemyType == CRAB)
   {
       return ENEMY_MEDIUM;
   }
   else
   {
       return ENEMY_BIG;
   }

}
/**
 * Method that returns the direction enemy is moving
 * @return integer representing move direction
 */
int Abstract::EnemyShip::getMoveDirection() const {
    return m_moveDirection;
}

void Abstract::EnemyShip::setMoveDirection(int direction) {
    m_moveDirection = direction;
}

