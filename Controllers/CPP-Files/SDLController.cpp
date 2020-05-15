#include "../Headers/SDLController.h"

/**
 * Constructor
 */
SDL::SDLController::SDLController() {}


bool SDL::SDLController::isRunning() {
    while(SDL_PollEvent(&m_event) !=0)
    {
        if(m_event.type == SDL_QUIT)
        {
            return true;
        }
    }
    return false;
}

/**
 * Method that returns current events
 * @return vector containing current events
 */
PLAYER_ACTION SDL::SDLController::getEvent() {
    PLAYER_ACTION event = NONE;
    //SDL_Event keyEvent;
    SDL_PollEvent(&m_event);
    const Uint8* keystate = SDL_GetKeyboardState(nullptr);
    if(keystate[SDL_SCANCODE_LEFT])
    {
        event = MOVE_LEFT;
    }
    else if(keystate[SDL_SCANCODE_RIGHT]){
        event = MOVE_RIGHT;
    }
    else if(keystate[SDL_SCANCODE_SPACE])
    {
        event = PLAYER_SHOOT;
    } else
    {
        event = NONE;
    }

    return event;
}


