//
// Created by cliff on 08/03/2020.
//

#include "../Headers/PlayerShip.h"

/**
 * Constructor for PlayerShip
 */
GameNs::PlayerShip::PlayerShip(){}
/**
 * Constructor for PlayerShip
 * @param xPos - x position of ship
 * @param yPos - y position of ship
 * @param width - width of ship
 * @param height - height of ship
 */
GameNs::PlayerShip::PlayerShip(int xPos, int yPos, int width, int height):Ship(xPos,yPos,width,height) {}

/**
 * Method that returns direction player is moving
 * @return
 */
int GameNs::PlayerShip::getMoveDirection(){
    return 1;
}
/**
 * Method to set the direction player is moving
 * @param direction - direction, ie 1 for right, -1 for left
 */
void GameNs::PlayerShip::setMoveDirection(int direction){}


