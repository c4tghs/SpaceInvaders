#include "../Headers/SDLEnemyShip.h"

/**
 * Constructor
 * @param window - window
 * @param xPos - initial x position of enemy
 * @param yPos - initial y position of enemy
 * @param width - width of enemy
 * @param height - height of enemy
 */
SDL::SDLEnemyShip::SDLEnemyShip(Abstract::Window *window, double xPos, double yPos, double width, double height,
                                ENEMY_TYPE type) : Abstract::EnemyShip(xPos, yPos, width, height)

{
    m_window = window;
    m_enemyType = type;
}
/**
 * Destructor
 */
SDL::SDLEnemyShip::~SDLEnemyShip() {}

/**
 * Method to render enemy ship
 */
void SDL::SDLEnemyShip::render() {
    m_window->drawRect(getSpriteType(), m_xPos, m_yPos, m_width, m_height);
}

/**
 * Method that returns the ship"s sprite type
 * @return SPRITE representing the ship's type
 */
SPRITE SDL::SDLEnemyShip::getSpriteType() {
    if(m_enemyType == Squid)
    {
        return ENEMY_SMALL_OPEN;
    }
    else if(m_enemyType == Crab)
    {
        return ENEMY_MEDIUM_OPEN;
    }
    else
    {
        return ENEMY_BIG_OPEN;
    }
}