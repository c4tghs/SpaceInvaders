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
 * Method to show background
 */
void SDLNs::SDLBackground::render() {
    //clear renderer before adding things
    SDL_RenderClear(m_renderer);
    //set background color
    SDL_SetRenderDrawColor(m_renderer,0,0,0,255);

}
/**
 * Method to destroy background texture
 */
void SDLNs::SDLBackground::close() {
    //m_backgroundTexture->free();

}