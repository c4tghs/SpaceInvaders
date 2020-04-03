/**
 * CPP file for SDLBullet class
 */

#include "../Headers/SDLBullet.h"
/**
 * Constructor for SDLBullet class
 * @param renderer
 * @param bulletPath - path to bullet image
 * @param xPos - x position of bullet
 * @param yPos - y position of bullet
 * @param width - width of bullet
 * @param height - height of bullet
 */
SDLNs::SDLBullet::SDLBullet(SDL_Renderer *renderer,std::string bulletPath,int xPos, int yPos,int width, int height):GameNs::Bullet(xPos,yPos,width,height)
{
    m_renderer = renderer;
    m_bulletPath = bulletPath;
    GameNs::TextureManager *bulletTexture = new GameNs::TextureManager(m_renderer);
    m_texture  = bulletTexture;
    loadMedia();
}
/**
 * Method to render bullet
 */
void SDLNs::SDLBullet::render() {
    SDL_Rect rQuad = {getXPosition(),getYPosition(),getWidth(),getHeight()};
    SDL_RenderCopy(m_renderer,m_texture->getTexture(),NULL,&rQuad);

}
/**
 * Method to destroy bullet texture
 */
void SDLNs::SDLBullet::close() {
    m_texture->free();
}

/**
 * Method to create SDL texture for the bullet
 */
void SDLNs::SDLBullet::loadMedia() {
    m_texture->LoadTexture(m_bulletPath,m_renderer);
    if(m_texture->getTexture() == NULL)
    {
        printf("Something went wrong loading texture %s",SDL_GetError());
    }
}