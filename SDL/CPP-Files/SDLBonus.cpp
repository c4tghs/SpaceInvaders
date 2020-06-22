#include "../Headers/SDLBonus.h"

/**
 * Constructor
 * @param xPos - initial x position
 * @param yPos - initial y position
 * @param width - width of bonus
 * @param height - height of bonus
 * @param type - bonus type
 * @param window - window to render bonus on
 */
SDL::SDLBonus::SDLBonus(double xPos, double yPos, double width, double height, BONUS_TYPE type, Abstract::Window *window): Abstract::Bonus(xPos, yPos, width, height) {
    m_bonusType = type;
    m_window = window;
}

/**
 * Destructor
 */
SDL::SDLBonus::~SDLBonus() {}

/**
 * Method used to render bonus
 */
void SDL::SDLBonus::render() {
    m_window->drawRect(getSpriteType(),m_xPos, m_yPos, m_width, m_height);
}
/**
 * Method that returns the bonus' sprite type
 * @return sprite type
 */
SPRITE SDL::SDLBonus::getSpriteType() {
    if(m_bonusType == POINTS)
    {
        return BONUS_POINTS;
    } else
    {
        return BONUS_LIFE;
    }
}
