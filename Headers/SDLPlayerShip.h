//
// Created by cliff on 12/03/2020.
//

#ifndef PROJECT_SDLPLAYERSHIP_H
#define PROJECT_SDLPLAYERSHIP_H

using namespace std;
#include <SDL_render.h>
#include <string>
#include "PlayerShip.h"
#include "SDLKeyStates.h"
#include "TextureManager.h"

class SDLPlayerShip: public PlayerShip {
public:
    SDLPlayerShip(SDL_Renderer *renderer,int screenHeight,int screenWidth,string playerShipPath);
    int getXPosition();
    int getYPosition();
    void render();
    void close();

private:
    void loadMedia();
    void movePlayerShip();
    TextureManager *m_playerShipTexture;
    int m_xPos;
    int m_yPos;
    SDL_Renderer* m_renderer;
    basic_string<char> m_playerShipPath;
    int m_screenHeight;
    int m_screenWidth;
    SDLKeyStates* m_keyStates;

};


#endif //PROJECT_SDLPLAYERSHIP_H
