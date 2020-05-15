#include "../Headers/SDLEnemyShip.h"

/**
 * Constructor
 * @param window
 * @param xPos
 * @param yPos
 * @param width
 * @param height
 */
SDL::SDLEnemyShip::SDLEnemyShip(Abstract::Window *window, double xPos, double yPos, double width, double height):Abstract::EnemyShip
                                                                                                        (xPos, yPos, width, height)
{
 m_window = window;
}
/**
 * Destructor
 */
SDL::SDLEnemyShip::~SDLEnemyShip() {}

/**
 * Method to render enemy ship
 */
void SDL::SDLEnemyShip::render() {
    m_window->drawRect(getSpriteType(),m_xPos,m_yPos,m_width,m_height);
}
