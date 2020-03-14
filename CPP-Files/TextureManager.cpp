//
// Created by cliff on 08/03/2020.
//
#include <SDL_image.h>
#include "../Headers/TextureManager.h"

TextureManager::TextureManager(){

}
TextureManager::TextureManager(SDL_Renderer *renderer){
    m_renderer = renderer;
}
void TextureManager::LoadTexture(std::string filename, SDL_Renderer *ren) {
    SDL_Surface* surface = IMG_Load(filename.c_str());
    if(surface == NULL)
    {
        SDL_Log("Failed to load image: %s",SDL_GetError());
    }
    else
    {
        //Create texture from surface pixels
        SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, surface);
        if(tex == NULL)
        {
            SDL_Log("Failed to create texture: %s",SDL_GetError());
        }
        else
        {
            //remove old loaded surface
            m_width = surface->w;
            m_height = surface->h;
            m_texture = tex;
        }
        SDL_FreeSurface(surface);

    }

}
SDL_Texture* TextureManager::getTexture(){
    return m_texture;
}
void TextureManager::render(int x, int y, SDL_Rect* rect, SDL_Point* center, SDL_RendererFlip flip) {

}
void TextureManager::free() {
    if(m_texture != NULL)
    {
        SDL_DestroyTexture(m_texture);
    }
}
