//
// Created by cliff on 05/04/2020.
//

#include <iostream>
#include "../Headers/SDLScore.h"

/**
 * Constructor
 * @param renderer - renderer
 */
SDLNs::SDLScore::SDLScore(SDL_Renderer* renderer) {
    m_renderer= renderer;
    m_textTexture = new GameNs::TextManager(m_renderer, 25);
}

SDLNs::SDLScore::~SDLScore() {
    delete m_textTexture;
}

/**
 * Method to render score
 */
void SDLNs::SDLScore::render() {
    //create texture
    std::string score = std::to_string(getScores());
    m_textTexture->loadTexture("Score:   " + score);
    SDL_Rect rect = {0, 0, 70, 70};
    SDL_RenderCopy(m_renderer, m_textTexture->getTexture(), nullptr, &rect);
}

