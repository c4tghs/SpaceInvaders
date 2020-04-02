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
        SDLBullet(SDL_Renderer *renderer,std::string bulletPath, int xPos, int yPos);
        void render();
        void loadMedia();
        void close();
        int getXPosition();
        int getYPosition();
        void setXPosition(int x);
        void setYPosition(int y);

    private:
        GameNs::TextureManager* m_texture;
        SDL_Renderer* m_renderer;
        std::string m_bulletPath;
        int m_xPos;
        int m_yPos;
        int m_width;
        int m_height;
    };
}



#endif //PROJECT_SDLBULLET_H
