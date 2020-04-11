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
        TextureManager(SDL_Renderer *renderer);
        SDL_Texture* getTexture();
        void LoadTexture(const std::string& filename, SDL_Renderer *ren);
        void free();

    private:
        SDL_Renderer* m_renderer= nullptr;
        SDL_Texture* m_texture= nullptr;
    };
}

