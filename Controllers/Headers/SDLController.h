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
        ~SDLController();
        void pollEvents();
        bool isRunning() override;
        bool isPressed(KEY key);
    private:
        void handleKeyboardEvent(SDL_Keycode code, bool keyDown);
        SDL_Event m_event;
        std::map<KEY,bool> m_keyPressed;
        bool m_isRunning = true;
    };
}



#endif //SPACEINVADERS_SDLCONTROLLER_H
