//
// Created by cliff on 12/03/2020.
//

#ifndef PROJECT_SDLENEMYSHIP_H
#define PROJECT_SDLENEMYSHIP_H

#include <SDL_render.h>
#include "SDLTimer.h"
#include "../../Models/Headers/EnemyShip.h"
#include "../../Controllers/Headers/TextureManager.h"

namespace SDLNs
{
    class SDLEnemyShip: public GameNs::EnemyShip {
    public:
        SDLEnemyShip(SDL_Renderer *renderer, std::string enemyShipPath, int xPos,int yPos,int width, int height);
        void render();
        void close();
        int getMoveDirection();
        void setMoveDirection(int direction);

    private:
        void loadMedia();
        SDL_Rect m_rect;
        SDL_Renderer* m_renderer;
        std::string m_enemyShipPath;
        int m_moveDirection;
        GameNs::TextureManager *m_enemyShipTexture;
    };
}



#endif //PROJECT_SDLENEMYSHIP_H
