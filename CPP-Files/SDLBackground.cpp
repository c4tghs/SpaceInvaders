//
// Created by cliff on 14/03/2020.
//

#include "../Headers/SDLBackground.h"
SDLBackground::SDLBackground(SDL_Renderer* renderer, int screenWidth, int screenHeight)
{
    m_renderer = renderer;
    m_screenHeight = screenHeight;
    m_screenWidth  = screenWidth;

    m_backgroundTexture = new TextureManager(renderer);
}
void SDLBackground::render() {
    //clear renderer adding things
    SDL_RenderClear(m_renderer);
    //set background color
    SDL_SetRenderDrawColor(m_renderer,100,218,254,255);

    //show alien
    //SDL_RenderCopy(m_renderer,alien,NULL,&drect); // srcrect: part of image that you want to draw. dstrect: where you want to draw image
    //present render
}
void SDLBackground::close() {
    m_backgroundTexture->free();
}