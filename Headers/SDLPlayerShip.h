//
// Created by cliff on 12/03/2020.
//

#ifndef PROJECT_SDLPLAYERSHIP_H
#define PROJECT_SDLPLAYERSHIP_H


#include <SDL_render.h>
#include "PlayerShip.h"
#include "SDLKeyStates.h"
#include "TextureManager.h"

class SDLPlayerShip: public PlayerShip {
public:
    SDLPlayerShip(SDL_Renderer *renderer,int screenHeight,int screenWidth,std::string playerShipPath);
    int getXPosition();
    int getYPosition();
    void setXPosition(int x);
    void setYPosition(int y);
    void render();
    void close();
    bool hitBoundary();
    int getMoveDirection();
    void setMoveDirection(int direction);

private:
    void loadMedia();
    void movePlayerShip();
    TextureManager *m_playerShipTexture;
    int m_xPos;
    int m_yPos;
    SDL_Renderer* m_renderer;
    std::string m_playerShipPath;
    int m_screenHeight;
    int m_screenWidth;
    int m_shipHeight;
    int m_shipWidth;
    SDLKeyStates* m_keyStates;

};


#endif //PROJECT_SDLPLAYERSHIP_H
