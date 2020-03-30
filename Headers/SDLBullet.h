//
// Created by cliff on 23/03/2020.
//

#ifndef PROJECT_SDLBULLET_H
#define PROJECT_SDLBULLET_H


#include "Bullet.h"
#include "TextureManager.h"

class SDLBullet: public Bullet {
public:
    SDLBullet();
    void fire();
    void reload();
    void render();

private:
    const int m_offScreenBuffer = 10;
    float m_speed;
    TextureManager* m_texture;
};


#endif //PROJECT_SDLBULLET_H
