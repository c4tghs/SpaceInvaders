//
// Created by cliff on 30/03/2020.
//

#include "../Headers/SDLTimer.h"
/**
 * Constructor for SDLTimer
 */
SDLNs::SDLTimer::SDLTimer()
{
    SDLTimer::reset();
}

/**
 * Destructor for SDLTimer
 */
SDLNs::SDLTimer::~SDLTimer(){}

/**
 * Method to reset all parameters
 */
void SDLNs::SDLTimer::reset() {
    m_startTicks = SDL_GetTicks();
    m_deltaTime = 0.0f;
    m_elapsedTicks = 0;
}
/**
 * Method that returns private member variable
 * @return m_deltaTime
 */
double SDLNs::SDLTimer::getDeltaTime() {
    return m_deltaTime;
}
/**
 * Method to update parameters
 */
void SDLNs::SDLTimer::update() {
    //ElapsedTicks is the time between reset and current time;
    m_elapsedTicks = SDL_GetTicks() - m_startTicks;
    //Divide by 1000 to get time in seconds
    m_deltaTime  = m_elapsedTicks/1000.0;
    if(m_deltaTime > TARGET_DELTATIME)
    {
        m_deltaTime = TARGET_DELTATIME;
    }
}

/**
 * Method that returns current time in seconds
 * @return
 */
float SDLNs::SDLTimer::getTime() {
    return SDL_GetTicks()/1000.0f;
}


