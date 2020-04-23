//
// Created by cliff on 14/03/2020.
//

#ifndef PROJECT_SDLBACKGROUND_H
#define PROJECT_SDLBACKGROUND_H

#include <SDL2/SDL.h>
//#include <SDL2/SDL_render.h>
#include "../../Controllers/Headers/TextureManager.h"
#include "../../Models/Headers/Background.h"

namespace SDLNs
{
    class SDLBackground:public GameNs::Background {
    public:
        SDLBackground(SDL_Renderer* renderer);
        void render();
        void close();

    private:
        int frame=0;
        SDL_Renderer* m_renderer= nullptr;
        GameNs::TextureManager* m_textureManager= nullptr;
        std::string sprite = "../assets/invader_sprites.png";
    };

}


#endif //PROJECT_SDLBACKGROUND_H
