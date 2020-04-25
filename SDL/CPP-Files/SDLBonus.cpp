
#include <iostream>
#include <utility>
#include "../Headers/SDLBonus.h"

/**
 * Constructor
 */
SDLNs::SDLBonus::SDLBonus() {}

/**
 * Constructor
 * @param renderer
 */
SDLNs::SDLBonus::SDLBonus(SDL_Renderer* renderer, int xPos, int yPos, int width, int height, std::string imagePath)
{
    m_renderer = renderer;
    m_bonusTexture = new GameNs::TextureManager(m_renderer);
    setXPosition(xPos);
    setYPosition(yPos);
    setHeight(height);
    setWidth(width);
    m_bonusImagePath = std::move(imagePath);

    //create texture
    loadMedia();
}

/**
 * Destructor
 */
SDLNs::SDLBonus::~SDLBonus() {
    delete m_bonusTexture;
}

/**
 * Method to render the bonus
 */
void SDLNs::SDLBonus::render()
{
    //Create rectangular area
    SDL_Rect rect = {getXPosition(),getYPosition(),getWidth(),getHeight()};
    SDL_RenderCopy(m_renderer,m_bonusTexture->getTexture(), nullptr,&rect);
}

/**
 * Method to create bonus texture
 */
void SDLNs::SDLBonus::loadMedia()
{
    m_bonusTexture->loadTexture(m_bonusImagePath);
    if(m_bonusTexture->getTexture() == nullptr){
        std::cout << "Something went wrong loading texture: "<< SDL_GetError()<< std::endl;
        exit(1);
    }
}


