
/**
 * CPP file of class Ship
 */
#include "../Headers/Ship.h"

GameNs::Ship::Ship() {}
/**
 * Constructor for Ship
 * @param xPos - x position of ship
 * @param yPos - y position of ship
 * @param width - width of ship
 * @param height - height of ship
 */
GameNs::Ship::Ship(int xPos, int yPos, int width, int height):Entity(xPos,yPos,width,height) {
}

int GameNs::Ship::getMoveDirection() {
    return 0;
}

void GameNs::Ship::setMoveDirection(int direction) {}
