#pragma once
//
// Created by cliff on 08/03/2020.
//

#include <SDL_render.h>
#include <string>
class TextureManager {
public:

    TextureManager();
    TextureManager(SDL_Renderer *renderer);
    SDL_Texture* getTexture();
    void LoadTexture(std::string filename, SDL_Renderer *ren);
    void render(int x, int y, SDL_Rect* rect, SDL_Point* center, SDL_RendererFlip flip);
    void free();

private:
    SDL_Renderer* m_renderer;
    SDL_Texture* m_texture;

    int m_width;
    int m_height;
};
