/**
 * Class to create texts
 */
#ifndef PROJECT_TEXTMANAGER_H
#define PROJECT_TEXTMANAGER_H

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_ttf.h>
#include <string>

namespace GameNs{
    class TextManager {
    public:
        TextManager();
        TextManager(SDL_Renderer* renderer);
        SDL_Texture* getTexture();
        void loadTexture(std::string text);
        void free();

    private:
        SDL_Renderer* m_renderer;
        SDL_Texture* m_texture =NULL;
        TTF_Font *m_font;
        const char *m_fontFile = "../assets/Fonts/Lato-Regular.ttf";
    };
}



#endif //PROJECT_TEXTMANAGER_H
