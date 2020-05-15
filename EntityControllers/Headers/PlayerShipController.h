#ifndef SPACEINVADERS_PLAYERSHIPCONTROLLER_H
#define SPACEINVADERS_PLAYERSHIPCONTROLLER_H


#include "../../Factories/Factory.h"

class PlayerShipController {
    public:
        PlayerShipController(Abstract::Controller* controller,Abstract::Factory* factory,Abstract::Timer* timer);
        ~PlayerShipController();
        void update();
        void playerActions();
        void shoot();

    private:
        Abstract::Factory* m_factory;
        Abstract::Controller* m_controller;
        Abstract::Timer* m_timer;
        Abstract::PlayerShip* m_playership;
        Abstract::Window* m_window;
};


#endif //SPACEINVADERS_PLAYERSHIPCONTROLLER_H
