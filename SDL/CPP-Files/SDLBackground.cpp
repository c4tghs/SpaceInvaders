/**
 * CPP file for SDLBackground
 */

#include "../Headers/SDLBackground.h"

/**
 * Constructor for SDLBackground
 * @param renderer - the renderer
 *
 */
SDLNs::SDLBackground::SDLBackground(SDL_Renderer* renderer)
{
    m_renderer = renderer;
}

/**
 * Destructor
 */
SDLNs::SDLBackground::~SDLBackground(){}

/**
 * Method to show background
 */
void SDLNs::SDLBackground::render() {
    //Clear renderer before adding things
    SDL_RenderClear(m_renderer);

    SDL_SetRenderDrawColor(m_renderer,0,0,0,255);

}


