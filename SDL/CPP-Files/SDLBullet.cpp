
#include "../Headers/SDLBullet.h"

/**
 * Constructor
 * @param xPos - initial x position of bullet
 * @param yPos - initial y position of bullet
 * @param width - width of bullet
 * @param height - height of bullet
 * @param window - Window
 */
SDL::SDLBullet::SDLBullet(double xPos, double yPos, double width, double height, Abstract::Window *window, Bullet_type type) : Abstract::Bullet(xPos, yPos, width, height) {
    m_window = window;
    m_bulletType = type;
}

/**
 * Destructor
 */
SDL::SDLBullet::~SDLBullet() {}

/**
 * Method to render bullet
 */
void SDL::SDLBullet::render() {
    m_window->drawRect(getSpriteType(), m_xPos, m_yPos, m_width, m_height);
}

/**
 * Method that returns the bullet's sprite type
 * @return sprite type
 */
Sprite SDL::SDLBullet::getSpriteType() {
    if(m_bulletType == player)
    {
        return PLAYER_BULLET;
    }
    else
    {
        return ENEMY_BULLET;
    }

}
