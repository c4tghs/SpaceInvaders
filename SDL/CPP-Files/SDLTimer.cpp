
#include "../Headers/SDLTimer.h"
/**
 * Constructor for SDLTimer
 */
SDL::SDLTimer::SDLTimer()
{
   m_startTicks = SDL_GetTicks();
   m_deltaTime = 0.0f;
   m_elapsedTicks = 0;
}

/**
 * Destructor for SDLTimer
 */
SDL::SDLTimer::~SDLTimer(){}

/**
 * Method that returns private member variable
 * @return m_deltaTime
 */
double SDL::SDLTimer::getDeltaTime() {
    return m_deltaTime;
}
/**
 * Method to update parameters
 */
void SDL::SDLTimer::update() {
    //ElapsedTicks is the time between reset and current time;
    m_elapsedTicks = SDL_GetTicks() - m_startTicks;
    //Divide by 1000 to get time in seconds
    m_deltaTime  = m_elapsedTicks/1000.0;
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




