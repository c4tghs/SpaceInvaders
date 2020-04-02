#pragma once
//
// Created by cliff on 08/03/2020.
//

#include <SDL_render.h>
#include <string>
namespace GameNs
{
    class TextureManager {
    public:

        TextureManager();
        ~TextureManager();
        TextureManager(SDL_Renderer *renderer);
        SDL_Texture* getTexture();
        void LoadTexture(std::string filename, SDL_Renderer *ren);
        void free();

    private:
        SDL_Renderer* m_renderer;
        SDL_Texture* m_texture;
        int m_width;
        int m_height;
    };
}

