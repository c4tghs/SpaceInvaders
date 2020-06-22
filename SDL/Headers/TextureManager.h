#ifndef SPACEINVADERS_TEXTUREMANAGER_H
#define SPACEINVADERS_TEXTUREMANAGER_H

#include <SDL2/SDL_render.h>

namespace SDL
{
    class TextureManager {
    public:
        TextureManager(SDL_Renderer* renderer);
        ~TextureManager();
        bool loadTexture(const char *filename, bool transparent);
        void renderTexture(double xPos, double yPos,double width, double height, SDL_Rect* sourceRect);

    private:
        SDL_Texture* m_texture= nullptr;
        SDL_Renderer* m_renderer= nullptr;

    };
}



#endif //SPACEINVADERS_TEXTUREMANAGER_H
