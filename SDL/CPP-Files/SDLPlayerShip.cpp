#include <iostream>
#include "../Headers/SDLPlayerShip.h"
#include "../../Enums.h"
#include "../Headers/SDLWindow.h"

/**
 * Constructor
 * @param xPos
 * @param yPos
 * @param width
 * @param height
 * @param window
 */
SDL::SDLPlayerShip::SDLPlayerShip(double xPos, double yPos, double width, double height, Abstract::Window *window)
        : Abstract::PlayerShip(xPos, yPos, width,height){
    m_window = window;
}

/**
 * Destructor
 */
SDL::SDLPlayerShip::~SDLPlayerShip() {}

/**
 * Method to render player ship
 */
void SDL::SDLPlayerShip::render() {
    m_window->drawRect(PLAYERSHIP,m_xPos,m_yPos,m_width,m_height);
}


