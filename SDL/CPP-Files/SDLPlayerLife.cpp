//
// Created by cliff on 09/04/2020.
//

#include "../Headers/SDLPlayerLife.h"

/**
 * Constructor
 */
SDLNs::SDLPlayerLife::SDLPlayerLife() {}

/**
 * Constructor
 * @param renderer
 */
SDLNs::SDLPlayerLife::SDLPlayerLife(SDL_Renderer* renderer, int screenWidth) {
    m_renderer = renderer;
    m_screenWidth = screenWidth;
    m_textTexture = new GameNs::TextManager(m_renderer);
}

/**
 * Method to render texture
 */
void SDLNs::SDLPlayerLife::render() {
    std::string life = std::to_string(getPlayerLife());
    m_textTexture->loadTexture("Lives:   " + life, 20);
    //Create rectangular area
    SDL_Rect rect = {m_screenWidth-100, 0, 60, 60};
    SDL_RenderCopy(m_renderer, m_textTexture->getTexture(), nullptr, &rect);
}

/**
 * Method to free texture, ie destroy texture
 */
void SDLNs::SDLPlayerLife::close() {
    m_textTexture->free();
}


