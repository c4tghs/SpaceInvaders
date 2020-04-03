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
GameNs::EnemyShip::EnemyShip(int xPos, int yPos, int width, int height):Ship(xPos,yPos,width,height) {}