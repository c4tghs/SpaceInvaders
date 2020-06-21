
#include "../Headers/PlayerShip.h"

/**
 * Constructor for PlayerShip
 * @param xPos - initial x position of ship
 * @param yPos - initial y position of ship
 * @param width - width of ship
 * @param height - height of ship
 */
Abstract::PlayerShip::PlayerShip(double xPos, double yPos, double width, double height): Entity(xPos, yPos, width, height) {

}

/**
 * Destructor
 */
Abstract::PlayerShip::~PlayerShip(){}

/**
 * Method used to set player score
 * @param score - integer representing player score
 */
void Abstract::PlayerShip::setScore(int score) {
    m_score = score;
}

/**
 * Method that returns the player's score
 * @return - integer representing player score
 */
int Abstract::PlayerShip::getScore() const {
    return m_score;
}

/**
 * Method used to set player score
 * @param lives - integer representing player lives
 */
void Abstract::PlayerShip::setLives(int lives) {
    m_lives = lives;
}

/**
 * Method that returns player's remaining lives
 * @return - integer representing player's remaining lives
 */
int Abstract::PlayerShip::getLives() {
    return m_lives;
}

