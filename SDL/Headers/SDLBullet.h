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
        SDLBullet(SDL_Renderer *renderer,std::string bulletPath);
        void fire();
        void reload();
        void render();
        void loadMedia();

    private:
        const int m_offScreenBuffer = 10;
        float m_speed;
        GameNs::TextureManager* m_texture;
        SDLTimer* m_timer;
        SDL_Renderer* m_renderer;
        std::string m_bulletPath;
    };
}



#endif //PROJECT_SDLBULLET_H
