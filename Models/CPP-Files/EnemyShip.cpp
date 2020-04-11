//
// Created by cliff on 08/03/2020.
//

#include "../Headers/EnemyShip.h"
/**
 * Constructor
 */
GameNs::EnemyShip::EnemyShip() {}
/**
 * Constructor for EnemyShip
 * @param xPos - x position of ship
 * @param yPos - y position of ship
 * @param width - width of ship
 * @param height - height of ship
 */
GameNs::EnemyShip::EnemyShip(int xPos, int yPos, int width, int height):Entity(xPos,yPos,width,height) {}

void GameNs::EnemyShip::setEnemyType(GameNs::EnemyType type) {
    m_enemyType = type;
}

GameNs::EnemyType GameNs::EnemyShip::getEnemyType() {
    return m_enemyType;
}
