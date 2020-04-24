//
// Created by cliff on 09/04/2020.
//

#ifndef PROJECT_SDLPLAYERLIFE_H
#define PROJECT_SDLPLAYERLIFE_H

#include "../../Models/Headers/PlayerLife.h"
#include "../../Controllers/Headers/TextManager.h"

namespace SDLNs{
class SDLPlayerLife:public GameNs::PlayerLife {
    public:
        SDLPlayerLife();
        SDLPlayerLife(SDL_Renderer* renderer, int screenWidth);
        ~SDLPlayerLife();
        void render();

    private:
        GameNs::TextManager* m_textTexture = nullptr;
        SDL_Renderer* m_renderer = nullptr;
        int m_screenWidth = 0;
    };
}



#endif //PROJECT_SDLPLAYERLIFE_H
