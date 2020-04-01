//
// Created by cliff on 14/03/2020.
//

#ifndef PROJECT_SDLBACKGROUND_H
#define PROJECT_SDLBACKGROUND_H


#include <SDL2/SDL_render.h>
#include "TextureManager.h"
#include "Background.h"

namespace SDLNs
{
    class SDLBackground:public GameNs::Background {
    public:
        SDLBackground(SDL_Renderer* renderer, int screenWidth, int screenHeight);
        void render();
        void close();

    private:
        SDL_Renderer* m_renderer;
        SDL_Texture* m_texture;
        GameNs::TextureManager* m_backgroundTexture;

        int m_screenWidth;
        int m_screenHeight;
    };

}


#endif //PROJECT_SDLBACKGROUND_H
