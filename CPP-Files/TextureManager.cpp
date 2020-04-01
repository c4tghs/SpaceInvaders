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
        SDL_Log("Failed to load image: %s",SDL_GetError());
        printf("Failed to load image: %s",SDL_GetError());
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
}/*
void TextureManager::render(int x, int y, SDL_Rect* rect, SDL_Point* center, SDL_RendererFlip flip) {
    SDL_Rect render = {x,y};
    if(rect != NULL)
    {
        render.w = rect->w;
        render.h = rect->h;
    }
    SDL_RenderCopyEx(m_renderer,m_texture,rect,&render,NULL,center,flip);
}*/
void GameNs::TextureManager::free() {
    if(m_texture != NULL)
    {
        SDL_DestroyTexture(m_texture);
    }
}

