//
// Created by cliff on 08/03/2020.
//
#include <SDL_image.h>
#include "../Headers/TextureManager.h"

GameNs::TextureManager::TextureManager(){

}
GameNs::TextureManager::~TextureManager() {
    free();
}
GameNs::TextureManager::TextureManager(SDL_Renderer *renderer){
    m_renderer = renderer;
}
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
        else
        {
            m_width = surface->w;
            m_height = surface->h;
        }
        //remove old loaded surface
        SDL_FreeSurface(surface);
    }
    m_texture = tex;

}
SDL_Texture* GameNs::TextureManager::getTexture(){
    return m_texture;
}

void GameNs::TextureManager::free() {
    if(m_texture != NULL)
    {
        SDL_DestroyTexture(m_texture);
    }
}

