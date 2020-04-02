//
// Created by cliff on 23/03/2020.
//

#include "../Headers/SDLBullet.h"
SDLNs::SDLBullet::SDLBullet(SDL_Renderer *renderer,std::string bulletPath,int xPos, int yPos)
{
    m_renderer = renderer;
    m_bulletPath = bulletPath;
    GameNs::TextureManager *bulletTexture = new GameNs::TextureManager(m_renderer);
    m_texture  = bulletTexture;
    m_xPos = xPos;
    m_yPos = yPos;
    loadMedia();
}
void SDLNs::SDLBullet::render() {
    SDL_Rect rQuad = {m_xPos,m_yPos,10,10};
    SDL_RenderCopy(m_renderer,m_texture->getTexture(),NULL,&rQuad);

}
void SDLNs::SDLBullet::close() {
    m_texture->free();
}

int SDLNs::SDLBullet::getXPosition() {
    return m_xPos;
}
int SDLNs::SDLBullet::getYPosition() {
    return m_yPos;
}
void SDLNs::SDLBullet::setXPosition(int x) {
     m_xPos = x;
}
void SDLNs::SDLBullet::setYPosition(int y) {
     m_yPos = y;
}

void SDLNs::SDLBullet::loadMedia() {
    m_texture->LoadTexture(m_bulletPath,m_renderer);
    if(m_texture->getTexture() == NULL)
    {
        printf("Something went wrong loading texture %s",SDL_GetError());
    }
}