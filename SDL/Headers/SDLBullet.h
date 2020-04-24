//
// Created by cliff on 23/03/2020.
//

#ifndef PROJECT_SDLBULLET_H
#define PROJECT_SDLBULLET_H


#include "../../Models/Headers/Bullet.h"
#include "../../Controllers/Headers/TextureManager.h"
#include "SDLTimer.h"

namespace SDLNs
{
    class SDLBullet: public GameNs::Bullet {
    public:
        SDLBullet(SDL_Renderer* renderer,std::string bulletPath, int xPos, int yPos, int width, int height);
        ~SDLBullet();
        void render();
        void loadMedia();


    private:
        GameNs::TextureManager* m_texture = nullptr;
        SDL_Renderer* m_renderer= nullptr;
        std::string m_bulletPath;
    };
}



#endif //PROJECT_SDLBULLET_H
