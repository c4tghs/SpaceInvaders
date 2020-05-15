
#include <iostream>
#include "../Headers/PlayerShipController.h"

/**
 * Controller
 * @param controller - controller
 * @param factory - factory to create objects
 * @param timer - game timer
 */
PlayerShipController::PlayerShipController(Abstract::Controller *controller, Abstract::Factory *factory,
                                           Abstract::Timer *timer) {
    m_factory = factory;
    m_controller = controller;
    m_timer = timer;
    m_window = m_controller->getWindow();
    double x = m_window->getWindowWidth() / 2.0;
    double y = m_window->getWindowHeight() - ((m_window->getWindowHeight()/20.0)+10);
    m_playership = m_factory->createPlayerShip(x, y, m_window->getWindowWidth() / 20.0, m_window->getWindowHeight() / 20.0, m_window);
}
/**
 * Destructor
 */
PlayerShipController::~PlayerShipController() {
    delete m_playership;
}

void PlayerShipController::update() {
    playerActions();
    m_playership->render();
}
/**
 * Method to move player
 */
void PlayerShipController::playerActions() {

   PLAYER_ACTION event = m_controller->getEvent();
   if(event == MOVE_LEFT)
   {
        if(m_playership->getXPosition() < 0)
        {
            m_playership->moveEntity(m_playership->getXPosition(),m_playership->getYPosition());
        }
        else
        {
            //200 pixels to move per second
            m_playership->moveEntity(m_playership->getXPosition()-(m_timer->getDeltaTime()*200),m_playership->getYPosition());
        }


   }
   else if(event == MOVE_RIGHT)
   {
       if(m_playership->getXPosition() > m_window->getWindowWidth()-m_playership->getWidth())
       {
           m_playership->moveEntity(m_playership->getXPosition(),m_playership->getYPosition());
       }
       else
       {
           m_playership->moveEntity(m_playership->getXPosition()+(m_timer->getDeltaTime()*200),m_playership->getYPosition());
       }
   }
   else if(event == PLAYER_SHOOT)
   {
       shoot();
   }
}

/**
 * Method that executed when player wants to shoot
 */
void PlayerShipController::shoot() {
    m_window->playSound(SHOOT);
}
