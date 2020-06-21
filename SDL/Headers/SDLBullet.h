#ifndef SPACEINVADERS_SDLBULLET_H
#define SPACEINVADERS_SDLBULLET_H

#include "../../Models/Headers/Bullet.h"
#include "../../Models/Headers/Window.h"

namespace SDL
{
    class SDLBullet: public Abstract::Bullet {
    public:
        SDLBullet(double xPos, double yPos, double width, double height, Abstract::Window *window, Bullet_type type);
        ~SDLBullet();
        void render();
        Sprite getSpriteType();

    private:
        Abstract::Window* m_window = nullptr;
        Bullet_type m_bulletType;
    };

}


#endif //SPACEINVADERS_SDLBULLET_H
