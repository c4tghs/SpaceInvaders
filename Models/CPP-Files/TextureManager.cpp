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
 * @param filename - path to file
 * @param renderer - the renderer
 * @return boolean value that says if texture was loaded or not
 */
bool SDL::TextureManager::loadTexture(const char *filename) {
    SDL_Surface* spriteSurface = IMG_Load(filename);
    SDL_Texture* texture = nullptr;
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
            m_width = spriteSurface->w;
            m_height = spriteSurface->h;
        }
        SDL_FreeSurface(spriteSurface);
    }

    return true;
}

int SDL::TextureManager::getHeight() {
    return m_height;
}

int SDL::TextureManager::getWidth() {
    return m_width;
}

void SDL::TextureManager::renderTexture(double xPos, double yPos, double width, double height, SDL_Rect *sourceRect) {
    SDL_Rect destRect = {static_cast<int>(xPos),static_cast<int>(yPos),static_cast<int>(width),static_cast<int>(height)};
    SDL_RenderCopy(m_renderer,m_texture,sourceRect,&destRect);
}
