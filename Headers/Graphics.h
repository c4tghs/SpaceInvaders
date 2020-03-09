//
// Created by cliff on 08/03/2020.
//

#ifndef PROJECT_GRAPHICS_H
#define PROJECT_GRAPHICS_H

using namespace std;


#include <string>
#include "SDL.h"
#include "SDL_image.h"

class Graphics {
public:
    Graphics();
    ~Graphics();
    void createWindow(const char* title,int width, int height);
    void createRender();
    SDL_Renderer* getRenderer();
    bool initialise();
    void Clean();
    void Update();
    void Render();
    void Events();
    void Quit();
    bool getRunningState();
    void playerDirection(string key);

private:
    int m_count = 0;
    bool m_rightDirection = true;
    bool m_IsRunning;
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;

    const int SCREEN_WIDTH = 960;
    const int SCREEN_HEIGHT = 640;
};


#endif //PROJECT_GRAPHICS_H
