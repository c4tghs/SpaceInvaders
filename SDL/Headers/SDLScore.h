//
// Created by cliff on 05/04/2020.
//

#ifndef PROJECT_SDLSCORE_H
#define PROJECT_SDLSCORE_H

#include "../../Models/Headers/Score.h"
#include "../../Controllers/Headers/TextManager.h"
#include <SDL2/SDL_render.h>
namespace SDLNs
{
    class SDLScore: public GameNs::Score {
        public:
            SDLScore(SDL_Renderer *renderer);
            void render();
            void close();

        private:
            SDL_Renderer* m_renderer;
            GameNs::TextManager* m_textTexture;

    };
}



#endif //PROJECT_SDLSCORE_H
