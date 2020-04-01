//
// Created by cliff on 14/03/2020.
//

#include "../Headers/SDLBackground.h"
SDLNs::SDLBackground::SDLBackground(SDL_Renderer* renderer, int screenWidth, int screenHeight)
{
    m_renderer = renderer;
    m_screenHeight = screenHeight;
    m_screenWidth  = screenWidth;

    m_backgroundTexture = new GameNs::TextureManager(renderer);
}
void SDLNs::SDLBackground::render() {
    //clear renderer before adding things
    SDL_RenderClear(m_renderer);
    //set background color
    SDL_SetRenderDrawColor(m_renderer,0,0,0,255);

}
void SDLNs::SDLBackground::close() {
    m_backgroundTexture->free();
}