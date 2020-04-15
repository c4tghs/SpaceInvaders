//
// Created by cliff on 14/04/2020.
//

#include "../Headers/Bonus.h"

/**
 * Constructor
 * @param xPos - x position of bonus
 * @param yPos - y position of bonus
 * @param width - width of bonus
 * @param height - height of bonus
 */
GameNs::Bonus::Bonus(int xPos, int yPos, int width, int height, BonusType bonusType) : Entity(xPos, yPos, width, height) {
    setBonusType(bonusType);
}
/**
 * Constructor
 */
GameNs::Bonus::Bonus() {}

/**
 * Method that returns the bonus type
 * @return - bonus type
 */
GameNs::BonusType GameNs::Bonus::getBonusType() {
    return m_bonusType;
}
/**
 * Method that set the bonus type
 * @param bonusType - bonus type
 */
void GameNs::Bonus::setBonusType(GameNs::BonusType bonusType) {
    m_bonusType = bonusType;
}


