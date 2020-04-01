//
// Created by cliff on 23/03/2020.
//

#ifndef PROJECT_SDLBULLET_H
#define PROJECT_SDLBULLET_H


#include "Bullet.h"
#include "TextureManager.h"
namespace SDLNs
{
    class SDLBullet: public GameNs::Bullet {
    public:
        SDLBullet();
        void fire();
        void reload();
        void render();

    private:
        const int m_offScreenBuffer = 10;
        float m_speed;
        GameNs::TextureManager* m_texture;
    };
}



#endif //PROJECT_SDLBULLET_H
