/**
 * CPP for TextureManager class
 */
#include <SDL2/SDL_image.h>
#include <iostream>
#include "../Headers/TextureManager.h"

/**
 * Constructor
 */
GameNs::TextureManager::TextureManager(){

}

/**
 * Constructor
 * @param renderer
 */
GameNs::TextureManager::TextureManager(SDL_Renderer* renderer){
    m_renderer = renderer;
}
/**
 * Method to create a texture from image
 * @param filename - path to image
 * @param ren - renderer
 */
void GameNs::TextureManager::LoadTexture(const std::string &filename) {
    SDL_Surface* surface = IMG_Load(filename.c_str());
    SDL_Texture* tex;

    //Check if surface was created successfully.
    if(surface == nullptr)
    {
        std::cerr << "Failed to load surface. Error: " << SDL_GetError() << std::endl;
        exit(1);
    }
    else
    {
        //Color image for transparency
        SDL_SetColorKey(surface,SDL_TRUE, SDL_MapRGB(surface->format,0,0,0));

        //Create texture from surface pixels
        tex = SDL_CreateTextureFromSurface(m_renderer, surface);

        //Check if texture was created successfully.
        if(tex == nullptr)
        {
            std::cerr << "Failed to create texture. Error: " << SDL_GetError() << std::endl;
            exit(1);
        } else
        {
            m_texture = tex;
            m_width = surface->w;
            m_height = surface->h;
        }

        //Free surface
        SDL_FreeSurface(surface);
    }


}
/**
 * Method that returns created texture
 * @return - texture
 */
SDL_Texture* GameNs::TextureManager::getTexture(){
    return m_texture;
}

/**
 * Method to destroy texture
 */
void GameNs::TextureManager::free() {
    if(m_texture != nullptr)
    {
        SDL_DestroyTexture(m_texture);
        m_texture = nullptr;
    }
}

int GameNs::TextureManager::getWidth() {
    return m_width;
}

int GameNs::TextureManager::getHeight() {
    return m_height;
}


