#include <SDL2/SDL_image.h>
#include <iostream>
#include <SDL2/SDL_render.h>
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
 * @return boolean value that says if texture was loaded or not
 */
bool SDL::TextureManager::loadTexture(const char *filename) {
    SDL_Surface* spriteSurface = IMG_Load(filename);
    SDL_Texture* texture;
    if(spriteSurface == nullptr)
    {
        std::cerr << "Unable to create surface: " << IMG_GetError() << "\n";
        return false;
    }
    else
    {
        texture = SDL_CreateTextureFromSurface(m_renderer,spriteSurface);
        if(texture == nullptr)
        {
            std::cerr << "Unable to create texture: " << SDL_GetError() << "\n";
            return false;
        }
        else
        {
            m_texture = texture;
        }
        SDL_FreeSurface(spriteSurface);
    }

    return true;
}

/**
 *
 * @param xPos
 * @param yPos
 * @param width
 * @param height
 * @param sourceRect
 */
void SDL::TextureManager::renderTexture(double xPos, double yPos, double width, double height, SDL_Rect *sourceRect) {
    SDL_Rect destRect = {static_cast<int>(xPos),static_cast<int>(yPos),static_cast<int>(width),static_cast<int>(height)};
    SDL_RenderCopy(m_renderer,m_texture,sourceRect,&destRect);
}


