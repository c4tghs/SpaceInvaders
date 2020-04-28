#pragma once
//
// Created by cliff on 08/03/2020.
//

#include <SDL2/SDL_render.h>
#include <string>
namespace GameNs
{
    class TextureManager {
    public:

        TextureManager();
        TextureManager(SDL_Renderer* renderer);
        ~TextureManager();
        SDL_Texture* getTexture();
        void loadTexture(const char* filename);
        int getWidth();
        int getHeight();

    private:
        int m_width;
        int m_height;
        SDL_Renderer* m_renderer= nullptr;
        SDL_Texture* m_texture= nullptr;
    };
}

