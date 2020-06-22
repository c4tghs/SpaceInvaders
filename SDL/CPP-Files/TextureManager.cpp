#include <SDL2/SDL_image.h>
#include <iostream>
#include "../Headers/TextureManager.h"

/**
 * Constructor
 */
SDL::TextureManager::TextureManager(SDL_Renderer* renderer) {
    m_renderer = renderer;
}

/**
 * Destructor
 */
SDL::TextureManager::~TextureManager() {
    SDL_DestroyTexture(m_texture);
}

/**
 * Method used to load a texture
 * @param filename - path to file
 * @return boolean indicating if texture was loaded or not
 */
bool SDL::TextureManager::loadTexture(const char *filename, bool transparent) {
    //Create surface from loaded image
    SDL_Surface* spriteSurface = IMG_Load(filename);

    if(spriteSurface == nullptr)
    {
        std::cerr << "Unable to create surface: " << IMG_GetError() << "\n";
        return false;
    }
    else
    {
        if(transparent)
        {
            //Transparent background
            Uint32 colorkey = SDL_MapRGB(spriteSurface->format, 255, 255, 255);
            SDL_SetColorKey(spriteSurface, SDL_TRUE, colorkey);
        }

        //Create texture
        m_texture = SDL_CreateTextureFromSurface(m_renderer,spriteSurface);
        if(m_texture == nullptr)
        {
            std::cerr << "Unable to create texture: " << SDL_GetError() << "\n";
            SDL_FreeSurface(spriteSurface);
            return false;
        }
        SDL_FreeSurface(spriteSurface);
    }

    return true;
}

/**
 * Method used to render a texture
 * @param xPos - x position of texture
 * @param yPos - y position of texture
 * @param width - width of texture
 * @param height - height of texture
 * @param sourceRect - source of rect
 */
void SDL::TextureManager::renderTexture(double xPos, double yPos, double width, double height, SDL_Rect *sourceRect) {
    // Destination rectangle
    SDL_Rect destRect = {static_cast<int>(xPos),static_cast<int>(yPos),static_cast<int>(width),static_cast<int>(height)};

    SDL_RenderCopy(m_renderer,m_texture,sourceRect,&destRect);
}


