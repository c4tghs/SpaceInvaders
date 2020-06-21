#include <iostream>
#include "../Headers/TextManager.h"
#include "../../Constants.h"

/**
 * Constructor
 * @param renderer - the renderer to render on
 */
SDL::TextManager::TextManager(SDL_Renderer *renderer) {
    m_renderer = renderer;
}

/**
 * Destructor
 */
SDL::TextManager::~TextManager() {
    SDL_DestroyTexture(m_texture);
}

/**
 * Method used to load texture
 * @param font - the font to use
 * @param text - the text
 * @param color - color of text
 * @return boolean indicating if texture was loaded successfully
 */
bool SDL::TextManager::loadTextTexture(TTF_Font *font, const std::string &text, SDL_Color color) {
    //Destroy texture -> prevent memory problems
    if(m_texture!= nullptr)
    {
        SDL_DestroyTexture(m_texture);
    }

    //Create Surface
    SDL_Surface *surface = TTF_RenderUTF8_Solid(font,text.c_str(),color);

    if(surface==nullptr)
    {
        std::cerr << "Failed to create text surface. Error: " << TTF_GetError() <<"\n";
        return false;

    }
    else
    {
        //Create texture
        m_texture = SDL_CreateTextureFromSurface(m_renderer,surface);
        if(m_texture == nullptr)
        {
            std::cerr << "Failed to create create texture. Error: " << SDL_GetError() <<"\n";
            SDL_FreeSurface(surface);
            return false;
        }
        m_width = surface->w;
        m_height = surface->h;
        SDL_FreeSurface(surface);
    }
    return true;
}

/**
 * Method used to render a text to the screen
 * @param xPos - x position of text
 * @param yPos - y position of text
 * @param width - width of text
 * @param height - height of text
 */
void SDL::TextManager::renderText(int xPos, int yPos) {
    //rectangle
    SDL_Rect rect = {xPos,yPos,static_cast<int>(m_width*Constants::SCALE_X),static_cast<int>(m_height*Constants::SCALE_Y)};

    //Render
    SDL_RenderCopy(m_renderer,m_texture, nullptr,&rect);
}

/**
 * Method that returns the created surface's width
 * @return integer representing the surface's width
 */
int SDL::TextManager::getSurfaceWidth() const {
    return m_width;
}

