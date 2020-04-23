/**
 * CPP file for SDLBackground
 */

#include "../Headers/SDLBackground.h"
#define SPRITES_FRAMES 2
/**
 * Constructor for SDLBackground
 * @param renderer - the renderer
 *
 */
SDLNs::SDLBackground::SDLBackground(SDL_Renderer* renderer)
{
    m_renderer = renderer;
    m_textureManager = new GameNs::TextureManager(m_renderer);
    m_textureManager->loadTexture(sprite);

}
/**
 * Method to show background
 */
void SDLNs::SDLBackground::render() {
    //Clear renderer before adding things
    SDL_RenderClear(m_renderer);

    SDL_SetRenderDrawColor(m_renderer,0,0,0,255);

}
/**
 * Method to destroy background texture
 */
void SDLNs::SDLBackground::close()
{
    //m_backgroundTexture->free();

}