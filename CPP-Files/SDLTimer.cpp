//
// Created by cliff on 30/03/2020.
//

#include "../Headers/SDLTimer.h"

SDLNs::SDLTimer::SDLTimer()
{
    reset();
}
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
float SDLNs::SDLTimer::getDeltaTime() {
    return m_deltaTime;
}
/**
 * Method to update parameters
 */
void SDLNs::SDLTimer::update() {
    //elapsedTicks is the time between reset and current time;
    m_elapsedTicks = SDL_GetTicks() - m_startTicks;
    //divide by 1000 to get time in seconds
    m_deltaTime  = m_elapsedTicks/1000.0;
    if(m_deltaTime > TARGET_DELTATIME)
    {
        m_deltaTime = TARGET_DELTATIME;
    }
}

