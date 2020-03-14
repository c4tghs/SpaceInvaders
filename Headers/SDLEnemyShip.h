//
// Created by cliff on 12/03/2020.
//

#ifndef PROJECT_SDLENEMYSHIP_H
#define PROJECT_SDLENEMYSHIP_H

using namespace std;
#include <SDL_render.h>
#include <string>
#include "EnemyShip.h"

class SDLEnemyShip: public EnemyShip {
public:
    SDLEnemyShip(SDL_Renderer *renderer,string enemyShipPath);
    int getXPosition();
    int getYPosition();
    void render();
    void close();

private:
    SDL_Renderer* m_renderer;
    string m_enemyShipPath;
    int m_xPos;
    int m_yPos;
};


#endif //PROJECT_SDLENEMYSHIP_H
