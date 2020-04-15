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
GameNs::PlayerShip::PlayerShip(int xPos, int yPos, int width, int height):Entity(xPos,yPos,width,height) {}
/**
 * Method that returns the players speed
 * @return player's speed
 */
float GameNs::PlayerShip::getPlayerSpeed() {
    return m_playerSpeed;
}

/**
 * Method that sets player speed
 * @param speed
 */
void GameNs::PlayerShip::setPlayerSpeed(float speed) {
    m_playerSpeed = speed;
}

