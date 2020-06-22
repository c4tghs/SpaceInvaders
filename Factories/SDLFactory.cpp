#include <iostream>
#include "SDLFactory.h"
#include "../Controllers/Headers/SDLController.h"
#include "../SDL/Headers/SDLTimer.h"
#include "../SDL/Headers/SDLPlayerShip.h"
#include "../SDL/Headers/SDLBullet.h"
#include "../SDL/Headers/SDLBonus.h"
#include "../SDL/Headers/SDLWindow.h"
#include "../SDL/Headers/SDLEnemyShip.h"

/**
 * Constructor
 */
SDL::SDLFactory::SDLFactory() {}
/**
 * Destructor
 */
SDL::SDLFactory::~SDLFactory() {
    std::cerr << "Factory destructor" << std::endl;
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
 * Method that creates new player ship
 * @param xPos - initial x position
 * @param yPos - initial y position
 * @param width - width of player ship
 * @param height - height of player ship
 * @return instance of SDL playership
 */
Abstract::PlayerShip* SDL::SDLFactory::createPlayerShip(double xPos, double yPos, double width, double height,Abstract::Window *window) {
    return new SDL::SDLPlayerShip(xPos,yPos,width,height,window);
}
/**
 * Method that creates window
 * @param title - title of window
 * @param width - width of window
 * @param height - height of window
 * @return SDL instance of window
 */
Abstract::Window* SDL::SDLFactory::createWindow(const char *title, int width, int height) {
    return new SDL::SDLWindow(title, width, height);
}

/**
 * Method that creates an enemy ship
 * @param xPos - initial x pos
 * @param yPos - initial y pos
 * @param width - width
 * @param height - height
 * @param window - window
 * @param type - enemy type
 * @return SDL instance of enemy ship
 */
Abstract::EnemyShip* SDL::SDLFactory::createEnemyShip(double xPos, double yPos, double width, double height, Abstract::Window *window, ENEMY_TYPE type) {
    return new SDL::SDLEnemyShip(window, xPos, yPos, width, height, type);
}

/**
 * Method that creates a bullet
 * @param xPos - initial x position
 * @param yPos - initial y position
 * @param width - width of bullet
 * @param height - height of bullet
 * @param window - window
 * @param type - bullet bullet
 * @return SDL instance of bullet
 */
Abstract::Bullet* SDL::SDLFactory::createBullet(double xPos, double yPos, double width, double height, Abstract::Window *window, BULLET_TYPE type) {
    return new SDL::SDLBullet(xPos,yPos,width,height,window,type);
}

/**
 * Method used to create a bonus
 * @param xPos - initial x position
 * @param yPos - initial y position
 * @param width - width of bonus
 * @param height - height of bonus
 * @param type - bonus type
 * @return SDL instance of bonus
 */
Abstract::Bonus *SDL::SDLFactory::createBonus(double xPos, double yPos, double width, double height, Abstract::Window *window, BONUS_TYPE type) {
    return new SDLBonus(xPos,yPos,width,height,type,window);
}











