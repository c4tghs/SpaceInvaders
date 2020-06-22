#ifndef SPACEINVADERS_SDLWINDOW_H
#define SPACEINVADERS_SDLWINDOW_H
#include "../../Constants.h"
#include "../../Models/Headers/Window.h"
#include "TextureManager.h"
#include "TextManager.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <map>

namespace SDL
{
    class SDLWindow: public Abstract::Window {
    public:
        SDLWindow(const char* title, int screenWidth, int screenHeight);
        ~SDLWindow();
        bool initialise();
        void render();
        bool loadMedia();
        void drawRect(SPRITE sprite, double xPos, double yPos, double width, double height);
        void refresh();
        void playSound(SOUND_TYPE sound);
        void exit(const char* message);
        void showScore(int score);
        void showLives(int lives);
        void showLevel(int level);
        void showEndScore(int score);

    private:
        const char* m_title;
        int m_windowWidth;
        int m_windowHeight;
        SDL_Window* m_window = nullptr;
        SDL_Renderer* m_renderer= nullptr;
        TTF_Font* m_font= nullptr;
        TTF_Font* m_fontEndScore= nullptr;
        TextureManager* m_textureManager;
        TextureManager* m_bonusLivesTexture;
        TextManager* m_playerScore;
        TextManager* m_playerLives;
        TextManager* m_level;
        TextManager* m_endScore;
        SDL_Texture* m_background = nullptr;
        std::map<SPRITE,SDL_Rect> m_sprites;
        std::map<SOUND_TYPE,Mix_Chunk*> m_sounds;
    };
}



#endif //SPACEINVADERS_SDLWINDOW_H
