#pragma once
#ifndef SPACEINVADERS_SDLWINDOW_H
#define SPACEINVADERS_SDLWINDOW_H
#include "../../Enums.h"
#include "../../Models/Headers/Window.h"
#include "../../Models/Headers/TextureManager.h"
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
        int getWindowWidth();
        int getWindowHeight();
        void drawRect(SPRITE sprite, double xPos, double yPos, double width, double height);
        void refresh();
        void playSound(SOUND_TYPE sound);

    private:
        const char* m_title;
        int m_windowWidth;
        int m_windowHeight;
        SDL_Window* m_window = nullptr;
        SDL_Renderer* m_renderer= nullptr;
        TTF_Font* m_font= nullptr;
        TextureManager* m_textureManager;
        SDL_Texture* m_background = nullptr;
        std::map<SPRITE,SDL_Rect> m_sprites;
        std::map<SOUND_TYPE,Mix_Chunk*> sounds;
    };
}



#endif //SPACEINVADERS_SDLWINDOW_H
