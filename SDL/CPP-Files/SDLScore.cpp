//
// Created by cliff on 05/04/2020.
//

#include "../Headers/SDLScore.h"
#include "../../Controllers/Headers/TextManager.h"

SDLNs::SDLScore::SDLScore(SDL_Renderer *renderer) {
    m_renderer= renderer;
    GameNs::TextManager* textManager = new GameNs::TextManager(m_renderer);
    m_texture = textManager;
}
void SDLNs::SDLScore::render() {
    //create texture
     std::string score = std::to_string(getScores());
    m_texture->loadTexture("Score:   "+score);
    SDL_Rect rect = {0, 0, 70, 70};
    SDL_RenderCopy(m_renderer,m_texture->getTexture(),NULL,&rect);
}

void SDLNs::SDLScore::close() {
    m_texture->free();
}
