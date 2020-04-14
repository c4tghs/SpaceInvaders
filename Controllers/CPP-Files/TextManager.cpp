//
// Created by cliff on 05/04/2020.
//

#include <iostream>
#include "../Headers/TextManager.h"

/**
 * Constructor
 */
GameNs::TextManager::TextManager() {}

/**
 * Constructor
 * @param renderer - the renderer
 */
GameNs::TextManager::TextManager(SDL_Renderer *renderer) {
    m_renderer = renderer;
}

/**
 * Method to return the created texture
 * @return - texture
 */
SDL_Texture* GameNs::TextManager::getTexture() {
    return m_texture;
}

/**
 * Method to create text texture from font
 * @param filename - the text to display
 * @param ren
 */
void GameNs::TextManager::loadTexture(const std::string &text, int textSize) {
    SDL_Texture *texture;
    SDL_Surface *surface;
    SDL_Color color = {255,255,255};
    m_font = TTF_OpenFont(m_fontFile,textSize);
    TTF_SetFontStyle(m_font,1);
    if(m_font==nullptr)
    {
        std::cout << "Failed to load font. Error: " << SDL_GetError() << std::endl;
        exit(1);
    } else{
        //create surface
        surface = TTF_RenderText_Blended(m_font,text.c_str(),color);
        if(surface==nullptr)
        {
            std::cout << "Failed to create surface. Error: " << SDL_GetError() << std::endl;
            exit(1);
        } else{
            //create texture
            texture = SDL_CreateTextureFromSurface(m_renderer,surface);
            if(texture ==nullptr)
            {
                std::cout << "Failed to create texture. Error: " << SDL_GetError() << std::endl;
                exit(1);
            } else
            {
                m_texture = texture;
            }
        }
        //free surface
        SDL_FreeSurface(surface);
    }
}

void GameNs::TextManager::free() {
    if(m_texture != nullptr)
    {
        SDL_DestroyTexture(m_texture);
        m_texture = nullptr;
    }
}



