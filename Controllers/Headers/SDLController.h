//
// Created by cliff on 08/05/2020.
//

#ifndef SPACEINVADERS_SDLCONTROLLER_H
#define SPACEINVADERS_SDLCONTROLLER_H

#include <SDL2/SDL_events.h>
#include "Controller.h"

namespace SDL
{
    class SDLController: public Abstract::Controller {
    public:
        SDLController();
        ~SDLController() =default;
        PLAYER_ACTION getEvent() override ;
        bool isRunning() override ;

    private:
        SDL_Event m_event;

    };
}



#endif //SPACEINVADERS_SDLCONTROLLER_H
