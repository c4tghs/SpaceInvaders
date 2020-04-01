//
// Created by cliff on 23/03/2020.
//

#include "../Headers/SDLBullet.h"
SDLNs::SDLBullet::SDLBullet(SDL_Renderer *renderer,std::string bulletPath)
{
    m_renderer = renderer;
    m_bulletPath = bulletPath;
    GameNs::TextureManager *bulletTexture = new GameNs::TextureManager(m_renderer);
    m_texture  =bulletTexture;
    m_timer = new SDLTimer();
    loadMedia();
}
void SDLNs::SDLBullet::render() {

}
void SDLNs::SDLBullet::fire() {

}
void SDLNs::SDLBullet::reload() {

}
void SDLNs::SDLBullet::loadMedia() {
    m_texture->LoadTexture(m_bulletPath,m_renderer);
    if(m_texture->getTexture() == NULL)
    {
        printf("Something went wrong loading texture %s",SDL_GetError());
    }
}