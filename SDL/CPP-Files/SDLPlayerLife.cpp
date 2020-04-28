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
    m_textTexture = new GameNs::TextManager(m_renderer, 25);
}

/**
 * Destructor
 */
SDLNs::SDLPlayerLife::~SDLPlayerLife()
{
    delete m_textTexture;
}

/**
 * Method to render texture
 */
void SDLNs::SDLPlayerLife::render() {
    std::string life = std::to_string(getPlayerLife());
    m_textTexture->loadTexture("Lives:   " + life);
    //Create rectangular area
    SDL_Rect rect = {m_screenWidth-100, 0, 60, 60};
    SDL_RenderCopy(m_renderer, m_textTexture->getTexture(), nullptr, &rect);
}



