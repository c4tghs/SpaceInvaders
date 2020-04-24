//
// Created by cliff on 12/03/2020.
//

#ifndef PROJECT_SDLENEMYSHIP_H
#define PROJECT_SDLENEMYSHIP_H

#include <SDL_render.h>
#include "SDLTimer.h"
#include "../../Models/Headers/EnemyShip.h"
#include "../../Controllers/Headers/TextureManager.h"
#define SPRITES_FRAMES 2
namespace SDLNs
{
    class SDLEnemyShip: public GameNs::EnemyShip {
    public:
        SDLEnemyShip(SDL_Renderer *renderer, GameNs::Timer *timer, std::string enemyShipPath, int xPos, int yPos,
                     int width, int height);
        void render();
        void close();
        void setRect(SDL_Rect rects[]);
        int getMoveDirection();
        void setMoveDirection(int direction);
        void loadMedia();

    private:
        SDL_Rect m_rects[SPRITES_FRAMES];
        SDL_Renderer* m_renderer = nullptr;
        std::string m_enemyShipPath;
        int m_moveDirection=1;
        GameNs::TextureManager* m_enemyShipTexture = nullptr;
        GameNs::Timer* m_timer= nullptr;
    };
}



#endif //PROJECT_SDLENEMYSHIP_H
