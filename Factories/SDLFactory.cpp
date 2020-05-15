
//TODO use controller for states
#include <iostream>
#include "SDLFactory.h"
#include "../Controllers/Headers/SDLController.h"
#include "../SDL/Headers/SDLTimer.h"
#include "../SDL/Headers/SDLPlayerShip.h"

/**
 * Constructor
 */
SDL::SDLFactory::SDLFactory() {}
/**
 * Destructor
 */
SDL::SDLFactory::~SDLFactory() {
    std::cerr << "Game cleaned successfully" << std::endl;
}

/**
 * Method that creates a new controller
 * @return SDL instance of controller
 */
Abstract::Controller* SDL::SDLFactory::createController() {
    return new SDL::SDLController();
}

/**
 * Method that creates new timer
 * @return SDL instance of timer
 */
Abstract::Timer* SDL::SDLFactory::createTimer() {
    return new SDL::SDLTimer();
}
/**
 * Method that creates new playership
 * @param xPos - initial x position
 * @param yPos - initial y position
 * @param width - width of player ship
 * @param height - height of player ship
 * @return instance of SDL playership
 */
Abstract::PlayerShip *SDL::SDLFactory::createPlayerShip(double xPos, double yPos, double width, double height,
                                                        Abstract::Window *window) {
    return new SDL::SDLPlayerShip(xPos,yPos,width,height,window);
}
/**
 * Method that creates window
 * @param title - title of window
 * @param width - width of window
 * @param height - height of window
 * @return SDL instance of window
 */
Abstract::Window *SDL::SDLFactory::createWindow(const char *title, int width, int height) {
    return new SDL::SDLWindow(title, width, height);
}

/**
 * Method that creates an enemy ship
 * @param xPos - initial x pos
 * @param yPos - initial y pos
 * @param width - width
 * @param height - height
 * @param window - window
 * @return SDL instance of enemy ship
 */
Abstract::EnemyShip* SDL::SDLFactory::createEnemyShip(double xPos, double yPos, double width, double height, Abstract::Window *window) {
    return new SDL::SDLEnemyShip(window,xPos,yPos,width,height);
}











