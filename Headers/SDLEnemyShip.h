//
// Created by cliff on 12/03/2020.
//

#ifndef PROJECT_SDLENEMYSHIP_H
#define PROJECT_SDLENEMYSHIP_H

using namespace std;
#include <SDL_render.h>
#include "SDLTimer.h"
#include <string>
#include "EnemyShip.h"
#include "TextureManager.h"

class SDLEnemyShip: public EnemyShip {
public:
    SDLEnemyShip(SDL_Renderer *renderer,int screenHeight,int screenWidth,string enemyShipPath, int xPos, int yPos);
    int getXPosition();
    int getYPosition();
    void setXPosition(int x);
    void setYPosition(int y);
    void render();
    void close();

private:
    void loadMedia();
    void moveEnemyShip();
    SDL_Renderer* m_renderer;
    string m_enemyShipPath;
    int m_xPos;
    int m_yPos;
    int m_screenHeight;
    int m_screenWidth;
    int m_shipHeight;
    int m_shipWidth;
    TextureManager *m_enemyShipTexture;
};


#endif //PROJECT_SDLENEMYSHIP_H
