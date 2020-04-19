
#ifndef PROJECT_SDLBONUS_H
#define PROJECT_SDLBONUS_H

#include <SDL2/SDL_render.h>
#include "../../Models/Headers/Bonus.h"
#include "../../Controllers/Headers/TextureManager.h"

namespace SDLNs{
    class SDLBonus: public GameNs::Bonus {
        public:
            SDLBonus();
            SDLBonus(SDL_Renderer* renderer, int xPos, int yPos, int width, int height, std::string imagePath);
            void render();
            void close();
            void loadMedia();

        private:
            SDL_Renderer* m_renderer= nullptr;
            GameNs::TextureManager* m_bonusTexture= nullptr;
            std::string m_bonusImagePath;
    };
}



#endif //PROJECT_SDLBONUS_H
