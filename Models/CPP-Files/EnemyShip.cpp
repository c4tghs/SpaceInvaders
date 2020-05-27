
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
 * Method that returns the direction enemy is moving
 * @return integer representing move direction
 */
int Abstract::EnemyShip::getMoveDirection() const {
    return m_moveDirection;
}

void Abstract::EnemyShip::setMoveDirection(int direction) {
    m_moveDirection = direction;
}

ENEMY_TYPE Abstract::EnemyShip::getEnemyType() {
    return m_enemyType;
}

