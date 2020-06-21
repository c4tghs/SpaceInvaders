#include "../Headers/SDLTimer.h"

/**
 * Constructor for SDLTimer
 */
SDL::SDLTimer::SDLTimer()
{
   m_startTicks = SDL_GetTicks();
   m_deltaTime = 0.0f;
}

/**
 * Destructor for SDLTimer
 */
SDL::SDLTimer::~SDLTimer(){}

/**
 * Method that returns delta time
 * @return double representing the delta time
 */
double SDL::SDLTimer::getDeltaTime() {
    return m_deltaTime;
}
/**
 * Method to update parameters
 */
void SDL::SDLTimer::update() {
    //Divide by 1000 to get time in seconds
    m_deltaTime  = (SDL_GetTicks() - m_startTicks)/1000.0;
}

/**
 * Method that returns current time in seconds
 * @return
 */
float SDL::SDLTimer::getTime() {
    return SDL_GetTicks()/1000.0f;
}

/**
 * Method that resets timer
 */
void SDL::SDLTimer::reset()
{
    m_startTicks = SDL_GetTicks();
}




