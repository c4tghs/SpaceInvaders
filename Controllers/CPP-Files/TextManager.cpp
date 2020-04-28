//
// Created by cliff on 05/04/2020.
//

#include <iostream>
#include "../Headers/TextManager.h"


GameNs::TextManager::TextManager() {}

/**
 * Constructor
 * @param renderer - the renderer
 */
GameNs::TextManager::TextManager(SDL_Renderer *renderer, int textSize) {
    m_renderer = renderer;
    m_font = TTF_OpenFont(m_fontFile,textSize);
}

/**
 * Destructor
 */
GameNs::TextManager::~TextManager()
{
    SDL_DestroyTexture(m_texture);
    TTF_CloseFont(m_font);
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
 * @param text - the text to display
 * @param textSize - the size of the text
 */
void GameNs::TextManager::loadTexture(const std::string &text) {
    SDL_Texture *texture;
    SDL_Surface *surface;
    SDL_Color color = {255,255,255};
    //Create Font


    //Check if font was created successfully.
    if(m_font==nullptr)
    {
        std::cerr << "Failed to load font. Error: " << SDL_GetError() << std::endl;
        exit(1);
    }
    else
    {
        //Create surface.
        surface = TTF_RenderText_Blended(m_font,text.c_str(),color);
        //Check if surface was created successfully.
        if(surface==nullptr)
        {
            std::cerr << "Failed to create text surface. Error: " << SDL_GetError() << std::endl;
            exit(1);
        }
        else
        {
            //Create texture.
            texture = SDL_CreateTextureFromSurface(m_renderer,surface);
            //Check if texture was created successfully.
            if(texture ==nullptr)
            {
                std::cerr << "Failed to create texture. Error: " << SDL_GetError() << std::endl;
                exit(1);
            }
            else
            {
                m_texture = texture;
            }
        }
        //Free surface.
        SDL_FreeSurface(surface);
    }
}





