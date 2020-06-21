#include "../Headers/Bonus.h"

/**
 * Constructor
 * @param xPos - x position of bonus
 * @param yPos - y position of bonus
 * @param width - width of bonus
 * @param height - height of bonus
 */
Abstract::Bonus::Bonus(double xPos, double yPos, double width, double height) : Entity(xPos, yPos, width, height) {}
/**
 * Destructor
 */
Abstract::Bonus::~Bonus() {}

/**
 * Method that returns the bonus type
 * @return - bonus type
 */
Bonus_type Abstract::Bonus::getBonusType() {
    return m_bonusType;
}


