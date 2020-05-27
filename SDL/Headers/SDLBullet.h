#ifndef SPACEINVADERS_SDLBULLET_H
#define SPACEINVADERS_SDLBULLET_H

#include "../../Models/Headers/Bullet.h"
#include "../../Models/Headers/Window.h"

namespace SDL
{
    class SDLBullet: public Abstract::Bullet {
    public:
        SDLBullet(double xPos, double yPos, double width, double height, Abstract::Window *window, BULLET_TYPE type);
        ~SDLBullet();
        void render();
        SPRITE getSpriteType();

    private:
        Abstract::Window* m_window = nullptr;
        BULLET_TYPE m_bulletType;
    };

}


#endif //SPACEINVADERS_SDLBULLET_H
