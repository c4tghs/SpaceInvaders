//
// Created by cliff on 04/04/2020.
//

#include "../Headers/CollisionDetector.h"


/**
 * Constructor
 */
GameNs::CollisionDetector::CollisionDetector() {}

/**
 * Method to check if there's a collision between a bullet and enemy ship or player ship
 * @param xPos - x position of other object
 * @param yPos - y position of other object
 * @param width - width of other object
 * @param height - height of other object
 * @param bullet - the bullet
 * @return - true or false
 */
bool GameNs::CollisionDetector::checkBulletCollision(Bullet* bullet, int xPos, int yPos, int width, int height) {
    return xPos + width >= bullet->getXPosition() &&
           xPos <= bullet->getXPosition() + bullet->getWidth() &&
           yPos + height >= bullet->getYPosition() &&
           yPos <= bullet->getYPosition() + bullet->getHeight();
}

/**
 * Method to check if there's a collision between playerShip and bonus
 * @param bonus - bonus
 * @param playerShip - player ship
 * @return - true or false
 */
bool GameNs::CollisionDetector::checkBonusCollision(Bonus* bonus, PlayerShip* playerShip) {
    return bonus->getXPosition()+bonus->getWidth() >= playerShip->getXPosition() &&
           bonus->getXPosition() <= playerShip->getXPosition() + playerShip->getWidth() &&
           bonus->getYPosition() + bonus->getHeight() >= playerShip->getYPosition() &&
           bonus->getYPosition() <= playerShip->getYPosition() + playerShip->getHeight();
}

/**
 * Method to check collision between player and enemy bullet
 * @param playerBullet - player's bullet
 * @param enemyBullet - enemy's bullet
 * @return - true of false
 */
bool GameNs::CollisionDetector::twoBulletsCollision(GameNs::Bullet* playerBullet, GameNs::Bullet* enemyBullet) {
    return playerBullet->getXPosition() + playerBullet->getWidth() >= enemyBullet->getXPosition() &&
           playerBullet->getXPosition() <= enemyBullet->getXPosition() + enemyBullet->getWidth() &&
           playerBullet->getYPosition() + playerBullet->getHeight() >= enemyBullet->getYPosition() &&
           playerBullet->getYPosition() <= enemyBullet->getYPosition() + enemyBullet->getHeight();
}





