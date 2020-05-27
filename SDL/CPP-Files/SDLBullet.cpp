
#include "../Headers/SDLBullet.h"

/**
 * Constructor
 * @param xPos - initial x position of bullet
 * @param yPos - initial y position of bullet
 * @param width - width of bullet
 * @param height - height of bullet
 * @param window - Window
 */
SDL::SDLBullet::SDLBullet(double xPos, double yPos, double width, double height, Abstract::Window *window,BULLET_TYPE type) : Abstract::Bullet(xPos, yPos, width, height) {
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

SPRITE SDL::SDLBullet::getSpriteType() {
    if(m_bulletType == PLAYER)
    {
        return PLAYER_BULLET;
    }
    else
    {
        return ENEMY_BULLET;
    }


}
