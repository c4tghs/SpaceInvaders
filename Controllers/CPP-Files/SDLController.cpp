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
 * @param keyDown - boolean indicating if key is pressed down or not
 */
void SDL::SDLController::handleKeyboardEvent(SDL_Keycode code, bool keyDown) {
    KEY key;
    switch (code)
    {
        case SDLK_LEFT:
            key = moveLeft;
            break;
        case SDLK_RIGHT:
            key = moveRight;
            break;
        case SDLK_SPACE:
            key = playerShoot;
            break;
        default:
            key = none;
            break;
    }
    if(key != none)m_keyPressed[key] = keyDown;

}
/**
 * Method used to check if a key a pressed
 * @param key - the key to check
 * @return Boolean indicating if the key is pressed
 */
bool SDL::SDLController::isPressed(KEY key) {
    return m_keyPressed[key];
}


