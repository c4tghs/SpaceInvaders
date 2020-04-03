/**
 * CPP for TextureManager class
 */
#include <SDL_image.h>
#include "../Headers/TextureManager.h"

/**
 * Constructor
 */
GameNs::TextureManager::TextureManager(){

}
/**
 * Destructor
 */
GameNs::TextureManager::~TextureManager() {
    free();
}
/**
 * Constructor
 * @param renderer
 */
GameNs::TextureManager::TextureManager(SDL_Renderer *renderer){
    m_renderer = renderer;
}
/**
 * Method to create a texture from image
 * @param filename - path to image
 * @param ren - renderer
 */
void GameNs::TextureManager::LoadTexture(std::string filename, SDL_Renderer *ren) {
    SDL_Surface* surface = IMG_Load(filename.c_str());
    SDL_Texture* tex;
    if(surface == NULL)
    {
        SDL_Log("Failed to create surface: %s",SDL_GetError());
        printf("Failed to load surface: %s",SDL_GetError());
        exit(1);
    }
    else
    {
        //color image for transparency
        SDL_SetColorKey(surface,SDL_TRUE, SDL_MapRGB(surface->format,0,0,0));

        //Create texture from surface pixels
        tex = SDL_CreateTextureFromSurface(ren, surface);
        if(tex == NULL)
        {
            SDL_Log("Failed to create texture: %s",SDL_GetError());
            printf("Failed to create texture: %s",SDL_GetError());
            exit(1);
        }

        //remove old loaded surface
        SDL_FreeSurface(surface);
    }
    m_texture = tex;

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
    if(m_texture != NULL)
    {
        SDL_DestroyTexture(m_texture);
    }
}

