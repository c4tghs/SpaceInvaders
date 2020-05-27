#include <iostream>
#include "../Headers/SDLController.h"

/**
 * Constructor
 */
SDL::SDLController::SDLController() {}

/**
 * Destructor
 */
SDL::SDLController::~SDLController() {}


/**
 * Method to check if user has not pressed X
 * @return boolean that says if user has quit or not
 */
bool SDL::SDLController::isRunning() {
    return m_isRunning;
}

/**
 * Method to poll events
 */
void SDL::SDLController::pollEvents()
{
    while(SDL_PollEvent(&m_event) !=0)
    {
        switch(m_event.type)
        {
            case SDL_QUIT:
                m_isRunning = false;
                break;
            case SDL_KEYUP:
                handleKeyboardEvent(m_event.key.keysym.sym, false);
                break;
            case SDL_KEYDOWN:
                handleKeyboardEvent(m_event.key.keysym.sym, true);
                break;
            default:
                break;
        }
    }
}

/**
 * Method used to handle a key pressed by the user
 * @param code - the SDL key code
 * @param keyDown - boolean that says if key is pressed down or not
 */
void SDL::SDLController::handleKeyboardEvent(SDL_Keycode code, bool keyDown) {
    KEY key = NONE;
    switch (code)
    {
        case SDLK_LEFT:
            key = MOVE_LEFT;
            break;
        case SDLK_RIGHT:
            key = MOVE_RIGHT;
            break;
        case SDLK_SPACE:
            key = PLAYER_SHOOT;
            break;
        default:
            key = NONE;
            break;
    }
    if(key != NONE)m_keyPressed[key] = keyDown;

}
/**
 *
 * @param key
 * @return
 */
bool SDL::SDLController::isPressed(KEY key) {
    return m_keyPressed[key];
}


