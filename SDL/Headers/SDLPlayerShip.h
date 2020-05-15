#ifndef SPACEINVADERS_SDLPLAYERSHIP_H
#define SPACEINVADERS_SDLPLAYERSHIP_H

#include <SDL2/SDL_render.h>
#include "../../Models/Headers/PlayerShip.h"
#include "../../Models/Headers/TextureManager.h"
#include "../../Models/Headers/Window.h"

namespace SDL
{
    class SDLPlayerShip: public Abstract::PlayerShip {
    public:
        SDLPlayerShip(double xPos, double yPos, double width, double height, Abstract::Window *window);
        ~SDLPlayerShip();
        void render() override ;
    private:
        Abstract::Window* m_window;
        SDL_Renderer* m_renderer;
        TextureManager* textureManager;
        SDL_Texture* m_playerTexture;
    };
}



#endif //SPACEINVADERS_SDLPLAYERSHIP_H
