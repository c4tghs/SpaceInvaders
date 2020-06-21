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
        void pollEvents() override;
        bool isRunning() override;
        bool isPressed(Key key) override;

    private:
        void handleKeyboardEvent(SDL_Keycode code, bool keyDown);
    private:
        SDL_Event m_event;
        std::map<Key,bool> m_keyPressed;
        bool m_isRunning = true;
    };
}



#endif //SPACEINVADERS_SDLCONTROLLER_H
