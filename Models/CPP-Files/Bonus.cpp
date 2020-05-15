#include "../Headers/Bonus.h"

/**
 * Constructor
 * @param xPos - x position of bonus
 * @param yPos - y position of bonus
 * @param width - width of bonus
 * @param height - height of bonus
 */
Abstract::Bonus::Bonus(int xPos, int yPos, int width, int height, BonusType bonusType) : Entity(xPos, yPos, width, height) {
    setBonusType(bonusType);
}
/**
 * Destructor
 */
Abstract::Bonus::~Bonus() {}

/**
 * Method that returns the bonus type
 * @return - bonus type
 */
Abstract::BonusType Abstract::Bonus::getBonusType() {
    return m_bonusType;
}
/**
 * Method that set the bonus type
 * @param bonusType - bonus type
 */
void Abstract::Bonus::setBonusType(Abstract::BonusType bonusType) {
    m_bonusType = bonusType;
}


