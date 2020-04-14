//
// Created by cliff on 05/04/2020.
//

#include "../Headers/SDLScore.h"
#include "../../Controllers/Headers/TextManager.h"

SDLNs::SDLScore::SDLScore(SDL_Renderer *renderer) {
    m_renderer= renderer;
    GameNs::TextManager* textManager = new GameNs::TextManager(m_renderer);
    m_textTexture = textManager;
}
void SDLNs::SDLScore::render() {
    //create texture
    std::string score = std::to_string(getScores());
    m_textTexture->loadTexture("Score:   " + score, 25);
    SDL_Rect rect = {0, 0, 70, 70};
    SDL_RenderCopy(m_renderer, m_textTexture->getTexture(), nullptr, &rect);
}

void SDLNs::SDLScore::close() {
    m_textTexture->free();
}
