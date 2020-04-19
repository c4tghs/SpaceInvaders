//
// Created by cliff on 12/03/2020.
//

#ifndef PROJECT_SDLPLAYERSHIP_H
#define PROJECT_SDLPLAYERSHIP_H


#include <SDL2/SDL_render.h>
#include "../../Models/Headers/PlayerShip.h"
#include "SDLKeyStates.h"
#include "../../Controllers/Headers/TextureManager.h"
#include "SDLTimer.h"

namespace SDLNs
{
    class SDLPlayerShip: public GameNs::PlayerShip {
    public:
        SDLPlayerShip(int xPos, int yPos, int width, int height,SDL_Renderer* renderer,std::string playerShipPath);
        void render();
        void close();
        void loadMedia();

    private:

        GameNs::TextureManager *m_playerShipTexture= nullptr;
        SDL_Renderer* m_renderer= nullptr;
        std::string m_playerShipPath;


    };
}



#endif //PROJECT_SDLPLAYERSHIP_H
