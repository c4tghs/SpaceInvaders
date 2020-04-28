/**
 * Class to create texts
 */
#pragma once
#ifndef PROJECT_TEXTMANAGER_H
#define PROJECT_TEXTMANAGER_H

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_ttf.h>
#include <string>

namespace GameNs{
    class TextManager {
    public:
        TextManager();
        TextManager(SDL_Renderer *renderer, int textSize);
        ~TextManager();
        SDL_Texture* getTexture();
        void loadTexture(const std::string &text);

    private:
        SDL_Renderer* m_renderer= nullptr;
        SDL_Texture* m_texture = nullptr;
        TTF_Font* m_font= nullptr;
        const char* m_fontFile = "../assets/Fonts/alexandria.ttf";
    };
}



#endif //PROJECT_TEXTMANAGER_H
