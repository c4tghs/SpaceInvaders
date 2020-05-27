#ifndef SPACEINVADERS_TEXTMANAGER_H
#define SPACEINVADERS_TEXTMANAGER_H

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_ttf.h>

namespace SDL
{
    class TextManager {
        public:
            TextManager(SDL_Renderer* renderer);
            ~TextManager();
            bool loadTextTexture(TTF_Font *font, const std::string& text, SDL_Color color);
            void renderText(int xPos, int yPos);
            int getSurfaceWidth();
        private:
            SDL_Renderer* m_renderer = nullptr;
            SDL_Texture* m_texture= nullptr;
            int m_width=0;
            int m_height=0;
    };
}



#endif //SPACEINVADERS_TEXTMANAGER_H
