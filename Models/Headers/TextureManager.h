#ifndef SPACEINVADERS_TEXTUREMANAGER_H
#define SPACEINVADERS_TEXTUREMANAGER_H

#include <SDL2/SDL_render.h>
#include <SDL_render.h>

namespace SDL
{
    class TextureManager {
    public:
        TextureManager(SDL_Renderer* renderer);
        ~TextureManager();
        bool loadTexture(const char *filename);

        void renderTexture(double xPos, double yPos,double width, double height, SDL_Rect* sourceRect);
        int getHeight();
        int getWidth();
    private:
        SDL_Texture* m_texture= nullptr;
        SDL_Renderer* m_renderer= nullptr;
        int m_height;
        int m_width;

    };
}



#endif //SPACEINVADERS_TEXTUREMANAGER_H
